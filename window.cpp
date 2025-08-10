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

//===============================================
//  This functions cleans the window by destroying it
//===============================================
void cleanupWindow() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
//===============================================

//===============================================
//  This functions draws a square in the coords
//
//  x and y, and if the cell is alive or not
//  (alive = 1, dead = 0)
//===============================================
void drawSquare(int x, int y, int alive) {
    SDL_Rect rect = { x * 10, y * 10, 10, 10 };
    SDL_SetRenderDrawColor(renderer, 255 * alive, 255 * alive, 255 * alive, 255);
    SDL_RenderFillRect(renderer, &rect);
}
//===============================================

//===============================================
//  This functions handles the start input at the start
//===============================================
int cursorX = 0;
int cursorY = 0;
int world[COLS][ROWS] = {};  // Initialized to 0 (dead)

void handleStartInput(SDL_Event& e) {

    if (e.type == SDL_MOUSEBUTTONDOWN) {
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);
        int gridX = mouseX / pixelSize;
        int gridY = mouseY / pixelSize;
        if (gridX >= 0 && gridX < COLS && gridY >= 0 && gridY < ROWS) {
            world[gridX][gridY] = !world[gridX][gridY];  // Toggle cell
            cursorX = gridX;
            cursorY = gridY;
        }
    }
}
//===============================================

//===============================================
//  This functions draws the start screen
//===============================================
void drawStartScreen() {
    // Clear screen (black)
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Draw alive cells (white)
    for (int i = 0; i < COLS; ++i) {
        for (int j = 0; j < ROWS; ++j) {
            if (world[i][j]) {
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                SDL_Rect rect = { i * pixelSize, j * pixelSize, pixelSize, pixelSize };
                SDL_RenderFillRect(renderer, &rect);
            }
        }
    }

    // Draw green cursor outline
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_Rect cursorRect = { cursorX * pixelSize, cursorY * pixelSize, pixelSize, pixelSize };
    SDL_RenderDrawRect(renderer, &cursorRect);

    SDL_RenderPresent(renderer);

    // Draw grid lines
    SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
    for (int x = 0; x <= WINDOW_WIDTH; x += pixelSize)
        SDL_RenderDrawLine(renderer, x, 0, x, WINDOW_HEIGHT);
    for (int y = 0; y <= WINDOW_HEIGHT; y += pixelSize)
        SDL_RenderDrawLine(renderer, 0, y, WINDOW_WIDTH, y);

}
//===============================================

//===============================================
//  This function runs the main logic of the window
//
//  In other words it draws the entire world
//===============================================
void windowLogic( int world[COLS][ROWS] ) {

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Clear with black
    SDL_RenderClear(renderer);

    for ( int i = 0 ; i <= COLS ; i++ ) {
        for ( int j = 0 ; j <= ROWS ; j++ ) {
            drawSquare( i, j, world[i][j] );
        }
    }
    
    SDL_RenderPresent(renderer);

}
//===============================================
