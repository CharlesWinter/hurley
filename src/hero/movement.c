#include <stdio.h>
#include <SDL2/SDL.h>

#include "hero/init.h"
#include "hero/movement.h"

int move_hero(int movementKey, Hero hero) {
  printf("moving player");

  switch (movementKey) {
    case SDLK_UP:
      break;
    case SDLK_DOWN:
      break;
    case SDLK_LEFT:
      break;
    case SDLK_RIGHT:
      break;
  }
  return 0;
}
