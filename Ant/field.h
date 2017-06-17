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

private:
    void initField();
};

#endif // FIELD_H
