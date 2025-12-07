//
// Created by brick on 11/26/2025.
//

#include "../include/graphics.hpp"

FFACE_Graphic::FFACE_Graphic() {
        graphic = new FFACE_Graphic_Struct;
        graphic->texture = nullptr;
        graphic->surface = nullptr;
}
bool FFACE_Graphic::FFACE_ClearGraphic() {
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
bool FFACE_Graphic::FFACE_DestroyGraphic() {

        FFACE_ClearGraphic();

        free(graphic);

        return true;
}
