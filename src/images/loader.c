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

SDL_Surface* GetSpritePNG(char* imageName) {

	char* spritePath = "images/";
  strcat(spritePath, imageName);

	SDL_Surface* sprite = IMG_Load(spritePath);
	if( sprite == NULL ) {
		printf( "Unable to load image %s! SDL Error: %s\n",spritePath, SDL_GetError() );
		return NULL;
	}
	return sprite;

}
