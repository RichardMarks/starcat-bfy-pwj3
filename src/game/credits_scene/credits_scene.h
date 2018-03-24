#ifndef CREDITS_SCENE_H
#define CREDITS_SCENE_H

extern void init_credits_scene();
extern void destroy_credits_scene();
extern void enter_credits_scene();
extern void exit_credits_scene();
extern void update_credits_scene(float dt);
extern void render_credits_scene();

extern SDL_Texture* creditsTexture;
extern SDL_Texture* creditsBackTexture;
extern int credits_mouseDown;

#endif
