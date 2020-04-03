#include <SDL2/SDL.h>

#include "hero/definition.h"
#include "view/definition.h"

SDL_Point getMouseCoords() {
  SDL_Point mouseClickPos;
  SDL_GetMouseState(&mouseClickPos.x, &mouseClickPos.y);
  return mouseClickPos;
}

int move_player_hero(Hero* hero, Viewport *viewport) {
  SDL_Point mouseCoords = getMouseCoords();
  hero->CurrentTarget = viewport->grid->getTargetCoords(viewport->grid, mouseCoords);

  SDL_Point heroCurrentPos = {
    .x = hero->X,
    .y = hero->Y,
  };
  viewport->player = hero;

  Hero__move(hero, viewport->renderer);

  viewport->grid->renderPath(viewport->grid, heroCurrentPos, hero->CurrentTarget);
  SDL_RenderPresent(viewport->renderer);

  SDL_Delay(2000);

  refresh_graphics(viewport);

  // for now just hardcode the viewport to only allow the player
  return 0;
}
