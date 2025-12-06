#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include "include/display.hpp"
#include "include/graphics.hpp"
#include "include/utility.hpp"
#include <pthread.h>
#include <iostream>

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
    return true;
}


int main()
{
    std::cout << "-Initializing SDL3-\n";

    if (!SDL_Init(SDL_INIT_EVENTS)) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << "\n";
        return 1;
    }

    display = FFACE_CreateDisplay();

    std::cout << "-Creating Window-\n";

    display->window = SDL_CreateWindow("FriendlyFace", 480, 480, SDL_WINDOW_RESIZABLE);
    if(!display->window) {
        std::cout << SDL_GetError() << "\n";
    }

    printf("-Creating Renderer-\n");

    display->renderer = SDL_CreateRenderer(display->window, NULL);
    if(!display->renderer) {
        std::cout << SDL_GetError() << "\n";
    }

    bool running = true;

    FFACE_Graphic* faceGraphic = FFACE_CreateGraphic();
    FFACE_UpdateWindowSize();
    do {

        if(!faceGraphic->texture) {
            faceGraphic->texture = IMG_LoadTexture(display->renderer, "../imgs/WorkerFace_Default.png");
            if(!faceGraphic->texture) {
                errorPopUp();
            }
        }

        float scale = 0.75f * display->h / faceGraphic->texture->h;

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
                    faceGraphic->texture = nullptr;
                }
            }
            if(event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }

        //Clean Up
        //FFACE_ClearGraphic(faceGraphic);

       SDL_Delay(40);
    } while(running);

    FFACE_DestroyGraphic(faceGraphic);
    SDL_Quit();

    return 0;
}
