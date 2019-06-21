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

// Heroes is a holder for all the heroes in the game
// TODO: should heroes have "methods" for all initialization?
// TODO: shold heroes have methods for destroying.
typedef struct
{
  Hero* player_hero;
  Hero* teammates[3];
  Hero* enemies[4];
} Heroes;

#endif
