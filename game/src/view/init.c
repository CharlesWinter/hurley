#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "view/definition.h"
#include "grid/definition.h"

Viewport* Init__Viewport(SDL_Window *window, SDL_Renderer *renderer) {
  Viewport* vp = (Viewport*) malloc(sizeof(Viewport));

  TTF_Font* font =  TTF_OpenFont("text/fonts.ttf", 14);
  if ( font == NULL ) {
    printf("Failed loading font: Err %s\n", TTF_GetError());
  }
  vp->font = font;

  Grid* grid = Grid__init(renderer, window);

  vp->grid = grid;
  vp->renderer = renderer;
  vp -> window = window;

 return vp;
}
