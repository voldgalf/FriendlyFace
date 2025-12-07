#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include "include/display.hpp"
#include "include/graphics.hpp"
#include "include/utility.hpp"
#include <pthread.h>
#include <iostream>
#include <fstream>
#include "include/inipp.h"

FFACE_Display* display;
SDL_Event event;

SDL_Color WHITE = {.r=255, .g=255, .b=255, .a=255};
SDL_Color BLACK = {.r=0, .g=0, .b=0, .a=255};

void errorPopUp() {
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "ERROR", SDL_GetError(), display->window);
}

void errorPopUp(const std::string& str) {
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "ERROR", str.c_str(), display->window);
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
    display->window = SDL_CreateWindow("FriendlyFace", 480, 640, SDL_WINDOW_RESIZABLE);
    if(!display->window) {
        std::cout << SDL_GetError() << "\n";
    }

    printf("-Creating Renderer-\n");
    display->renderer = SDL_CreateRenderer(display->window, NULL);
    if(!display->renderer) {
        std::cout << SDL_GetError() << "\n";
    }

    bool running = true;

    FFACE_Graphic faceGraphic;

    FFACE_UpdateWindowSize();


    inipp::Ini<char> ini;

    std::ifstream iniStream("../config.ini");

    if(!iniStream.is_open()) {
        std::cout << "config.ini does NOT exist\n";
        errorPopUp("config.ini does NOT exist");
        return -1;
    }

    ini.parse(iniStream);

    std::string currentEmotion = "default";
    std::string faceURL;
    do {

        if(!faceGraphic.graphic->texture) {
            inipp::get_value(ini.sections["EMOTION_URLS"], currentEmotion, faceURL);
            faceURL = "../imgs/" + faceURL;
            faceGraphic.graphic->texture = IMG_LoadTexture(display->renderer, faceURL.c_str());
            if(!faceGraphic.graphic->texture) {
                errorPopUp();
                return -1;
            }
        }

        //SDL_SetTextureColorMod(faceGraphic.graphic->texture, 255, 0, 0);

        float scale = 0.75f * display->h / faceGraphic.graphic->texture->h;

        faceGraphic.graphic->rect.w = faceGraphic.graphic->texture->w * scale;
        faceGraphic.graphic->rect.h = faceGraphic.graphic->texture->h * scale;

        faceGraphic.graphic->rect.x = (display->w - faceGraphic.graphic->rect.w) / 2;
        faceGraphic.graphic->rect.y = (display->h - faceGraphic.graphic->rect.h) / 2;

        FFACE_SetRendererColor(display->renderer, BLACK);

        SDL_RenderClear(display->renderer);

        FFACE_SetRendererColor(display->renderer, WHITE);

        if(!SDL_RenderTexture(display->renderer, faceGraphic.graphic->texture, NULL, &faceGraphic.graphic->rect)) {
            errorPopUp();
            return -1;
        }

        SDL_FlushRenderer(display->renderer);
        SDL_RenderPresent(display->renderer);

        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_EVENT_WINDOW_RESIZED) {
                FFACE_UpdateWindowSize();
                if(faceGraphic.graphic->texture) {
                    SDL_DestroyTexture(faceGraphic.graphic->texture);
                    faceGraphic.graphic->texture = nullptr;
                }
            }
            if(event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }

       SDL_Delay(40);
    } while(running);

    faceGraphic.FFACE_DestroyGraphic();
    SDL_Quit();

    return 0;
}