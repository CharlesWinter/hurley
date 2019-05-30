#ifndef IMG_LOADER
#define IMG_LOADER

int getSprite(SDL_Surface **sprite, char* imageName);
SDL_Surface* GetSpritePNG(char* imageName);
SDL_Texture* GetSpriteTexture(char* imageName, SDL_Renderer* renderer);

#endif
