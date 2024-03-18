
#include <iostream>
#include "../include/raylib/raylib.h"
#include "./simulation.hpp"


int main() {
    Color color = {30, 30, 30, 255};
    const int WINDOW_WIDTH = 750;
    const int WINDOW_HEIGHT = 750;
    const int CELL_SIZE = 25;
    int fps = 12;

    Simulation *simulation = new Simulation(WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE);

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Life");
    SetTargetFPS(fps);

    while (WindowShouldClose() == false) {
        // event handling

        // update state
        simulation->update();
        // drawing
        BeginDrawing();
        ClearBackground(color);
        (*simulation).draw();
        EndDrawing();
    }
    CloseWindow();
    delete simulation;
    return 0;
}

