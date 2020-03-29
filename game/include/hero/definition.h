#ifndef HERO_DEF
#define HERO_DEF

typedef struct
{
  SDL_Texture* Sprite;
  char Name[50];

	int X;
	int Y;
  int Height;
  int Width;

  int MoveDistance;

  SDL_Point CurrentTarget;

} Hero;

Hero* init_hero(char* name, SDL_Renderer *renderer);

void Hero__blit(SDL_Renderer *renderer, Hero *hero);
void Hero__destroy(Hero* hero);
int Hero__move(Hero* hero, SDL_Renderer *renderer);

#endif
