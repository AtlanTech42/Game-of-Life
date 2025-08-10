#include <iostream>
#include "window.h"
#include "logic.h"

int main(int argc, char* argv[]) {
    // Create the window
    
    if (!initWindow("Simulation Window")) {
        std::cerr << "Failed to initialize window\n";
        return 1;
    }

    // Create the world
    int world[WINDOW_WIDTH][WINDOW_HEIGHT];

    world[1][1] = 1; // Example: flying cell
    world[2][2] = 1;
    world[2][3] = 1;
    world[3][1] = 1;
    world[3][2] = 1;

    bool running = true;
    SDL_Event event;
    while (running) {

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                running = false;
        }

        worldUpdate(world);

        windowLogic(world);

        SDL_Delay(200);
        
    }

    // Destroy the window
    cleanupWindow();

    return 0;
}
