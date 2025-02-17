//
// Created by ADMIN on 2/17/2025.
//

#include <iostream>
#include "SDL_utils.h"

void initSDL(SDL_Window*& window , SDL_Renderer*& renderer , const int WIDTH , const int HEIGHT , const char* WINDOW_TITLE){
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
        std::cerr << "SDL could not initialize! SDL_ERROR" << SDL_GetError() << std::endl;
    }
    window = SDL_CreateWindow(WINDOW_TITLE , SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED ,
                                          WIDTH , HEIGHT , SDL_WINDOW_SHOWN);
    if (window == nullptr){
        std::cerr << "window could not be create!" << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
    renderer = SDL_CreateRenderer(window , -1 , SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr){
        std::cerr << "renderer could not be create!" << SDL_GetError() << std::endl;
        SDL_DestroyRenderer(renderer);
        SDL_Quit();
    }
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear"); // Thiết lập chất lượng scaling
    SDL_RenderSetLogicalSize(renderer, WIDTH, HEIGHT);        // Thiết lập kích thước logic
}
void waitUntilKeyPressed(){
    bool running = true;
    SDL_Event event;
    while(running){
        while(SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT || event.type == SDL_KEYDOWN) return;
        }
        SDL_Delay(100);
    }
}
void QUIT_SDL(SDL_Window* window , SDL_Renderer* renderer){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
