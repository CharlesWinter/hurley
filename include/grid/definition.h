#ifndef GRID_DEF
#define GRID_DEF

enum TerrainType {Ground = 0, FullCover = 1};

typedef struct
{
  SDL_Texture* Texture;
  enum TerrainType Type;

  int X, Y, Width, Height;
  SDL_Point centre;

  void (*render)(const void *self, SDL_Renderer *renderer);
  void (*highlight)(const void *self_obj);

} Cell;

typedef struct
{
  SDL_Renderer *renderer;
  int wHeight;
  int wWidth;

  int rowHeight;
  int colWidth;

  void (*renderGrid)(const void* self);

  void (*highlightCell)(const void* self, SDL_Point clickPos);

  SDL_Point (*getTargetCoords)(const void *self_obj, SDL_Point);

  Cell* cells[10][10];

} Grid;

Cell* Cell__init(enum TerrainType type, SDL_Point position, int height, int width, SDL_Renderer* renderer);

void Cell__destroy(Cell* cell);

#endif
