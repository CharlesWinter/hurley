#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#include "core/loop_handler.h"

#include "hero/definition.h"
#include "hero/init.h"
#include "hero/movement.h"

int start_loop_handler(SDL_Window *window, SDL_Renderer *renderer) {

  Hero* sensei = init_hero("sensei.png", renderer);

	Hero__blit(renderer, sensei);

	SDL_UpdateWindowSurface(window);

  printf("starting main loop handler\n");
  SDL_Event e;

  int quit = 0;

  while(quit == 0) {
    while (SDL_PollEvent(&e) != 0) {
      SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
      SDL_RenderClear(renderer);
      if(e.type == SDL_QUIT) {
        quit = 1;
      }

      if (e.type == SDL_KEYDOWN) {
        Hero__move(e.key.keysym.sym, sensei, renderer);
      }
      Hero__blit(renderer, sensei);
      SDL_RenderPresent(renderer);
    }
  }

  Hero__destroy(sensei);

  return 0;
}
