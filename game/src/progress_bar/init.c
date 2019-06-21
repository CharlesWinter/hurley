#include <SDL2/SDL.h>

#include "progress_bar/definition.h"

void update(const void*);

ProgressBar* ProgressBar__init(SDL_Renderer *renderer, int totalTime) {

    ProgressBar* pgb = (ProgressBar*) malloc(sizeof(ProgressBar));

    pgb->renderer = renderer;
    pgb->startTime = SDL_GetTicks();
    pgb->isFinished = 0;
    pgb->totalTime = totalTime;

    pgb->update = update;

    return pgb;
}

void update(const void *self_obj) {

    // in order to use the function pointer style, need to cast the 
    ProgressBar *self = ((ProgressBar *)self_obj);

    int timeRemaining = self->totalTime - SDL_GetTicks();
    printf("time remaining is %d\n", timeRemaining);
} 