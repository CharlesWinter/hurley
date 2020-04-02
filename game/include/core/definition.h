#include <SDL2/SDL.h>

#include "hero/definition.h"
#include "tcp/definition.h"
#include "view/definition.h"

#ifndef CORE_STRUCT
#define CORE_STRUCT

typedef struct
{

  Viewport* viewport;

  Hero* player;
  Hero* allies[3];

  Hero* enemies[4];

  unsigned int total_rounds;
  unsigned int current_round;
  unsigned int current_phase;

  int (*ProcessEvent)(const void* self_obj, SDL_Event* e);
  int (*ProcessTCP)(const void *self_obj, unsigned int code);

} Core;

// process evebt is used to handle SDL events
int processEvent(const void *self_obj, SDL_Event* e);
int process_tcp(const void *self_obj, unsigned int code);

int core_init(Core* core);
void Run(Core* core, TCP_Client *tcp_client);
#endif
