#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#include "core/loop_handler.h"

#include "grid/definition.h"
#include "grid/grid.h"

#include "hero/definition.h"
#include "hero/init.h"
#include "hero/movement.h"

int start_loop_handler(SDL_Window *window, SDL_Renderer *renderer) {

  Hero* sensei = init_hero("sensei.png", renderer);
	Hero__blit(renderer, sensei);

  Grid* grid = Grid__init(renderer, window);

  int mouseX, mouseY;

  int quit = 0;
  SDL_Event e;
  while(quit == 0) {
    while (SDL_PollEvent(&e) != 0) {
      SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
      SDL_RenderClear(renderer);

      grid->renderGrid(grid);
      if(e.type == SDL_QUIT) {
        quit = 1;
      }

      // simple test code to get sensei to move around. to be removed
      if (e.type == SDL_KEYDOWN) {
        Hero__move(e.key.keysym.sym, sensei, renderer);
      }

      if (e.type == SDL_MOUSEBUTTONUP) {
        SDL_GetMouseState(&mouseX, &mouseY);
        SDL_Point mousePos = {
          .x = mouseX,
          .y = mouseY,
        };
        SDL_Point targPos = grid->getTargetCoords(grid, mousePos);
        printf("targX %d, targY %d\n", targPos.x, targPos.y);
      }

      if (e.type == SDL_MOUSEMOTION) {
        SDL_GetMouseState(&mouseX, &mouseY);
        SDL_Point mousePos = {
          .x = mouseX,
          .y = mouseY,
        };
        grid->highlightCell(grid, mousePos);
      }

      Hero__blit(renderer, sensei);
      SDL_RenderPresent(renderer);
    }
  }

  Hero__destroy(sensei);

  return 0;
}
