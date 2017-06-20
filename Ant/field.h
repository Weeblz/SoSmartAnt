#ifndef FIELD_H
#define FIELD_H

#include "cell.h"
#include "utilities.h"
#include "state.h"
#include "ant.h"
#include <vector>

class Field {
public:
    Ant ant;
private:
    std::vector<std::vector<Cell>> playingGrid;
    Position startingPoint;
    int applesLeft;

public:
    Field(Position);
    Field(Position, const std::vector<State>&);
    void appleEaten() { applesLeft--; }
    void eatApple(Position);
    void updateField();
    bool isApple(Position);
    int getApplesLeft() { return applesLeft; }
    Position nextCell(Position, Direction);
    std::vector<std::vector<Cell>> getPlayingGrid() { return playingGrid; }

private:
    void initField();
};

#endif // FIELD_H
