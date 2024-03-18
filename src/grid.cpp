#include <iostream>
#include <vector>
#include  <cstdlib>
#include "../include/raylib/raylib.h"
#include "./grid.hpp"

Grid::Grid(int width, int height, int cellSize) {
    (*this).rows = height / cellSize;
    (*this).columns = width / cellSize;
    (*this).cellSize = cellSize;
    std::vector<std::vector<int>> cells;

    int row = 0;
    while (row < this->rows) {
        int column = 0;
        std::vector<int> vectorRow;
        while (column < this->columns) {
            vectorRow.push_back(0);
            column++;
        }
        cells.push_back(vectorRow);
        row++;
    }

    (*this).cells = cells;

    this->fillRandom();
}

void Grid::draw() {
    int row = 0;
    while (row < this->rows) {
        int column = 0;
        while (column < this->columns) {
            Color color = this->cells[row][column] ? (Color){0, 255, 0, 255} : (Color){55, 55, 55, 255};
            DrawRectangle(column * this->cellSize, row * this->cellSize, this->cellSize - 1, this->cellSize - 1, color);
            column++;
        }
        row++;
    }
}

void Grid::setValue(int row, int column, int value) {
    if (this->isWithinBounds(row, column)) {
        (*this).cells[row][column] = value;
    }
}

int Grid::getValue(int row, int column) {
    if (this->isWithinBounds(row, column)) {
        return this->cells[row][column];
    }
    return 0;
}

bool Grid::isWithinBounds(int row, int column) {
    if (row >= 0 && row < rows && column >= 0 && column < columns) {
        return true;
    }
    return false;
}

int Grid::getRows() {
    return this->rows;
}

int Grid::getColumns() {
    return this->columns;
}

void Grid::fillRandom() {
    for (int row = 0; row < this->rows; row++) {
        bool flag = false;
        for (int column = 0; column < this->columns; column++) {
            this->cells[row][column] = std::rand() % 2 == 0 ? 1 : 0;
        }
    }
}
