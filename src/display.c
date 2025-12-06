//
// Created by brick on 11/26/2025.
//

#include "../include/display.h"
//
// Created by brick on 11/25/2025.
//


FFACE_Display* FFACE_CreateDisplay() {
    FFACE_Display* newDisplay = malloc(sizeof (FFACE_Display));

    newDisplay->window = NULL;
    newDisplay->renderer = NULL;
    newDisplay->w = 0;
    newDisplay->h = 0;
    return newDisplay;
}
