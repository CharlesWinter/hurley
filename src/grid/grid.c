#include <SDL2/SDL.h>
#include <stdio.h>

#include "grid/definition.h"

#define NUM_COLS 10
#define NUM_ROWS 10

void renderGrid(const void *self);

Grid* Grid__init(SDL_Renderer *renderer, SDL_Window *window) {

  Grid* new_grid = (Grid*) malloc(sizeof(Grid));
  SDL_GetWindowSize(window, &new_grid->wWidth, &new_grid->wHeight);

  new_grid->renderer = renderer;

  new_grid->renderGrid = &renderGrid;

  return new_grid;
}

void renderGrid(const void *self_obj) {
  // as the typedef for grid has no knowledge of its own type as its not created yet,
  // its "methods" can't be passed the type grid. Need to cast it  to a grid ptr to
  // use this style
  Grid *self = ((Grid *)self_obj);

  SDL_SetRenderDrawColor(self->renderer, 0,0,0,0);

  int rowHeight = self->wHeight / NUM_ROWS;

  for (int rowNum = 1; rowNum < NUM_ROWS; rowNum++) {
    int rowY = rowNum * rowHeight;
    if (SDL_RenderDrawLine(self->renderer, 0, rowY, self->wWidth, rowY) < 0) {
      printf("had a nightmare with the drawline %s\n", SDL_GetError());
    }
  }

  double colWidth = self->wWidth / NUM_COLS;
  for (int colNum = 1; colNum < NUM_ROWS; colNum++) {
    int colX = colNum * colWidth;
    if (SDL_RenderDrawLine(self->renderer, colX, 0, colX, self->wHeight) < 0) {
      printf("had a nightmare with the drawline %s\n", SDL_GetError());
    }
  }
}
