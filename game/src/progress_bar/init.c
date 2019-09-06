#include <SDL2/SDL.h>

#include "progress_bar/definition.h"

void update(const void*);

ProgressBar* ProgressBar__init(SDL_Renderer *renderer, int totalTime, SDL_Point display_location, unsigned int h, unsigned int w) {

    ProgressBar* pgb = (ProgressBar*) malloc(sizeof(ProgressBar));

    pgb->renderer = renderer;
    pgb->startTime = SDL_GetTicks();
    pgb->totalTime = SDL_GetTicks() + totalTime * 1000;
    pgb->location = display_location;
    pgb->height = h;
    pgb->width = w;

    pgb->IsFinished = 0;
    pgb->Update = update;

    printf("initial time is %d\n", pgb->totalTime);

    return pgb;
}

void blit(const void *self_obj, SDL_Rect bar) {
  ProgressBar *self = ((ProgressBar *)self_obj);

  SDL_SetRenderDrawColor( self->renderer, 0xFF, 0x00, 0x00, 0xFF );
  SDL_RenderFillRect( self->renderer, &bar );
  SDL_SetRenderDrawColor(self->renderer, 0xFF, 0xFF, 0xFF, 0xFF );
}

// calculateLength determines the percentage for the new draw length for the bar.
double calculateLength(const void *self_obj) {
  ProgressBar *self = ((ProgressBar *)self_obj);
  double d_total_time = self->totalTime;

  double totalLength = (d_total_time - SDL_GetTicks()) / d_total_time;
  if (totalLength < 0 || totalLength > 1) {
    return 0;
  }
  return totalLength;
}

void update(const void *self_obj) {

    // in order to use the function pointer style, need to cast
    ProgressBar *self = ((ProgressBar *)self_obj);

    int timeRemaining = self->totalTime - SDL_GetTicks();

    if (timeRemaining <= 0) {
      self->IsFinished = 1;
    }

    double currentLength = calculateLength(self_obj);

    printf("current length is %f\n", currentLength);

    SDL_Rect currentBar = {
      .x = self->location.x,
      .y = self->location.y,
      .h = self->height,
      .w = self->width*currentLength,
    };

    blit(self_obj, currentBar);
}
