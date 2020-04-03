#include <SDL2/SDL.h>

#include "core/definition.h"
#include "hero/definition.h"

int move_player(Core* core, SDL_Event* e) {
  return move_player_hero(core->player, core->viewport);
}
