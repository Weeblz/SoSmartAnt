#ifndef UTILITIES_H
#define UTILITIES_H

#define APPLES_COUNT 89
#define GRID_SIZE 32

struct Position {
    int x;
    int y;
    Position(int _x,int _y) : x(_x), y(_y) {}
};

enum Direction { UP, RIGHT, DOWN, LEFT };
enum Action { IDLE, FORWARD, LTURN, RTURN };

#endif // UTILITIES_H
