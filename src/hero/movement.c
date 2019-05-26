#include <stdio.h>
#include <SDL2/SDL.h>

#include "hero/definition.h"
#include "hero/init.h"
#include "hero/movement.h"

int move_hero(int movementKey, Hero* hero) {

  switch (movementKey) {
    case SDLK_UP:
      printf("moving %s up\n", hero->Name);
      break;
    case SDLK_DOWN:
      printf("moving %s down\n", hero->Name);
      break;
    case SDLK_LEFT:
      printf("moving %s left\n", hero->Name);
      break;
    case SDLK_RIGHT:
      printf("moving %s right\n", hero->Name);
      break;
  }
  return 0;
}
