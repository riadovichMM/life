#include "./simulation.hpp"
#include <utility> 

Simulation::Simulation(int width, int height, int cellSize){
    (*this).grid = new Grid(width, height, cellSize);
    (*this).tempGrid = new Grid(width, height, cellSize);
}

Simulation::~Simulation() {
    delete (*this).grid;
}

void Simulation::draw() {
    // (*(*this).grid).draw();
    this->grid->draw();
}

void Simulation::setCellValue(int row, int column, int value) {
    this->grid->setValue(row, column, value);
}

int Simulation::countLiveNeighbors(int row, int column) {
    int liveNeighbors = 0;
    std::vector<std::pair<int, int>> neighborOffset = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1},
        {-1, -1},
        {-1, 1},
        {1, -1},
        {1, 1}
    };


    for(std::pair<int, int> offset: neighborOffset) {
        int neighborRow = (row + offset.first + this->grid->getRows()) % this->grid->getRows();
        int neighborColumn = (column + offset.second + this->grid->getColumns()) % this->grid->getColumns();

        liveNeighbors = liveNeighbors + this->grid->getValue(neighborRow, neighborColumn);
    }
    return liveNeighbors;
}


void Simulation::update() {
    for (int row = 0; row < this->grid->getRows(); row++) {
        for (int column = 0; column < this->grid->getColumns(); column++) {
            int lifeNeighbors = this->countLiveNeighbors(row, column);
            int cellValue = this->grid->getValue(row, column);

            if (cellValue == 1) {
                if (lifeNeighbors > 3 || lifeNeighbors < 2) {
                    this->tempGrid->setValue(row, column, 0);
                } else {
                    this->tempGrid->setValue(row, column, 1); 
                }
            } else {
                if (lifeNeighbors == 3) {
                    this->tempGrid->setValue(row, column, 1);
                } else {
                    this->tempGrid->setValue(row, column, 0);
                }
            }
        }
    }
    *grid = *tempGrid;
}
