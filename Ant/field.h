#ifndef FIELD_H
#define FIELD_H

#include "ant.h"
#include "cell.h"

class Field {
private:
    QVector<QVector<Cell>> playingGrid;
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
