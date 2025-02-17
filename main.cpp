# include <iostream>
# include <SDL.h>
# include <SDL_image.h>
# include "SDL_utils.h"
# include <string>

const int WIDTH = 800;
const int HEIGHT = 600;
const char* TITLE = "keoDepTrai";

SDL_Texture* loadTexture(std::string path , SDL_Renderer* renderer);

int main(int argc , char* argv[]){
    SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window , renderer , WIDTH , HEIGHT , TITLE);
    SDL_Texture* backGround = loadTexture("kaneki.jpg" , renderer);
    SDL_RenderCopy(renderer , backGround , NULL , NULL);
    SDL_RenderPresent(renderer);

    SDL_Texture* noi = loadTexture("kaneki.jpg" , renderer);
    std::cout << "no";
    SDL_Rect noiRect;
    SDL_QueryTexture(noi , NULL , NULL , &noiRect.w , &noiRect.h);
    noiRect.x = 100;
    noiRect.y = 100;
    SDL_RenderCopy(renderer , noi , NULL , &noiRect);
    SDL_RenderPresent(renderer);
    char* base_path = SDL_GetBasePath();
    if (base_path) {
        std::cout << "Current working directory: " << base_path << std::endl;
        SDL_free(base_path);
    }
    waitUntilKeyPressed();
    QUIT_SDL(window , renderer);
    SDL_Quit();
    return 0;
}
SDL_Texture* loadTexture(std::string path , SDL_Renderer* renderer){
    SDL_Texture* newTexture = nullptr;
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr){
        std::cout << "Unable to load image " << path << " " << "SDL_image Error: " << SDL_GetError() << std::endl;
    }
    else{
        newTexture = SDL_CreateTextureFromSurface(renderer , loadedSurface);
        if (newTexture == nullptr){
            std::cout << "Unable to create texture from" << path << " SDL Error: " << SDL_GetError() << std::endl;
        }
        SDL_FreeSurface(loadedSurface);
    }
    return newTexture;
}




