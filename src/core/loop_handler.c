#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#include "core/loop_handler.h"

#include "hero/definition.h"
#include "hero/init.h"
#include "hero/movement.h"

int start_loop_handler(SDL_Window *window, SDL_Surface *screenSurface) {

  Hero* sensei = init_hero("sensei.png");

	Hero__blit(screenSurface, sensei);

	SDL_UpdateWindowSurface(window);

  printf("starting main loop handler\n");
  SDL_Event e;

  int quit = 0;

  while(quit == 0) {
    while (SDL_PollEvent(&e) != 0) {
      if(e.type == SDL_QUIT) {
        quit = 1;
      }

      if (e.type == SDL_KEYDOWN) {
        Hero__move(e.key.keysym.sym, sensei, screenSurface);
      }
			SDL_UpdateWindowSurface(window);
    }
  }

  Hero__destroy(sensei);

  return 0;
}
