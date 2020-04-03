#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "view/definition.h"

int Viewport__display_banner(Viewport* vp, char* message) {
  refresh_graphics(vp);

  SDL_Color tc = {0, 0, 0};
  SDL_Surface* textSurface = TTF_RenderText_Solid( vp->font, message,  tc);
  SDL_Texture* mTexture = SDL_CreateTextureFromSurface(vp->renderer, textSurface);
  SDL_Rect renderQuad = {
    .x = 100,
    .y = 100,
    .h = 100,
    .w = 300,
  };

  SDL_Point centre = {10, 100};

  SDL_RenderCopyEx(vp->renderer, mTexture, NULL, &renderQuad, 0, &centre, SDL_FLIP_NONE);
  SDL_RenderPresent(vp->renderer);
  return 0;
}
