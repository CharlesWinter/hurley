#include <stdio.h>
#include <SDL2/SDL.h>

#include "hero/definition.h"
#include "hero/movement.h"
#include "images/loader.h"

Hero* init_hero(char* name) {
  printf("Init New Hero %s\n", name);
  Hero* new_hero = (Hero*) malloc(sizeof(Hero));

  new_hero->Sprite = GetSpritePNG(name);

  strcpy(new_hero->Name, name);

  return new_hero;
}

// Hero__blit blits the heros sprite onto the main screenSurface
void Hero__blit(SDL_Surface *screenSurface, Hero *hero) {
  SDL_BlitSurface(hero->Sprite, NULL, screenSurface, NULL);
}

void Hero__destroy(Hero* hero) {
  if (hero->Sprite) {
    free(hero->Sprite);
  }
  if (hero) {
    free(hero);
  }
}
