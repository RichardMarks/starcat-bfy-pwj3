#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "xorshift.h"

// portrait
#if 0
#define SCREEN_WIDTH 270
#define SCREEN_HEIGHT 480
#else
// landscape
#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 270
#endif

#define GAME_TITLE "Starcat and the Battle for Yarnia :: PixelWeekendJam #3 - 03/23/2018"

extern SDL_Window* mainWindowPtr;
extern SDL_Renderer* mainRendererPtr;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

typedef struct t_Input {
  unsigned char up;
  unsigned char down;
  unsigned char left;
  unsigned char right;
  unsigned char quit;
  unsigned char confirm;
  unsigned char cancel;
  unsigned char padding;
} Input;

typedef struct t_Mouse {
  int x;
  int y;
  unsigned char state;
} Mouse;

/*
  a simple structure to hold game-related information
*/
typedef struct Game {
  /* number of arguments passed on the command line. (includes the program itself as the 0th element) */
  int cmdLineCount;

  /* actual array of arguments passed on the command line. program name is the 0th element */
  char** cmdLine;

  /* current game state */
  int gameState;

  int paused;
  float timeScale;

  Input inputs;
  Mouse mouse;
} Game;

/*
  global pointer to the game instance that has been init by init_game()
  destroy_game() will use this to clean up when the program's main() exits.
*/
extern Game* currentGamePtr;

extern int init_game(Game* gamePtr, int cmdLineCount, char** cmdLine);
extern int run_game(Game* gamePtr);
extern void destroy_game();

/* asset loaders */
extern SDL_Texture* load_texture(char* filename);
extern TTF_Font* load_font(char* filename, int fontSize);
extern Mix_Music* load_music(char* filename);
extern Mix_Chunk* load_sfx(char* filename);

#define kill_texture(t){if(t){SDL_DestroyTexture(t);t=0;}}
#define kill_font(f){if(f){TTF_CloseFont(f);f=0;}}
#define kill_music(m){if(m){Mix_FreeMusic(m);m=0;}}
#define kill_sfx(s){if(s){Mix_FreeChunk(s);s=0;}}

#endif
