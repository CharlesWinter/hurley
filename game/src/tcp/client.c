#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "tcp/definition.h"

#define NEW_ROUND 465
#define MOVE_PHASE_START 466
#define MOVE_PHASE_END 467

unsigned int listen_and_wait(const void* self_obj, unsigned int* event_code) {
  //eventually this will listen for and respond with TCP events,
  //but for now will just fake some simple integers being returned
  TCP_Client *self = ((TCP_Client *)self_obj);
  sleep(5);

  printf("current state is: %d\n", self->current_phase);

  unsigned int code;

  // cycle is NEW_ROUND -> MOVE_PHASE_START -> MOVE_PHASE_END
  if (self->current_phase == 0 || self->current_phase == MOVE_PHASE_END) {
    code = NEW_ROUND;
  } else if (self->current_phase == NEW_ROUND) {
    code = MOVE_PHASE_START;
  } else {
    code = MOVE_PHASE_END;
  }

  if (self->current_phase == MOVE_PHASE_END) {
    self->total_rounds++;
  }

  *event_code = code;
  self->current_phase=code;

  return 1;
}

TCP_Client* New__TCP_Client() {
 TCP_Client* new_tcp_client = (TCP_Client*) malloc(sizeof(TCP_Client));

 new_tcp_client->Listen_Wait = listen_and_wait;

 return new_tcp_client;
}
