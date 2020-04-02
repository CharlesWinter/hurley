#include <SDL2/SDL.h>

#include "view/definition.h"

int refresh_graphics(Viewport* vp) {
  SDL_SetRenderDrawColor( vp->renderer, 0xFF, 0xFF, 0xFF, 0xFF );
  SDL_RenderClear(vp->renderer);
  vp->grid->renderGrid(vp->grid);
  SDL_RenderPresent(vp->renderer);

  return 0;
}
