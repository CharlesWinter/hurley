#include <SDL2/SDL.h>
#include <stdio.h>

#define NUM_COLS 10
#define NUM_ROWS 10

void renderGrid(SDL_Renderer *renderer, SDL_Window *window) {
  SDL_SetRenderDrawColor(renderer, 0,0,0,0);

  int wHeight, wWidth;
  SDL_GetWindowSize(window, &wWidth, &wHeight);

  int rowHeight = wHeight / NUM_ROWS;

  // draw  the lines in black.

  for (int rowNum = 1; rowNum < NUM_ROWS; rowNum++) {
    int rowY = rowNum * rowHeight;
    if (SDL_RenderDrawLine(renderer, 0, rowY, wWidth, rowY) < 0) {
      printf("had a nightmare with the drawline %s\n", SDL_GetError());
    }
  }

  double colWidth = wWidth / NUM_COLS;
  for (int colNum = 1; colNum < NUM_ROWS; colNum++) {
    int colX = colNum * colWidth;
    if (SDL_RenderDrawLine(renderer, colX, 0, colX, wHeight) < 0) {
      printf("had a nightmare with the drawline %s\n", SDL_GetError());
    }
  }

}
