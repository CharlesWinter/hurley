#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <time.h>

#include "grid/definition.h"
#include "grid/grid.h"

#include "hero/definition.h"
#include "hero/init.h"
#include "hero/movement.h"

#include "client/http_client.h"

#include "progress_bar/definition.h"

#define TOTAL_HEROES 8
// Length of a round in seconds
#define ROUND_LENGTH 30

int executeMoves(Hero *hero, SDL_Renderer *renderer, Grid* grid);

int movement_phase(Heroes heroes, SDL_Window *window, SDL_Renderer *renderer) {

  Grid* grid = Grid__init(renderer, window);
  ProgressBar* progBar = ProgressBar__init(renderer, 30);

  SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
  SDL_RenderClear(renderer);
  grid->renderGrid(grid);
	Hero__blit(renderer, heroes.player_hero);
  SDL_RenderPresent(renderer);

  // wait until the round begins
  // todo improve this madness
  time_t start_time = getPhaseStartTime();
  while (time(NULL) - start_time < 2) {
    SDL_Delay(500);
  }

  int quit = 0;
  int input_made = 0;
  SDL_Event e;
  printf("input unlocked\n");
  while (!input_made && SDL_WaitEvent(&e)) {
    if (e.type == SDL_QUIT) {
      quit = 1;
      input_made = 1;
    }

    if (e.type == SDL_MOUSEBUTTONUP) {
      SDL_Point mouseClickPos;
      SDL_GetMouseState(&mouseClickPos.x, &mouseClickPos.y);
      heroes.player_hero->CurrentTarget = grid->getTargetCoords(grid, mouseClickPos);
      input_made = 1;
    }
  }

  //move the hero.
  SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
  SDL_RenderClear(renderer);
  grid->renderGrid(grid);
  Hero__move(heroes.player_hero, renderer);
  SDL_RenderPresent(renderer);

  printf("movement phase finished, quit is %d\n", quit);
  return quit;
}
