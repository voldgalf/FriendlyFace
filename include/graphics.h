
#ifndef FFACE_GRAPHICS_H
#define FFACE_GRAPHICS_H
//
// Created by brick on 11/25/2025.
//

#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <stdlib.h>
/*
    Struct: FFACE_TextGraphic
    A struct containing TTF_Text, w and h

    Variables:
        text - TTF_Text pointer
        w  - width of text
        h - height of text
*/

/*
    Struct: FFACE_Graphic
    A struct containing SDL_FRect, and points to SDL_Texture, SDL_Surface and FFACE_TextGraphic

    Variables:
        SDL_FRect - SDL_FRect
        SDL_Texture  - SDL_Texture pointer
        SDL_Surface - SDL_Surface pointer
        FFACE_TextGraphic - FFACE_TextGraphic pointer
*/
typedef struct {
    SDL_FRect rect;
    SDL_Texture* texture;
    SDL_Surface* surface;

} FFACE_Graphic;

/**
 * Function: FFACE_CreateGraphic
 *
 * Create & returns FFACE_CreateGraphic struct.
 *
 * Returns:
 * A pointer to the created FFACE_CreateGraphic
 */
FFACE_Graphic* FFACE_CreateGraphic();


/**
 * Function: FFACE_ClearGraphic
 *
 * Clear given FFACE_CreateGraphic
 *
 * Returns:
 * true
 */
bool FFACE_ClearGraphic(FFACE_Graphic *graphic);

/**
 * Function: FFACE_DestroyGraphic
 *
 * destroys FFACE_CreateGraphic
 *
 * Returns:
 * true
 */
bool FFACE_DestroyGraphic(FFACE_Graphic *graphic);
#endif //FFACE_GRAPHICS_H
