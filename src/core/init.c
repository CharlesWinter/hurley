#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "core/init.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int init_window(SDL_Window **window, SDL_Renderer **screenRenderer) {

	printf("Initalising SDL...\n");
  //Initialize SDL

  if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
  {
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		return -1;
  }

	printf("Initialising Window...\n");
  *window = SDL_CreateWindow("Hurley", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  if (window == NULL) {
		return -1;
  }
	printf("Created Window OK... \n");

  *screenRenderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
  if (*screenRenderer == NULL) {
    printf("Couldn't create renderer %s\n", SDL_GetError());
  }
  int blank = 0xFF;
  SDL_SetRenderDrawColor(*screenRenderer, blank, blank, blank, blank);
  SDL_RenderClear(*screenRenderer);
  SDL_RenderPresent(*screenRenderer);

  // initialise the image loading lib for PNGs
 int imgFlags = IMG_INIT_PNG;
 if( !( IMG_Init( imgFlags ) & imgFlags ) ) {
	 printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
 }

	return 0;
}
