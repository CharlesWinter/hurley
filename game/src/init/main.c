#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#define VERSION "0.0.1"

int init_game(SDL_Window *window, SDL_Renderer *renderer);
int init_window(SDL_Window **window, SDL_Renderer **screenRenderer);

int main() {
  printf("Starting Hurley, Version %s\n", VERSION);

  SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;

	if (init_window(&window, &renderer) < 0) {
    printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    exit(1);
  }

  if (init_game(window, renderer) < 0) {
    printf( "loop exit, closing program %s\n", SDL_GetError() );
    exit(1);
  }
}
