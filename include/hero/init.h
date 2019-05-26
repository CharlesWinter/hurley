#ifndef HERO_INIT
#define HERO_INIT

Hero* init_hero(char* name);

void Hero__blit(SDL_Surface *screenSurface, Hero *hero);
void Hero__destroy(Hero* hero);
#endif
