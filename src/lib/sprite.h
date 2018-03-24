#ifndef SPRITE_H
#define SPRITE_H

#define MAX_SPRITES 400
#define MAX_LAYERS 3 // BG, FG, UI
#define BG_LAYER 0
#define FG_LAYER 1
#define UI_LAYER 2

#define SPRITE_VISIBLE 0x00
#define SPRITE_HIDDEN 0xFF

typedef struct t_Sprite {
  float x;
  float y;
  float xv;
  float yv;
  void* data;
  int state;
  SDL_Texture* texture;
  SDL_Texture* texture2;
  SDL_Rect src;
  unsigned char visible;
  int layer;
  int frame;
} Sprite;


extern Sprite sprites[MAX_SPRITES * MAX_LAYERS];
extern int numSprites;

extern Sprite* spriteLayer[MAX_LAYERS][MAX_SPRITES];
extern int numSpritesByLayer[MAX_LAYERS];

extern Sprite* Sprite__init(Sprite* sprite, SDL_Texture* texture, SDL_Rect* src, int layer);
extern void Sprite__render(Sprite* sprite);
extern int Sprite__collides_with_point(Sprite* sprite, int x, int y);
extern void Sprite__change_texture(Sprite* sprite, SDL_Texture* texture, SDL_Rect* src);
extern void Sprite__add_to_layer(Sprite* sprite, int layer);

#endif
