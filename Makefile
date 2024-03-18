all:
	clang++ -std=c++17 -I./include/raylib -L./lib/raylib -lraylib ./src/main.cpp ./src/grid.cpp ./src/simulation.cpp -o program
