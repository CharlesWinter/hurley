#include <SDL2/SDL.h>

#include "core/core.h"

SDL_Point getMouseCoords() {
  SDL_Point mouseClickPos;
  SDL_GetMouseState(&mouseClickPos.x, &mouseClickPos.y);
  return mouseClickPos;
}

int move_player(Core* core, SDL_Event* e) {
  SDL_Point mouseCoords = getMouseCoords();

  printf("mouse coords X: %d, Y: %d\n", mouseCoords.x, mouseCoords.y);
  return 0;

}
