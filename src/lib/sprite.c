#include "game.h"
#include "sprite.h"

Sprite sprites[MAX_SPRITES * MAX_LAYERS];
Sprite* spriteLayer[MAX_LAYERS][MAX_SPRITES] = {0};
int numSprites = 0;
int numSpritesByLayer[MAX_LAYERS] = {0};

Sprite* Sprite__init(Sprite* sprite, SDL_Texture* texture, SDL_Rect* src, int layer) {
  memset(sprite, 0, sizeof(Sprite));
  sprite->texture = texture;

  sprite->frame = 0;
  sprite->texture2 = 0;
  sprite->visible = SPRITE_VISIBLE;

  if (src) {
    sprite->src.x = src->x;
    sprite->src.y = src->y;
    sprite->src.w = src->w;
    sprite->src.h = src->h;
  } else {
    int w, h;
    SDL_QueryTexture(sprite->texture, 0, 0, &w, &h);
    sprite->src.x = 0;
    sprite->src.y = 0;
    sprite->src.w = w;
    sprite->src.h = h;
  }

  Sprite__add_to_layer(sprite, layer);

  return sprite;
}

void Sprite__change_texture2(Sprite* sprite, SDL_Texture* texture, SDL_Rect* src) {
  sprite->frame = 1;
}

void Sprite__change_texture(Sprite* sprite, SDL_Texture* texture, SDL_Rect* src) {
  sprite->texture = texture;
  if (src) {
    sprite->src.x = src->x;
    sprite->src.y = src->y;
    sprite->src.w = src->w;
    sprite->src.h = src->h;
  } else {
    int w, h;
    SDL_QueryTexture(sprite->texture, 0, 0, &w, &h);
    sprite->src.x = 0;
    sprite->src.y = 0;
    sprite->src.w = w;
    sprite->src.h = h;
  }
}

SDL_Rect dst;
void Sprite__render(Sprite* sprite) {
  if (sprite->visible == SPRITE_HIDDEN) {
    return;
  }

  dst.x = (int)sprite->x;
  dst.y = (int)sprite->y;

  SDL_Texture* texture = sprite->frame ? sprite->texture2 : sprite->texture;
  texture = !texture ? sprite->texture : texture;

  int w, h;
  SDL_QueryTexture(texture, 0, 0, &w, &h);

  sprite->src.x = 0;
  sprite->src.y = 0;
  sprite->src.w = w;
  sprite->src.h = h;

  dst.w = sprite->frame ? w / 2 : w;
  dst.h = sprite->frame ? h / 2 : h;
  if (sprite->frame) {
    dst.x += dst.w / 2;
    dst.y += dst.h / 2;
  }
  SDL_RenderCopy(mainRendererPtr, texture, &sprite->src, &dst);
}

int Sprite__collides_with_point(Sprite* sprite, int x, int y) {
  if (
    x >= (int)sprite->x && x <= (int)(sprite->x + sprite->src.w) &&
    y >= (int)sprite->y && y <= (int)(sprite->y + sprite->src.h)) {
    return 1;
  }
  return 0;
}

void Sprite__add_to_layer(Sprite* sprite, int layer) {
  sprite->layer = layer;
  spriteLayer[layer][numSpritesByLayer[layer]] = sprite;
  numSpritesByLayer[layer] += 1;
}
