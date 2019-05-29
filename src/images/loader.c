#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string.h>

#include "images/loader.h"

int getSprite(SDL_Surface **sprite, char* imageName) {

	char* spritePath = "images/";
  strcat(spritePath, imageName);

	*sprite = SDL_LoadBMP(spritePath);
	if( *sprite == NULL ) {
		printf( "Unable to load image %s! SDL Error: %s\n",spritePath, SDL_GetError() );
		return -1;
	}
	return 1;
}

// GetSpritePNG returns an allocated SDL_Surface after loading the passed image
// name
SDL_Surface* GetSpritePNG(char* imageName) {

  // need a long enough total path so as to allow large imageNames and avoid
  // segfaults
	char spritePath[100] = "images/";
  strcat(spritePath, imageName);

	SDL_Surface* sprite = IMG_Load(spritePath);
	if( sprite == NULL ) {
		printf( "Unable to load image %s! SDL Error: %s\n",spritePath, IMG_GetError() );
		return NULL;
	}
	return sprite;
}

SDL_Texture* GetSpriteTexture(char* imageName, SDL_Renderer* renderer) {
  SDL_Surface* spriteSurface = GetSpritePNG(imageName);

  SDL_Texture *spriteTexture = SDL_CreateTextureFromSurface(renderer, spriteSurface);
  if (spriteTexture == NULL) {
    printf("couldn't load sprite texture %s\n",SDL_GetError());
  }

  SDL_FreeSurface(spriteSurface);
  return spriteTexture;
}
