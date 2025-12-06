//
// Created by brick on 11/26/2025.
//

#include "../include/graphics.h"


FFACE_Graphic* FFACE_CreateGraphic() {

    FFACE_Graphic* newGraphic = malloc(sizeof (FFACE_Graphic));
    newGraphic->texture = NULL;
    newGraphic->surface = NULL;
    return newGraphic;
}

bool FFACE_ClearGraphic(FFACE_Graphic *graphic) {

    if(graphic->texture) {
        SDL_DestroyTexture(graphic->texture);
        graphic->texture = NULL;
    }

    if(graphic->surface) {
        SDL_DestroySurface(graphic->surface);
        graphic->surface = NULL;   // optional safety
    }


    return true;
}

bool FFACE_DestroyGraphic(FFACE_Graphic *graphic) {

    FFACE_ClearGraphic(graphic);

    free(graphic);

    return true;
}
