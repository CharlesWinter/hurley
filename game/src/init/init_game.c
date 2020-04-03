#include "core/definition.h"
#include "hero/definition.h"
#include "tcp/definition.h"
#include "view/definition.h"

// init game starts a game, and handles all operations until the game finishes
int init_game(SDL_Window *window, SDL_Renderer *renderer, TCP_Client* tcp_client) {
  Hero* player = init_hero("sensei.png", renderer);

  // attach properties to core
  Core* core = (Core*) malloc(sizeof(Core));
  core->viewport = Init__Viewport(window, renderer, player);

  core->player=player;

  // attach functions to the core
  core->ProcessEvent = processEvent;
  core->ProcessTCP = process_tcp;

  // core_init performs the initialization of the graphics, and blits the hero
  // to the screen
  core_init(core);

  // running the core actually starts the game
  Run(core, tcp_client);

  return 0;
}
