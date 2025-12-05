#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL3/SDl.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3_image/SDL_image.h>
#include "include/display.h"
#include "include/graphics.h"
#include "include/utility.h"

FFACE_Display* display;
SDL_Event event;

SDL_Color WHITE = {.r=255, .g=255, .b=255, .a=255};
SDL_Color BLACK = {.r=0, .g=0, .b=0, .a=255};

void errorPopUp() {
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "ERROR", SDL_GetError(), display->window);
}

bool FFACE_UpdateWindowSize() {
    if(!SDL_GetCurrentRenderOutputSize(display->renderer,&display->w, &display->h)) {
        errorPopUp();
    }
}


int main()
{
    printf("Initializing SDL3");

    if (!SDL_Init(SDL_INIT_EVENTS)) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    display = FFACE_CreateDisplay();

    printf("Creating Window\n");
    display->window = SDL_CreateWindow("My Game", 480, 480, SDL_WINDOW_RESIZABLE);
    if(!display->window) {
        printf("%s\n", SDL_GetError());
    }

    printf("Creating Renderer\n");
    display->renderer = SDL_CreateRenderer(display->window, NULL);
    if(!display->renderer) {
        printf("%s\n", SDL_GetError());
    }

    TTF_Init();

    printf("Creating Text FFACE\n");
    display->textEngine = TTF_CreateRendererTextEngine(display->renderer);

    if(!display->textEngine) {
        printf("%s\n", SDL_GetError());
    }

    bool running = true;

    FFACE_Graphic* faceGraphic = FFACE_CreateGraphic();
    FFACE_UpdateWindowSize();
    do {

        //SDL_SetTextureColorMod(faceGraphic->texture, GOLD.r, GOLD.g, GOLD.b);

        if(!faceGraphic->texture) {
            faceGraphic->texture = IMG_LoadTexture(display->renderer, "C:\\GroundFaller\\Worker_Icon.png");
        }
        float scale = 0.70f * display->h / faceGraphic->texture->h;

        faceGraphic->rect.w = faceGraphic->texture->w * scale;
        faceGraphic->rect.h = faceGraphic->texture->h * scale;

        faceGraphic->rect.x = (display->w - faceGraphic->rect.w) / 2;
        faceGraphic->rect.y = (display->h - faceGraphic->rect.h) / 2;
        FFACE_SetRendererColor(display->renderer, BLACK);

        SDL_RenderClear(display->renderer);

        FFACE_SetRendererColor(display->renderer, WHITE);

        //SDL_RenderRect(display->renderer, &faceGraphic->rect);

        if(!SDL_RenderTexture(display->renderer, faceGraphic->texture, NULL, &faceGraphic->rect)) {
            errorPopUp();
        }

        SDL_FlushRenderer(display->renderer);
        SDL_RenderPresent(display->renderer);

        //events
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_EVENT_WINDOW_RESIZED) {
                FFACE_UpdateWindowSize();
                if(faceGraphic->texture) {
                    SDL_DestroyTexture(faceGraphic->texture);
                    faceGraphic->texture = NULL;
                }
            }
        }

        //Clean Up
        //FFACE_ClearGraphic(faceGraphic);

       SDL_Delay(40);
    } while(running);

    FFACE_DestroyGraphic(faceGraphic);

    return 0;
}
