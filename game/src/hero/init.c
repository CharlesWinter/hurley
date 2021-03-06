#include <stdio.h>
#include <SDL2/SDL.h>

#include "hero/definition.h"
#include "images/loader.h"

Hero* init_hero(char* name, SDL_Renderer* renderer) {
  printf("Init New Hero %s\n", name);
  Hero* new_hero = (Hero*) malloc(sizeof(Hero));

	new_hero->X = 0;
	new_hero->Y = 0;

  new_hero->MoveDistance = 4;

  new_hero->Sprite = GetSpriteTexture(name, renderer);
  SDL_QueryTexture(new_hero->Sprite, NULL, NULL, &new_hero->Width, &new_hero->Height);

  strcpy(new_hero->Name, name);

  return new_hero;
}

void Hero__destroy(Hero* hero) {
  if (hero->Sprite) {
    free(hero->Sprite);
  }
  if (hero) {
    free(hero);
  }
}

// game(client) C <----> python <-----> game(client) C
//
// keyboard --> game --> python
// TCP      `:w
// --> game()
