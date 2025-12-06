//
// Created by brick on 11/26/2025.
//

#include "../include/graphics.hpp"


FFACE_Graphic* FFACE_CreateGraphic() {

    FFACE_Graphic* newGraphic = new FFACE_Graphic;
    newGraphic->texture = nullptr;
    newGraphic->surface = nullptr;
    return newGraphic;
}

bool FFACE_ClearGraphic(FFACE_Graphic *graphic) {

    if(graphic->texture) {
        SDL_DestroyTexture(graphic->texture);
        graphic->texture = nullptr;
    }

    if(graphic->surface) {
        SDL_DestroySurface(graphic->surface);
        graphic->surface = nullptr;   // optional safety
    }


    return true;
}

bool FFACE_DestroyGraphic(FFACE_Graphic *graphic) {

    FFACE_ClearGraphic(graphic);

    free(graphic);

    return true;
}
