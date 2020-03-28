#ifndef HERO_INIT
#define HERO_INIT

#include "hero/definition.h"

Hero* init_hero(char* name, SDL_Renderer *renderer);

void Hero__blit(SDL_Renderer *renderer, Hero *hero);
void Hero__destroy(Hero* hero);
#endif
