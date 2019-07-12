#include <SDL2/SDL.h>

#include "progress_bar/definition.h"

void ProgressBar__destroy(ProgressBar* progBar) {
 free(progBar);
}
