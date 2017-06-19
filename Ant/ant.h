#ifndef ANT_H
#define ANT_H

#include "utilities.h"
#include "state.h"
#include "field.h"
#include <vector>

class Ant {
private:
    Position currentLocation;
    Direction currentDirrection;
    State currentState;
    Action currentAction;
    int applesEaten;
    std::vector<State> states;
    Field* grid;

public:
    Ant(Position);
    Ant(Position, const std::vector<State>&, Field*);
    void turnLeft();
    void turnRight();
    void move();
    bool checkNextCell();
    int getApplesEaten() { return applesEaten; }
    Position getPosition() { return currentLocation; }
    Direction getDirection() { return currentDirrection; }
    Action changeState(bool);
};

#endif // ANT_H
