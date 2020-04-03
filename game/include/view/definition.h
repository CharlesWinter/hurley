/*
 * The viewport is intended as the sole place (apart from main) where the
 * application interacts with SDL. The viewport will have functions to update
 * the state, such as moving a player etc.
 * */
#ifndef VIEW_PORT
#define VIEW_PORT

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "hero/definition.h"
#include "grid/definition.h"

typedef struct
{
  SDL_Renderer* renderer;
  SDL_Window* window;
  Grid* grid;
  TTF_Font* font;

  Hero* player;
  Hero* allies[3];

  Hero* enemies[4];

  char* current_phase;

} Viewport;

int move_player_hero(Hero* hero, Viewport *viewport);
int refresh_graphics(Viewport *viewport);

Viewport* Init__Viewport(SDL_Window *window, SDL_Renderer *renderer, Hero* player);

int Viewport__display_banner(Viewport* vp, char* message);

#endif
