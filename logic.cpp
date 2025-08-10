// logic.cpp
#include "logic.h"
#include <iostream>
using namespace std;

//===============================================
//  This function counts the number of alive cells around a cell
//===============================================
int aroundCount(int x, int y, int world[COLS][ROWS]) {
    int count = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue; // Skip the cell itself
            int newX = x + i;
            int newY = y + j;
            if (newX >= 0 && newX < WINDOW_WIDTH && newY >= 0 && newY < WINDOW_HEIGHT) { // if inside the world
                count += world[newX][newY];
            }
        }
    }
    return count;
}

//===============================================
//  This function figures out the logic to update the world
//===============================================
void worldUpdate ( int world[COLS][ROWS] ) {

    // Create the world copy
    int worldCopy[COLS][ROWS];

    for ( int i = 0 ; i <= COLS - 1 ; i++ ) {
        for ( int j = 0 ; j <= ROWS - 1 ; j++ ) {
            if ( world[i][j] == 1 ) {
                // If the cell is alive, check the number of alive neighbors
                int count = aroundCount(i, j, world);
                
                // Apply the rules of life
                if (count < 2 || count > 3) {
                    worldCopy[i][j] = 0; // Cell dies
                } else {
                    worldCopy[i][j] = 1; // Cell stays alive
                }
            } else {
                // If the cell is dead, check if it can come to life
                int count = aroundCount(i, j, world);
                if (count == 3) {
                    worldCopy[i][j] = 1; // Cell becomes alive
                } else {
                    worldCopy[i][j] = 0; // Cell stays dead
                }
            }
        }
    }
    
    // Update the world based on the rules
    for ( int i = 0 ; i <= COLS - 1 ; i++ ) {
        for ( int j = 0 ; j <= ROWS - 1 ; j++ ) {
            world[i][j] = worldCopy[i][j];
        }
    }
    
}
//===============================================
