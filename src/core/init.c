#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#include "core/init.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int init_window(SDL_Window **window, SDL_Surface **screenSurface) {

	printf("Initalising SDL...\n");
  //Initialize SDL

  if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
  {
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		return -1;
  }

	printf("Initialising Window...\n");
  *window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  if (window == NULL) {
		return -1;
  }
	printf("Created Window OK... \n");

  *screenSurface = SDL_GetWindowSurface(*window);
  if (screenSurface == NULL) {
    return -1;
  }
	printf("Got Surface OK... \n");

	return 0;
}
