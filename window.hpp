// window.hpp
#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SDL2/SDL.h>

// Declare extern so other files can access these
extern SDL_Window* window;
extern SDL_Renderer* renderer;

// Declare your init and cleanup functions
bool initWindow(const char* title);
void cleanupWindow();
void drawSquare(int x, int y);
void windowLogic();

#endif
