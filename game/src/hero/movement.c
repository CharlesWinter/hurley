#include <stdio.h>
#include <SDL2/SDL.h>

#include "hero/definition.h"

#define MOVE_DISTANCE 2

// move_hero moves a hero to the new x and y coordinates specified,
// updates the heros internal x and ys, and reblits the image
int Hero__move(Hero* hero, SDL_Renderer *renderer) {

  hero->X = hero->CurrentTarget.x - (hero->Width / 2);
  hero->Y = hero->CurrentTarget.y - (hero->Height / 2);

  Hero__blit(renderer, hero);

  return 1;
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
