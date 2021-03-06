#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "scene.h"
#include "credits_scene.h"
#include "title_scene.h"

void exit_credits_scene() {
  printf("exiting credits scene\n");
  currentScenePtr->id = 0;
  currentScenePtr->init = &init_title_scene;
  currentScenePtr->destroy = &destroy_title_scene;
  currentScenePtr->enter = &enter_title_scene;
  currentScenePtr->exit = &exit_title_scene;
  currentScenePtr->update = &update_title_scene;
  currentScenePtr->render = &render_title_scene;
  currentScenePtr->enter();
}
