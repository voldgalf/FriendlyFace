//
// Created by brick on 11/26/2025.
//

#ifndef FFACE_UTILITY_H
#define FFACE_UTILITY_H

#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <stdlib.h>

typedef struct {
    float x, y;
} FFACE_mouse;

/**
 * Function: FFACE_SetRendererColor
 *
 * Update SDL_Renderer's DrawColor using given SDL_Color
 *
 * Parameters:
 * renderer - given SDL_Renderer
 * color - given SDL_Color
 *
 * Returns:
 * true - completed without errors
 * false - completed with errors
 */
bool FFACE_SetRendererColor(SDL_Renderer *renderer, SDL_Color color);

/**
 * Function: FFACE_SetTextColor
 *
 * Update TTF_Text's DrawColor using given SDL_Color
 *
 * Parameters:
 * text - given TTF_Text
 * color - given SDL_Color
 *
 * Returns:
 * true - completed without errors
 * false - completed with errors
 */
bool FFACE_SetTextColor(TTF_Text *text, SDL_Color color);
#endif //FFACE_UTILITY_H
