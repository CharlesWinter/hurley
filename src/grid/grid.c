#include <SDL2/SDL.h>
#include <stdio.h>

#include "grid/definition.h"
#include "grid/cells.h"

#define NUM_COLS 10
#define NUM_ROWS 10

void renderGrid(const void *self);
void highlightCell(const void *self_obj, SDL_Point clickPos);
void getPotentialPath(const void *self_obj, SDL_Point clickPos, SDL_Point *path);
void fillCells(Cell* cells[NUM_ROWS][NUM_COLS], int rowHeight, int colWidth, SDL_Renderer *renderer);

SDL_Point getTargetCoords(const void *self_obj, SDL_Point);

Grid* Grid__init(SDL_Renderer *renderer, SDL_Window *window) {

  Grid* new_grid = (Grid*) malloc(sizeof(Grid));
  new_grid->renderer = renderer;

  // Set data  for row and column calcs
  SDL_GetWindowSize(window, &new_grid->wWidth, &new_grid->wHeight);
  new_grid->rowHeight = new_grid->wHeight / NUM_ROWS;
  new_grid->colWidth = new_grid->wWidth / NUM_COLS;

  // fill the cells array with Cells
  fillCells(new_grid->cells,new_grid->rowHeight, new_grid->colWidth, renderer);

  // Set struct methods
  new_grid->renderGrid = &renderGrid;
  new_grid->highlightCell = &highlightCell;
  new_grid->getTargetCoords = &getTargetCoords;
  new_grid->getPotentialPath = &getPotentialPath;

  return new_grid;
}

void fillCells(Cell* cells[NUM_ROWS][NUM_COLS], int rowHeight, int colWidth, SDL_Renderer *renderer) {

  enum TerrainType tType = Ground;
  for (int rowNum = 0; rowNum < NUM_ROWS; rowNum++) {
    for (int colNum = 0; colNum < NUM_COLS; colNum++) {
      SDL_Point pos = {
        .x = colNum * colWidth,
        .y = rowNum * rowHeight,
      };
      cells[rowNum][colNum] = Cell__init(tType, pos, rowHeight, colWidth, renderer);
    }
  }
}

void renderGrid(const void *self_obj) {

  // as the typedef for grid has no knowledge of its own type as its not created yet,
  // its "methods" can't be passed the type grid. Need to cast it  to a grid ptr to
  // use this style
  Grid *self = ((Grid *)self_obj);

  for (int rowNum = 0; rowNum < NUM_ROWS; rowNum++) {
    for (int colNum = 0; colNum < NUM_COLS; colNum++) {
      Cell *cell = self->cells[rowNum][colNum];
      self->cells[rowNum][colNum]->render(cell, self->renderer);
    }
  }

  SDL_SetRenderDrawColor(self->renderer, 0,0,0,0);

  for (int rowNum = 1; rowNum < NUM_ROWS; rowNum++) {
    int rowY = rowNum * self->rowHeight;
    if (SDL_RenderDrawLine(self->renderer, 0, rowY, self->wWidth, rowY) < 0) {
      printf("had a nightmare with the drawline %s\n", SDL_GetError());
    }
  }

  for (int colNum = 1; colNum < NUM_ROWS; colNum++) {
    int colX = colNum * self->colWidth;
    if (SDL_RenderDrawLine(self->renderer, colX, 0, colX, self->wHeight) < 0) {
      printf("had a nightmare with the drawline %s\n", SDL_GetError());
    }
  }

}

// highlightCell makes the cell red when hovered over
// TODO: actually highlight the returned cell
void highlightCell(const void *self_obj, SDL_Point clickPos) {
  Grid *self = ((Grid *)self_obj);

  Cell *cell = getMouseCell(self, clickPos);
  if (cell == NULL) {
    printf("gone bad\n");
    return;
  }
}

// getPotentialPaths fills an array of the players potential paths
void getPotentialPath(const void *self_obj, SDL_Point clickPos, SDL_Point *path) {

  // TODO: don't hardcode this
  // int pathLength = sizeof(path);
  int pathLength = 4;
  printf("path len is %d\n", pathLength);

}

// returns the coordinates to move the target to on a mouse click
SDL_Point getTargetCoords(const void *self_obj, SDL_Point mousePos) {

  Grid *self = ((Grid *)self_obj);
  Cell *cell = getMouseCell(self, mousePos);
  printf("cell centre is X %d, Y %d\n", cell->centre.x, cell->centre.y);
  return cell->centre;
}
