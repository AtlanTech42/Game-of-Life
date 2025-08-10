#include <iostream>
#include "window.hpp"

int main(int argc, char* argv[]) {
    if (!initWindow("Simulation Window")) {
        std::cerr << "Failed to initialize window\n";
        return 1;
    }

    windowLogic();

    cleanupWindow();

    return 0;
}
