//
// Created by brick on 11/26/2025.
//

#include "../include/utility.h"

bool FFACE_SetRendererColor(SDL_Renderer *renderer, SDL_Color color) {

    if(!SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a)) {
        return false;
    }
    return true;

}