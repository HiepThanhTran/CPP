#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "giaoDIen.h"

using namespace std;

void VeVat(SDL_Rect *rect, SDL_Renderer *renderer, int Ve){
    SDL_SetRenderDrawColor(renderer, 0, Ve*100, Ve*100, 255);
    SDL_RenderDrawRect(renderer, rect);
    SDL_RenderPresent(renderer);
}

