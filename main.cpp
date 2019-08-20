#include "Game.h"
int main(int argc, char **argv){
	bool quit{ false };
	Game game(210, 210, 6, 6, '*', '-');
	game.inputFromFile("input.txt");
	if (!game.initalizeDisplay()) {
		std::cout << "init fail" << '\n';
		return 1;
	}
	//
	
		
	
	SDL_Event event;
	int i{ 0 };
	while (!quit || i < 5) {
		game.displayLive();
		game.nextGeneration();

		SDL_WaitEvent(&event);
		switch (event.type) {
		case SDL_QUIT:
			quit = true;
			break;
		}
		++i;
	}
	game.outputInFile("w.txt");
	/*	game.nextGeneration();
		game.displayLive();
	}
	SDL_Event event;
	while (!quit) {
		while (SDL_PollEvent(&event)) {
			if (event.type = SDL_QUIT) {
				quit = true;
			}
		}
		
		game.nextGeneration();
	}*/
	return 0;
}
/*
#include <iostream>
#include <SDL.h>
int main(int argc, char**argv) {
	int width = 400;
	int height = 400;
	int cellWidth = 20;
	int cellHeight = 20;
	int *field = new int[(width/cellWidth) * (height/cellHeight)];
	bool quit = false;
	for (int i = 0; i < (width / cellWidth) * (height / cellHeight); ++i) {
		field[i] = i % 2 == 0;
	}
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window *win = SDL_CreateWindow("W", 200, 200, width, height, SDL_WINDOW_SHOWN);
	SDL_Renderer *r = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	

	SDL_SetRenderDrawColor(r, 255, 255, 255, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(r);

	SDL_SetRenderDrawColor(r, 0, 0, 0, SDL_ALPHA_OPAQUE);

	for (int i = 0; i < (width/cellWidth); ++i) {
		SDL_RenderDrawLine(r,
			0, cellWidth*i,          /* x1, y1 */
	/*	width, cellHeight*i /* x2, y2 */
	/*	);
	}

	/* Draw column lines */
	/*for (int i = 0; i < (height/cellHeight); ++i) {
		SDL_RenderDrawLine(r,
			cellWidth*i, 0,           /* x1, y1 */
	/*		cellHeight*i, height /* x2, y2 */
	/*	);
	}
	
	for (int x = 0; x < (width/cellWidth); ++x) {
		for (int y = 0; y < (height/cellHeight); ++y) {
			std::cout << field[y * (width/cellWidth) + x];
		}
		std::cout << '\n';
	}
	SDL_SetRenderDrawColor(r, 0, 255, 0, 0);
	for (int x = 0; x < (width / cellWidth); ++x) {
		for (int y = 0; y < (height / cellHeight); ++y) {
			if (field[x * (width/cellWidth) + y] == 1) {
				std::cout << 1;
				SDL_Rect rect = { x * cellWidth, y * cellHeight, cellWidth, cellHeight };
				SDL_RenderFillRect(r, &rect);
			}
		}
	}
	SDL_RenderPresent(r);
	SDL_Event event;
	while (!quit) {
		SDL_WaitEvent(&event);
		switch (event.type) {
		case SDL_QUIT:
			quit = true;
			break;
		}
	}
	return 0;
}*/