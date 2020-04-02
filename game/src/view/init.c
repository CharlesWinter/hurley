#include <SDL2/SDL.h>

#include "view/definition.h"
#include "grid/definition.h"

Viewport* Init__Viewport(SDL_Window *window, SDL_Renderer *renderer) {
  Viewport* vp = (Viewport*) malloc(sizeof(Viewport));

 Grid* grid = Grid__init(renderer, window);

 vp->grid = grid;
 vp->renderer = renderer;
 vp -> window = window;

 return vp;
}
