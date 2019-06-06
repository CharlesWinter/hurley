#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#include "core/init.h"
#include "core/loop_handler.h"

#define VERSION "0.0.1"

int main() {
  printf("Starting Hurley, Version %s\n", VERSION);

  SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;

	if (init_window(&window, &renderer) < 0) {
    printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    exit(1);
  }

  if (start_loop_handler(window, renderer) < 0) {
    printf( "loop exit, closing program %s\n", SDL_GetError() );
    exit(1);
  }

  /*
	SDL_Surface *plySprite = NULL;
	getSprite(&plySprite);

  SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );
  //SDL_BlitSurface(gHelloWorld, NULL, screenSurface, NULL);
  SDL_BlitSurface(plySprite, NULL, screenSurface, NULL);

  SDL_UpdateWindowSurface(window);
  SDL_Delay(2000);
	//close(window, screenSurface);
  */
}

/*
void close(SDL_Window **window, SDL_Surface **surface) {
	//Deallocate surface
	SDL_FreeSurface( *surface );
	//Destroy window
	SDL_DestroyWindow( *window );
	//Quit SDL subsystems
	SDL_Quit();
}
*/
