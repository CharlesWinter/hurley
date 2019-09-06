#ifndef PROGRESS_BAR_DEFINITION
#define PROGRESS_BAR_DEFINITION

typedef struct {

  SDL_Renderer *renderer;

  int startTime;
  // totalTime is the time in seconds until the timer should be declared finished
  int totalTime;
  int IsFinished;

  // location is the x and y of the top left corner of the bar
  SDL_Point location;

  // height and width are the total height and width of the bar
  // these numbers are never updated as the bar shrinks
  unsigned int height;
  unsigned int width;

  void (*Update)(const void *self);

} ProgressBar;

void ProgressBar__destroy(ProgressBar* progBar);
ProgressBar* ProgressBar__init(SDL_Renderer *renderer, int totalTime, SDL_Point display_location, unsigned int h, unsigned int w);

#endif
