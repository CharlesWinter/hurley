#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#include "core/loop_handler.h"

#include "hero/definition.h"
#include "hero/init.h"
#include "hero/movement.h"

int start_loop_handler(SDL_Window *window, SDL_Surface *screenSurface) {

 int 4 = init_hero();

  SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );
  SDL_BlitSurface(sensei.sprite, NULL, screenSurface, NULL);

  SDL_UpdateWindowSurface(window);

  printf("starting main loop handler\n");
  SDL_Event e;

  int quit = 0;

  while(quit == 0) {
    while (SDL_PollEvent(&e) != 0) {
      printf("polling\n");
      if(e.type == SDL_QUIT) {
        quit = 1;
      }

      if (e.type == SDL_KEYDOWN) {
        move_hero(e.key.keysym.sym);
      }
    }
  }
  return 0;
}
