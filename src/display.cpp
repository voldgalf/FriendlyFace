//
// Created by brick on 11/26/2025.
//

#include "../include/display.hpp"
//
// Created by brick on 11/25/2025.
//


FFACE_Display* FFACE_CreateDisplay() {
    FFACE_Display* newDisplay = new FFACE_Display;

    newDisplay->window = nullptr;
    newDisplay->renderer = nullptr;
    newDisplay->w = 0;
    newDisplay->h = 0;
    return newDisplay;
}
