#ifndef PROGRESS_BAR_DEFINITION
#define PROGRESS_BAR_DEFINITION

typedef struct {

  SDL_Renderer *renderer;

  int startTime;
  // totalTime is the time in seconds until the timer should be declared finished
  int totalTime;
  int isFinished;

  void (*update)(const void *self);

} ProgressBar;

void ProgressBar__destroy(ProgressBar);

#endif
