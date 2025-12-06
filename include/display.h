//
// Created by brick on 11/25/2025.
//

#ifndef FFACE_DISPLAY_H
#define FFACE_DISPLAY_H

#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <stdlib.h>
/*
    Struct: FFACE_Display
    A struct that holds priority pointers

*/
typedef struct {
    SDL_Window* window;
    SDL_Renderer* renderer;
    int w,h;
} FFACE_Display;

/**
 * Function: FFACE_CreateDisplay
 *
 * Create & returns FFACE_Display struct.
 *
 *
 * Returns:
 * A pointer to the created FFACE_Display
 */
FFACE_Display* FFACE_CreateDisplay();

#endif //FFACE_DISPLAY_H
