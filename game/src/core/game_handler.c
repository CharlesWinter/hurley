#include <stdio.h>
#include <SDL2/SDL.h>

#include "hero/definition.h"
#include "hero/init.h"

#include "core/movement_phase.h"

#define TOTAL_ROUNDS 8

// init game starts a game, and handles all operations until the game finishes
int init_game(SDL_Window *window, SDL_Renderer *renderer) {

  Heroes heroes = {
    .player_hero = init_hero("sensei.png", renderer),
  };

  for (int i = 0; i < TOTAL_ROUNDS; i++) {
    int m_p = movement_phase(heroes, window, renderer);
    if (m_p < 0) {
      printf("something went wrong with the move\n");
    }

    if (m_p > 0) {
      printf("player has ended the game");
      return 0;
    }
  }

  Hero__destroy(heroes.player_hero);
  return 0;
}
