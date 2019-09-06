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

  int window_h, window_w;
  SDL_GetWindowSize(window, &window_w, &window_h);

  SDL_Point pbLoc = {
    .x = window_w*0.1,
    .y = window_h*0.9,
  };
  ProgressBar* progBar = ProgressBar__init(renderer, 2, pbLoc, 10, 100);

  SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
  SDL_RenderClear(renderer);
  grid->renderGrid(grid);
	Hero__blit(renderer, heroes.player_hero);
  SDL_RenderPresent(renderer);

  // wait until the round begins
  // todo improve this madness
  while (progBar->IsFinished == 0) {
    SDL_Delay(50);
    SDL_RenderClear(renderer);
    grid->renderGrid(grid);
    progBar->Update(progBar);
    Hero__blit(renderer, heroes.player_hero);
    SDL_RenderPresent(renderer);
  }
  ProgressBar__destroy(progBar);

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
      SDL_Point heroCurrentPos = {
        .x = heroes.player_hero->X,
        .y = heroes.player_hero->Y,
      };
      grid->renderPath(grid, heroCurrentPos, heroes.player_hero->CurrentTarget);
      SDL_RenderPresent(renderer);
      SDL_Delay(2000);
      input_made = 1;
    }
  }

  // move the hero.
  SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
  SDL_RenderClear(renderer);
  grid->renderGrid(grid);
  Hero__move(heroes.player_hero, renderer);
  SDL_RenderPresent(renderer);

  printf("movement phase finished, quit is %d\n", quit);
  return quit;
}
