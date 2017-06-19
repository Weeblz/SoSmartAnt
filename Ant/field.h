#ifndef FIELD_H
#define FIELD_H

#include "cell.h"
#include "utilities.h"
#include <vector>
class Ant;

class Field {
private:
    std::vector<std::vector<Cell>> playingGrid;
    Position startingPoint;
    int applesLeft;

public:
    Field(Position);
    void appleEaten() { applesLeft--; }
    void eatApple(Position);
    bool isApple(Position);
    Position nextCell(Position, Direction);

private:
    void initField();
};

#endif // FIELD_H
