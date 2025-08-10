#include <iostream>
#include "window.h"
#include "logic.h"

int main(int argc, char* argv[]) {

    // Create the window (With the title)
    if (!initWindow("Conway's Game of Life")) {
        std::cerr << "Failed to initialize window\n";
        return 1;
    }

    world[1][1] = 1; // Example: flying cell
    world[2][2] = 1;
    world[2][3] = 1;
    world[3][1] = 1;
    world[3][2] = 1;

    // variables to control the start and the main loop
    bool inStart = true;
    bool running = true;
    SDL_Event event;

    // Main loop
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {   // Exit the program
                running = false;
            }

            if (inStart) {   // Handle start input
                handleStartInput(event);
                if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN) {
                    inStart = false;  // Start simulation
                }
            }
        }

        if (inStart) {   // Draw the start screen
            drawStartScreen();
        } else {  // Run the simulation logic
            worldUpdate(world);
            windowLogic(world);
            SDL_Delay(200);
        }

        // Delay to control the frame rate
        SDL_Delay(16);
    }

    // Destroy the window
    cleanupWindow();

    return 0;
}
