#include <SDL2/SDL.h>

#include "core/definition.h"
#include "hero/definition.h"

SDL_Point getMouseCoords() {
  SDL_Point mouseClickPos;
  SDL_GetMouseState(&mouseClickPos.x, &mouseClickPos.y);
  return mouseClickPos;
}

int move_player(Core* core, SDL_Event* e) {
  SDL_Point mouseCoords = getMouseCoords();

  core->player->CurrentTarget = core->grid->getTargetCoords(core->grid, mouseCoords);
  SDL_Point heroCurrentPos = {
    .x = core->player->X,
    .y = core->player->Y,
  };

  core->grid->renderPath(core->grid, heroCurrentPos, core->player->CurrentTarget);
  SDL_RenderPresent(core->renderer);

  SDL_Delay(2000);
  core->RefreshGraphics(core);
  Hero__move(core->player, core->renderer);
  SDL_RenderPresent(core->renderer);

  return 0;
}
