#pragma once
#include <vector>


// Класс сетка может устанавливать значения и все она не содержит логики самой симуляции
class Grid
{
    private:
        int rows;
        int columns;
        int cellSize;
        std::vector<std::vector<int>> cells;

        bool isWithinBounds(int row, int column);
    public:
        Grid(int width, int height, int cellSize);
        void draw();
        void setValue(int row, int column, int value);
        int getValue(int row, int column);
        int getRows();
        int getColumns();
        void fillRandom();
};
