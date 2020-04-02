#include <SDL2/SDL.h>

#include "hero/definition.h"
#include "view/definition.h"

SDL_Point getMouseCoords() {
  SDL_Point mouseClickPos;
  SDL_GetMouseState(&mouseClickPos.x, &mouseClickPos.y);
  return mouseClickPos;
}

int move_hero(Hero* hero, Viewport *viewport) {
  SDL_Point mouseCoords = getMouseCoords();
  hero->CurrentTarget = viewport->grid->getTargetCoords(viewport->grid, mouseCoords);

  SDL_Point heroCurrentPos = {
    .x = hero->X,
    .y = hero->Y,
  };

  viewport->grid->renderPath(viewport->grid, heroCurrentPos, hero->CurrentTarget);

  SDL_RenderPresent(viewport->renderer);

  SDL_Delay(2000);
  refresh_graphics(viewport);
  Hero__move(hero, viewport->renderer);
  SDL_RenderPresent(viewport->renderer);

  return 0;
}
