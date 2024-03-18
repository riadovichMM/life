#pragma once
#include "./grid.hpp"


// Класс симулятор создает объект сетки (Grid) и содержит правила симуляции Жизни Конвея манипулируя сеткой 
class Simulation {

    private:
        Grid *grid;
        Grid *tempGrid;
    public:
        Simulation(int width, int height, int cellSize);
        ~Simulation();
        void draw();
        void setCellValue(int row, int column, int value);
        int countLiveNeighbors(int row, int column);
        void update();
};