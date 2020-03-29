#include <SDL2/SDL.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

#include "hero/definition.h"
#include "grid/definition.h"
#include "core/definition.h"
#include "core/handlers.h"

#define TOTAL_ROUNDS 8

pthread_t tid[2];
int counter;
pthread_mutex_t lock;

void Run(Core* core) {
  pthread_t thread_1, thread_2;

  int exit_all_threads;

  void* eventThread(void *arg) {
    SDL_Event e;
    while (SDL_WaitEvent(&e)) {
      pthread_mutex_lock(&lock);
      exit_all_threads = core->ProcessEvent(core, &e);
      pthread_mutex_unlock(&lock);
      if (exit_all_threads == 1) {
        printf("returning\n");
        return NULL;
      }
    }

    return NULL;
  }

  void* timerThread(void *arg) {
    time_t seconds;
    while (exit_all_threads != 1) {
      seconds = time(NULL);
      printf("Seconds since January 1, 1970 = %ld\n", seconds);
      sleep(2);
    }

    return NULL;
  }

	if (pthread_mutex_init(&lock, NULL) != 0)
	{
		printf("\n mutex init failed\n");
		return;
	}

  int err = pthread_create(&thread_1, NULL, &eventThread, NULL);
  if (err != 0) {
    return;
  }
  err = pthread_create(&thread_2, NULL, &timerThread, NULL);
  if (err != 0) {
    return;
  }

  pthread_join(thread_1, NULL);
  pthread_join(thread_2, NULL);

	pthread_mutex_destroy(&lock);

  return;
}

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

int core_init(Core* core) {
  core->RefreshGraphics(core);
  Hero__blit(core->renderer, core->player);
  return 0;
}

int refresh_graphics(const void *self_obj) {
  Core *self = ((Core *)self_obj);

  SDL_SetRenderDrawColor( self->renderer, 0xFF, 0xFF, 0xFF, 0xFF );
  SDL_RenderClear(self->renderer);
  self->grid->renderGrid(self->grid);
  SDL_RenderPresent(self->renderer);

  return 0;
}
