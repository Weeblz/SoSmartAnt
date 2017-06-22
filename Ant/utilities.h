#ifndef UTILITIES_H
#define UTILITIES_H

#define APPLES_COUNT 89
#define GRID_SIZE 32

#define GENERATION_SIZE 100
#define NUMBER_OF_GENERATIONS 200
#define MUTATION_PROBABILITY 5
#define STATE_COUNT 7 // how many different states every ant will have

struct Position {
    int x;
    int y;
    Position() : x(0), y(0) {}
    Position(int _x,int _y) : x(_x), y(_y) {}
};

enum Direction { UP, RIGHT, DOWN, LEFT };
enum Action { IDLE, FORWARD, LTURN, RTURN };

#endif // UTILITIES_H
