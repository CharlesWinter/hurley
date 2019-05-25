#include <stdio.h>
#include <SDL2/SDL.h>

#include "hero/definition.h"
#include "hero/movement.h"
#include "images/loader.h"

Hero* init_hero() {
  Hero new_hero;
  SDL_Surface* heroSprite =  GetSpritePNG("sensei.png");

  new_hero->Sprite = heroSprite;
  return new_hero;
}
