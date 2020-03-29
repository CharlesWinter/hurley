#include "core/definition.h"
#include "grid/definition.h"
#include "hero/definition.h"
#include "tcp/definition.h"

// init game starts a game, and handles all operations until the game finishes
int init_game(SDL_Window *window, SDL_Renderer *renderer, TCP_Client* tcp_client) {
  Grid* grid = Grid__init(renderer, window);
  Hero* player = init_hero("sensei.png", renderer);

  // attach properties to core
  Core* core = (Core*) malloc(sizeof(Core));
  core->grid = grid;
  core->window = window;
  core->renderer = renderer;
  core->player=player;

  // attach functions to the core
  core->ProcessEvent = processEvent;
  core->RefreshGraphics = refresh_graphics;

  // core_init performs the initialization of the graphics, and blits the hero
  // to the screen
  core_init(core);

  // running the core actually starts the game
  Run(core, tcp_client);

  return 0;
}
