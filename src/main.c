#include <stdlib.h>
#include "game.h"

int main (int argc, char* argv[]) {
  Game game;
  atexit(destroy_game);
  init_game(&game, argc, argv);
  return run_game(&game);
}
