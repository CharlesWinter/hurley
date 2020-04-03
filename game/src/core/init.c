#include <SDL2/SDL.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

#include "hero/definition.h"
#include "tcp/definition.h"
#include "core/definition.h"
#include "view/definition.h"
#include "core/handlers.h"

#define TOTAL_ROUNDS 8

int counter;
pthread_mutex_t lock;

void Run(Core* core, TCP_Client* tcp_client) {
  printf("running the game\n");
  pthread_t thread_1, thread_2, thread_3;

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
    while (exit_all_threads != 1) {
      sleep(1);
    }

    return NULL;
  }

  // in place of actually making a TCP connection, this thread will be used to
  // simulate input from the server
  void* mockTCPThread(void *arg) {
      unsigned int event_code;

      while( tcp_client->Listen_Wait(tcp_client, &event_code)) {
        pthread_mutex_lock(&lock);
        printf("received a thing\n");

        core->ProcessTCP(core, event_code);
        pthread_mutex_unlock(&lock);

        if (exit_all_threads == 1) {
          return NULL;
        }
      }
      printf("returning from the mock tcp handler\n");

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

  err = pthread_create(&thread_3, NULL, &mockTCPThread, NULL);
  if (err != 0) {
    return;
  }

  pthread_join(thread_1, NULL);
  pthread_join(thread_2, NULL);
  pthread_join(thread_3, NULL);

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
  refresh_graphics(core->viewport);
  return 0;
}

int process_tcp(const void *self_obj, unsigned int code) {
  printf("received code: %d\n", code);
  Core *self = ((Core *)self_obj);

  switch (code) {
    case 465:
      printf("received event NEW_ROUND\n");
      self->current_round++;
      self->viewport->current_phase =  "new round";
      return 0;
    case 466:
      printf("received event MOVE_PHASE_START\n");
      self->viewport->current_phase =  "move phase start";
      return 0;
    case 467:
      printf("received event MOVE_PHASE_END\n");
      self->viewport->current_phase =  "move phase end";
      return 0;
  }
  self->current_phase = code;

  refresh_graphics(self->viewport);
  return 0;
}
