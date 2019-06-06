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

#endif
