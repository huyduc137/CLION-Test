
#ifndef SDL_UTILS_H
#define SDL_UTILS_H

#include <SDL.h>

void initSDL(SDL_Window*& window, SDL_Renderer*& renderer, const int WIDTH, const int HEIGHT, const char* WINDOW_TITLE);
void waitUntilKeyPressed();
void QUIT_SDL(SDL_Window* window, SDL_Renderer* renderer);

#endif //SDL_UTILS_H
