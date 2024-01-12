#ifndef hd_h_
#define hd_h_

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "giaoDIen.h"

using namespace std;
const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 600;

SDL_Event g_even;

void draw(SDL_Renderer* renderer,int x,int y, char *s, float tiLe);
SDL_Texture* loadTexture( string path,SDL_Renderer* renderer );
#endif
