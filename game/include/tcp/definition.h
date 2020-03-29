#ifndef TCP_CLIENT
#define TCP_CLIENT

typedef struct
{
  unsigned int current_phase;
  unsigned int total_rounds;

  unsigned int (*Listen_Wait)(const void* self_obj, unsigned int* event_code);
} TCP_Client;

TCP_Client* New__TCP_Client();

#endif
