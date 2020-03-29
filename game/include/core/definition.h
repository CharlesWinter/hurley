#include <SDL2/SDL.h>
#include "grid/definition.h"
#include "hero/definition.h"
#include "tcp/definition.h"

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

  unsigned int Total_Rounds;
  unsigned int Current_Round;
  unsigned int Current_Phase;

  int (*ProcessEvent)(const void* self_obj, SDL_Event* e);
  int (*RefreshGraphics)(const void* self_obj);

} Core;

// process evebt is used to handle SDL events
int processEvent(const void *self_obj, SDL_Event* e);
int refresh_graphics(const void *self_obj);
int core_init(Core* core);
void Run(Core* core, TCP_Client *tcp_client);
#endif
