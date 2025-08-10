// window.cpp
#include "window.h"
#include "logic.h"
#include <iostream>

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;

//===============================================
//  This functions initialises the window
//===============================================
bool initWindow(const char* title) {

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << "\n";
        return false;
    }

    window = SDL_CreateWindow(
        title,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_SHOWN
    );

    if (!window) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << "\n";
        SDL_Quit();
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << "\n";
        SDL_DestroyWindow(window);
        SDL_Quit();
        return false;
    }

    return true;
}

//===============================================
//  This functions cleans the window by destroying it
//===============================================
void cleanupWindow() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

//===============================================
//  This functions draws a square in the coords
//===============================================
void drawSquare(int x, int y) {
    SDL_Rect rect = { x * 10, y * 10, 10, 10 };
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
}

//===============================================
//  This function runs the main logic of the window
//
//  In other words it draws the entire world
//===============================================
void windowLogic( int world[WINDOW_WIDTH][WINDOW_HEIGHT] ) {

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Clear with black
    SDL_RenderClear(renderer);

    for ( int i = 0 ; i <= WINDOW_WIDTH ; i++ ) {
        for ( int j = 0 ; j <= WINDOW_HEIGHT ; j++ ) {
            drawSquare( i * world[i][j], j * world[i][j]  );
        }
    }
    
    SDL_RenderPresent(renderer);

}
