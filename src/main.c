#include "SDL.h"
#include "include/touch_screen.h"
#include "include/plataforma.h"
#include <stdio.h>

int main (int argc, char *argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    infoSistema sys = detectar();

    printf("SO: %s (%s)\n", sys.operacional, sys.arquitetura);

    int windowWidth, windowHeight;
    Uint32 flags = SDL_WINDOW_SHOWN;

    if (sys.tipo == DISPOSITIVO_MOBILE)
    {
        SDL_DisplayMode dm;
        SDL_GetCurrentDisplayMode(0, &dm);

        windowWidth = dm.w;
        windowHeight = dm.h;

        flags |= SDL_WINDOW_FULLSCREEN | SDL_WINDOW_BORDERLESS;
    } else {
        windowWidth = 360;
        windowHeight = 640;
        flags |= SDL_WINDOW_RESIZABLE;
    }


    SDL_Window* window = SDL_CreateWindow(
            "Meu jogo", 
            SDL_WINDOWPOS_CENTERED, 
            SDL_WINDOWPOS_CENTERED, 
            windowWidth, windowHeight, flags
    );

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    int running = 1;
    SDL_Event event;

    while (running) {
  //      while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) running = 0;
  //      }

        SDL_SetRenderDrawColor(renderer, 20, 20, 40, 255);
        SDL_RenderClear(renderer);
        
        SDL_Rect rect = { 130, 270, 100, 100 };

        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        SDL_RenderFillRect(renderer, &rect);

        SDL_RenderPresent(renderer);

        touch();;
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
