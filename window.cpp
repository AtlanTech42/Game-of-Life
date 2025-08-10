#include "window.hpp"
#include <iostream>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;

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
//  In other words it draws the entire window
//===============================================
void windowLogic() {
    bool running = true;
    SDL_Event event;
    int temp1 = 0;
    int temp2 = 0;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                running = false;
        }

        if (temp1 >= WINDOW_WIDTH / 10) temp1 = 0;
        if (temp2 >= WINDOW_HEIGHT / 10) temp2 = 0;

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Clear with black
        SDL_RenderClear(renderer);

        drawSquare(temp1, temp2);
        SDL_RenderPresent(renderer);

        SDL_Delay(200);
        temp1++;
        temp2++;
    }
}
