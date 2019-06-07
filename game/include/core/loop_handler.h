#ifndef CORE_LOOP
#define CORE_LOOP

int start_loop_handler();

typedef struct {
  char* err_msg;
  int err;

  int action;

} sub_phase_return;

#endif
