#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#include "core/loop_handler.h"

#include "grid/definition.h"
#include "grid/grid.h"

#include "hero/definition.h"
#include "hero/init.h"
#include "hero/movement.h"

#define TOTAL_HEROES 8

int executeMoves(Hero *sensei, SDL_Renderer *renderer);

int start_loop_handler(SDL_Window *window, SDL_Renderer *renderer) {

  Hero* sensei = init_hero("sensei.png", renderer);
	Hero__blit(renderer, sensei);

  Grid* grid = Grid__init(renderer, window);

  int mouseX, mouseY;
  SDL_Point mouseClickPos;

  int quit = 0;

  // allowInput is locked out whenever a round expires, for example when moves
  // are being executed
  int allowInput = 1;

  SDL_Event e;
  while(quit == 0) {

    while (allowInput == 1 && quit == 0) {
      while (SDL_PollEvent(&e) != 0) {
        SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear(renderer);

        grid->renderGrid(grid);
        if(e.type == SDL_QUIT) {
          quit = 1;
        }

        if (e.type == SDL_MOUSEBUTTONUP) {
          SDL_GetMouseState(&mouseClickPos.x, &mouseClickPos.y);
          sensei->CurrentTarget = grid->getTargetCoords(grid, mouseClickPos);

          // Oversimplified; just simple lock to move sensei once input is given
          allowInput = 0;
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

    // Once the flag is set to block movement, move all heroes (for now just
    // sensei)
    SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear(renderer);
    grid->renderGrid(grid);
    executeMoves(sensei, renderer);
    SDL_RenderPresent(renderer);
    allowInput = 1;
  }
  Hero__destroy(sensei);

  return 0;
}

int executeMoves(Hero *hero, SDL_Renderer *renderer) {

  int reached_dest = Hero__move(hero, renderer);
  return 0;
}
