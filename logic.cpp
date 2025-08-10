// logic.cpp
#include "logic.h"
#include <iostream>
using namespace std;

int timer = 0;

//===============================================
//  This function figures out the logic to update the world
//===============================================
void worldUpdate ( int world[WINDOW_WIDTH][WINDOW_HEIGHT] ) {

    for ( int i = 0 ; i <= (WINDOW_WIDTH / pixelSize) - 1 ; i++ ) {
        for ( int j = 0 ; j <= (WINDOW_HEIGHT / pixelSize) - 1 ; j++ ) {
            if ( timer == 1 ) {
                world[i][j] = (i%2) * (j%2);
            }else {
                world[i][j] = (i%3) * (j%3);
            }
            
        }
    }

    if ( timer == 1 ) {
        timer = 0;
    } else {
        timer = 1;
    }

}