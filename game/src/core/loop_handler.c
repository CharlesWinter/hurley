#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <time.h>

#include "core/loop_handler.h"

#include "grid/definition.h"
#include "grid/grid.h"

#include "hero/definition.h"
#include "hero/init.h"
#include "hero/movement.h"

#include "client/http_client.h"

#define TOTAL_HEROES 8

int executeMoves(Hero *hero, SDL_Renderer *renderer, Grid* grid);
sub_phase_return updateMovementInput(SDL_Event e, Hero *hero, SDL_Renderer *renderer, Grid* grid);

int start_loop_handler(SDL_Window *window, SDL_Renderer *renderer) {

  Hero* player_hero = init_hero("sensei.png", renderer);

  Grid* grid = Grid__init(renderer, window);

  SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
  SDL_RenderClear(renderer);
  grid->renderGrid(grid);
	Hero__blit(renderer, player_hero);
  SDL_RenderPresent(renderer);

  // wait until the round begins
  // todo improve this madness
  time_t start_time = getPhaseStartTime();
  while (time(NULL) - start_time < 2) {
    SDL_Delay(500);
  }

  // wait over, unlock input
  int allowInput, makeMovement;
  bool quit = false;
  SDL_Event e;
  printf("input unlocked\n");
  while (!quit && SDL_WaitEvent(&e)) {
    if (e.type == SDL_QUIT) {
      quit = true;
    }

    if (e.type == SDL_MOUSEBUTTONUP) {
      SDL_Point mouseClickPos;
      SDL_GetMouseState(&mouseClickPos.x, &mouseClickPos.y);
      player_hero->CurrentTarget = grid->getTargetCoords(grid, mouseClickPos);

      // just exist the game loop here as a test.
      quit = 1;
    }
  }

  //move the hero.
  SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
  SDL_RenderClear(renderer);
  grid->renderGrid(grid);
  Hero__move(player_hero, renderer);
  SDL_RenderPresent(renderer);

  SDL_Delay(2000);

}
