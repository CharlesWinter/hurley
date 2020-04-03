#include <SDL2/SDL.h>

#include "view/definition.h"
#include "hero/definition.h"

int refresh_graphics(Viewport* vp) {
  SDL_SetRenderDrawColor( vp->renderer, 0xFF, 0xFF, 0xFF, 0xFF );
  SDL_RenderClear(vp->renderer);
  vp->grid->renderGrid(vp->grid);

  Hero__blit(vp->renderer, vp->player);
  Viewport__display_banner(vp, vp->current_phase);

  SDL_RenderPresent(vp->renderer);
  return 0;
}
