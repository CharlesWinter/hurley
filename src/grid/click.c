#include <SDL2/SDL.h>
#include <stdio.h>

#include "grid/definition.h"
#include "grid/cells.h"

// getClickedCell, returns a pointer to the cell that the mouse
// was in when the mouse button was raised
Cell* getMouseCell(Grid *grid, SDL_Point clickPoint) {

  int rowIndex = clickPoint.y / grid->rowHeight;
  int colIndex = clickPoint.x / grid->colWidth;

  return grid->cells[rowIndex][colIndex];

  printf("rowIdx %d, colIdx %d\n", rowIndex, colIndex);

  return NULL;
}
