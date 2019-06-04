#include <SDL2/SDL.h>
#include <stdio.h>

#include "grid/definition.h"
#include "images/loader.h"

void render(const void *self_obj, SDL_Renderer *renderer);

Cell* Cell__init(enum TerrainType type, SDL_Point position, int height, int width, SDL_Renderer* renderer) {

  Cell* new_cell = (Cell*) malloc(sizeof(Cell));

  new_cell->Texture = GetSpriteTexture("grass.png", renderer);
  new_cell->Type = type;

  new_cell->X = position.x;
  new_cell->Y = position.y;
  new_cell->Width = width;
  new_cell->Height = height;

  SDL_Point centre = {
  .x = position.x + (width / 2),
  .y = position.y + (height / 2),
  };
  new_cell->centre = centre;

  // Define methods on each cell
  new_cell->render = &render;

  return new_cell;
}

// Renders the cells texture using the passed in renderer
void render(const void *self_obj, SDL_Renderer *renderer) {
  Cell *self = ((Cell *)self_obj);

  struct SDL_Rect cell_rect = {
  	.x = self->X,
  	.y = self->Y,
  	.h = self->Height,
  	.w = self->Width,
  };

  SDL_RenderCopy(renderer, self->Texture, NULL, &cell_rect);
}

void highlight(const void *self_obj) {
  //TODO: Actually highlight the cell
}

void Cell__destroy(Cell* cell) {
  if (cell->Texture) {
    free(cell->Texture);
  }
  if (cell) {
    free(cell);
  }
}
