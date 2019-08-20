#include "Game.h"

void Game::nextGeneration() {
	std::cout << "next ";
	auto cellUpdate = [&](int x, int y) {
		return field[y *(width / cellWidth)  + x];
	};
	for (int i = 0; i < ((width/cellWidth) * (height / cellHeight)); ++i) {
		output[i] = field[i];
	}
	


	for (int x = 1; x < (width /  cellWidth) - 1; ++x) {
		for (int y = 1; y < (height / cellHeight) - 1; ++y) {
			auto numberOfNeighbours = cellUpdate(x - 1, y - 1) + cellUpdate(x, y - 1) + cellUpdate(x + 1, y - 1)
				+ cellUpdate(x - 1, y) + 0 + cellUpdate(x + 1, y)
				+ cellUpdate(x - 1, y + 1) + cellUpdate(x, y + 1) + cellUpdate(x + 1, y + 1);
			cellUpdate(x - 1, y + 1) + cellUpdate(x, y + 1) + cellUpdate(x + 1, y + 1);
			if (cellUpdate(x, y) == 1) field[y * (width / cellWidth) + x] = numberOfNeighbours == 2 || numberOfNeighbours == 3;
			else field[y * (width/cellWidth) + x] = numberOfNeighbours == 3;
		}
	}
}

bool Game::initalizeDisplay() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cout << "SDL init failed" <<' ' << SDL_GetError();
		return false;
	}
	mainWindow = SDL_CreateWindow("Game Of Life", 200, 200, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	 renderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED);
	
	 SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	 SDL_RenderClear(renderer);
	 
	 SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);

	 for (int i = 0; i < width / cellWidth; ++i) {
		 SDL_RenderDrawLine(renderer, 
			 0, cellWidth*i,          /* x1, y1 */
			 width, cellHeight*i /* x2, y2 */
		 );
	 }
	
	 /* Draw column lines */
	 for (int i = 0; i < height / cellHeight; ++i) {
		 SDL_RenderDrawLine(renderer,
			 cellWidth*i, 0,           /* x1, y1 */
			 cellHeight*i, height /* x2, y2 */
		 );
	 }

	 return true;
}

void Game::displayLive() {
	std::cout << "display";
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
	for (int x = 0; x < (width/cellWidth); ++x) {
		for (int y = 0; y < (height / cellHeight); ++y) {
			if (output[y * (width / cellWidth) + x]) {

				//std::cout << "Alive!";
				SDL_Rect rect = { x * cellWidth, y * cellHeight, cellWidth, cellHeight};
				
				SDL_RenderFillRect(renderer, &rect);
			}
		
		}
	}
	SDL_RenderPresent(renderer);
}
bool Game::close() {
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		if (event.type = SDL_QUIT) {
			return true;
		}
	}
	return false;

}
void Game::inputFromFile(const char *filename) {
	std::ifstream in(filename);
	if (!in) {
		std::cout << "unable to open file";
	}
	char ch;
	int i{ 0 };
	int count{ 0 };
	while (in >> std::noskipws >> ch) {
		if (ch == '\n') continue;
		ch == alive ? field[i] = 1, ++count : field[i] = 0;
		++i;
	}
	std::cout << count;

}

void Game::outputInFile(const char *filename) {
		std::ofstream out(filename);

		for (size_t i = 0; i < (width / cellWidth) * (height / cellHeight); ++i) {
			if (i  && i % (width / cellWidth) == 0) out << '\n';
			output[i] ? out << alive : out << dead;
		}
}