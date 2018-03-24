#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "credits_scene.h"

SDL_Texture* creditsTexture = 0;
SDL_Texture* creditsBackTexture = 0;

int credits_mouseDown = 0;

void init_credits_scene() {
  // printf("init credits\n");

  // creditsTexture = load_texture("../data/ui/CreditsText.png");
  // creditsBackTexture = load_texture("../data/backgrounds/CreditsScreenfill.png");
}
