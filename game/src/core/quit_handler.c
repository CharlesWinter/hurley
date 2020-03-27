#include <SDL2/SDL.h>
#include "core/core.h"

int quit_handler(Core* core, SDL_Event* e) {
  printf("quitting!\n");
  return 1;
}
