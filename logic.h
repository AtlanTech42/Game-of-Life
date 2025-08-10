// logic.h
#ifndef LOGIC_H
#define LOGIC_H

// Pixel size
const int pixelSize = 10;

// Size of the screen and the size of the world
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

const int COLS = WINDOW_WIDTH / pixelSize;
const int ROWS = WINDOW_HEIGHT / pixelSize;

extern int world[COLS][ROWS];

void worldUpdate ( int world[COLS][ROWS] );

#endif