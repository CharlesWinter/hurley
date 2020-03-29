#include <SDL2/SDL.h>
#include "grid/definition.h"
#include "hero/definition.h"

#ifndef CORE_STRUCT
#define CORE_STRUCT

typedef struct
{
  Grid* grid;
  SDL_Renderer* renderer;
  SDL_Window* window;

  Hero* player;
  Hero* allies[3];

  Hero* enemies[4];

  int (*ProcessEvent)(const void* self_obj, SDL_Event* e);
  int (*RefreshGraphics)(const void* self_obj);

} Core;

#endif
