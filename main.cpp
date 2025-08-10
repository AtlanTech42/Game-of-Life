#include <SDL2/SDL.h>
#include <iostream>
using namespace std;

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

// Create a window
SDL_Window* window = SDL_CreateWindow(
    "Simulation Window",
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    WINDOW_WIDTH,
    WINDOW_HEIGHT,
    SDL_WINDOW_SHOWN
);

// Create a renderer
SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

//===============================================
//  This functions draws a square in the coords
//
//===============================================
int drawQuare( int x, int y) {

    // Create the quare at the right place
    SDL_Rect rect = { x * 10, y * 10, 10, 10 };

    // Draw the right color quare
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &rect);

    return 0;
}

int main(int argc, char* argv[]) {
    cout << "test";
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << "\n";
        return 1;
    }

    // Makes sure there is a window running
    if (!window) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << "\n";
        SDL_Quit();
        return 1;
    }

    // Main loop
    bool running = true;
    SDL_Event event;

    int temp1 = 0;
    int temp2 = 0;

    // The loop to run the entire code
    while (running) {
        // Handle event to quit the app
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;    // Leave the loop
            }
        }
        
        if ( temp1 >= WINDOW_WIDTH / 10 ) {
            temp1 = 0;
        }
        if ( temp2 >= WINDOW_WIDTH / 10 ) {
            temp2 = 0;
        }

        // Clear the screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // black
        SDL_RenderClear(renderer);

        // Draw the square
        drawQuare( temp1, temp2 );
        
        // Draw the screen
        SDL_RenderPresent(renderer);

        SDL_Delay(200);

        temp1 += 1;
        temp2 += 1;

    }

    // Cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}