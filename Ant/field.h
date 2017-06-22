#ifndef FIELD_H
#define FIELD_H

#include "cell.h"
#include "utilities.h"
#include "state.h"
#include "ant.h"
#include <vector>

class Field {
    friend class Ant;
public:
    Ant ant;
private:
    std::vector<std::vector<Cell>> playingGrid;
    Position startingPoint;
    int applesLeft;
    int maxAntScore;

public:
    Field(Position);
    Field(Position, const std::vector<State>&);
    void operator=(const Field&);
    void appleEaten() { applesLeft--; }
    void eatApple(Position);
    void updateField();
    void initField();
    bool isApple(Position);
    int getApplesLeft() { return applesLeft; }
    int getMaxAntScore() { return maxAntScore; }
    Position nextCell(Position, Direction);
    std::vector<std::vector<Cell>> getPlayingGrid() { return playingGrid; }

};

#endif // FIELD_H
