#include <stdlib.h>
#include <unistd.h>

#include "tcp/definition.h"

#define NEW_ROUND 465
#define MOVE_PHASE_START 466
#define MOVE_PHASE_END 467

void listen_and_wait(const void* self_obj, unsigned int* event_code) {
  //eventually this will listen for and respond with TCP events,
  //but for now will just fake some simple integers being returned

  sleep(5);

  unsigned int code = MOVE_PHASE_START;
  *event_code = code;
  return;
}

TCP_Client* New__TCP_Client() {
 TCP_Client* new_tcp_client = (TCP_Client*) malloc(sizeof(TCP_Client));

 new_tcp_client->Listen_Wait = listen_and_wait;

 return new_tcp_client;
}
