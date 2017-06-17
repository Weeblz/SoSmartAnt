#ifndef ANT_H
#define ANT_H

#include "QVector"
#include "utilities.h"
#include "state.h"

class Ant {
private:
    Position currentLocation;
    Direction currentDirrection;
    Action lastAction;
    int applesEaten;
    int antIntelligence;
    QVector<State> states;
public:
    Ant(Position);
    void turnLeft();
    void turnRight();
    Position getPosition() { return currentLocation; }
    Direction getDirection() { return currentDirrection; }
};

#endif // ANT_H
