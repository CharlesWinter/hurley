#include <SDL2/SDL.h>
#include "core/definition.h"

int quit_handler(Core* core, SDL_Event* e) {
  free(core);
  return 1;
}
