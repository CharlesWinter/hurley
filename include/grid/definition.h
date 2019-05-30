#ifndef GRID_DEF
#define GRID_DEF

typedef struct
{
  SDL_Renderer *renderer;
  int wHeight;
  int wWidth;

  void (*renderGrid)(const void* self);

} Grid;

#endif
