#include <SDL2/SDL.h>
#include<pthread.h>

#include "core/core.h"
#include <time.h>

#define TOTAL_ROUNDS 8

int processEvent(const void *self_obj, SDL_Event* e) {
  Core *self = ((Core *)self_obj);

  switch (e->type) {
    case SDL_QUIT:
      return quit_handler(self, e);
    case SDL_MOUSEBUTTONUP:
      return move_player(self, e);
  }

  return 0;
}

void* doSomeThing(void *arg)
{
    unsigned long i = 0;
    counter += 1;
    printf("\n Job %d started\n", counter);

    for(i=0; i<(0xFFFFFFFF);i++);
    printf("\n Job %d finished\n", counter);

    return NULL;
}

void Run(Core* core) {
  SDL_Event e;
  int exit_code;

}

// init game starts a game, and handles all operations until the game finishes
int init_game(SDL_Window *window, SDL_Renderer *renderer) {
  Core* core = (Core*) malloc(sizeof(Core));
  core->ProcessEvent = processEvent;

  Run(core);

  free(core);
  return 0;
}
