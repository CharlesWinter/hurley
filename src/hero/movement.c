#include <stdio.h>
#include <SDL2/SDL.h>

#include "hero/definition.h"
#include "hero/init.h"
#include "hero/movement.h"

#define MOVE_DISTANCE 2

// move_hero moves a hero to the new x and y coordinates specified,
// updates the heros internal x and ys, and reblits the image
int Hero__move(int movementKey, Hero* hero, SDL_Renderer *renderer) {

  switch (movementKey) {
    case SDLK_UP:
			hero->Y -= MOVE_DISTANCE;
      break;
    case SDLK_DOWN:
			hero->Y += MOVE_DISTANCE;
      break;
    case SDLK_LEFT:
			hero->X -= MOVE_DISTANCE;
      break;
    case SDLK_RIGHT:
			hero->X += MOVE_DISTANCE;
      break;
  }
  return 0;
}

// Hero__blit blits the heros sprite onto the main screenSurface
void Hero__blit(SDL_Renderer *renderer, Hero *hero) {

  struct SDL_Rect new_hero_rect = {
  	.x = hero->X,
  	.y = hero->Y,
  	.h = hero->Height,
  	.w = hero->Width,
  };

  SDL_RenderCopy(renderer, hero->Sprite, NULL, &new_hero_rect);
}
