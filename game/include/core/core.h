#include <SDL2/SDL.h>

typedef struct
{
  unsigned int turn_number;
  int (*ProcessEvent)(const void* self_obj, SDL_Event* e);

} Core;
