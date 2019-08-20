#pragma once
#include <cstring>
#include <SDL.h>
#include <iostream>
#include <fstream>

class Game {
private:
	int width;
	int height;
	int cellWidth;
	int cellHeight;
	int *field;
	int *output;
	char alive;
	char dead;
	SDL_Window *mainWindow;
	SDL_Renderer *renderer;
public:
	Game(int fieldW, int fieldH, int cellW, int cellH, char al, char de) : width{ fieldW }, height{ fieldH }, cellWidth{ cellW }, cellHeight{ cellH }, alive{ al }, dead{de}{
		field = new int[(fieldW / cellW) * (fieldH / cellH)];
		output = new int[(fieldW / cellW) * (fieldH / cellH)];
		memset(field, 0, (fieldW / cellW) * (fieldH / cellH) * sizeof(int));
		memset(output, 0, (fieldW / cellW) * (fieldH / cellH) * sizeof(int));
	}
	bool initalizeDisplay();
	bool close();
	void nextGeneration();
	void displayLive();
	void inputFromFile(const char*);
	void outputInFile(const char*);

};