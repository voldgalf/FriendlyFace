//
// Created by brick on 11/26/2025.
//

#include "../include/graphics.h"


FFACE_Graphic* FFACE_CreateGraphic() {

    FFACE_Graphic* newGraphic = malloc(sizeof (FFACE_Graphic));
    FFACE_TextGraphic* newTextGraphic = malloc(sizeof (FFACE_TextGraphic));

    newGraphic->texture = NULL;
    newGraphic->surface = NULL;
    newGraphic->textGraphic = newTextGraphic;
    newGraphic->textGraphic->text = NULL;
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

    if (graphic->textGraphic && graphic->textGraphic->text) {
        TTF_DestroyText(graphic->textGraphic->text);
        graphic->textGraphic->text = NULL;   // optional safety
    }

    return true;
}

bool FFACE_DestroyGraphic(FFACE_Graphic *graphic) {

    FFACE_ClearGraphic(graphic);

    free(graphic->textGraphic);

    free(graphic);

    return true;
}
