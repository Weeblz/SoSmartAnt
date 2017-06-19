#ifndef ANT_H
#define ANT_H

#include "QVector"
#include "utilities.h"
#include "state.h"
#include "field.h"

class Ant {
private:
    Position currentLocation;
    Direction currentDirrection;
    State currentState;
    Action currentAction;
    int behaviourFitness;
    int applesEaten;
    int antIntelligence;
    QVector<State> states;
    Field* grid;

public:
    Ant(Position);
    void turnLeft();
    void turnRight();
    void move();
    bool checkNextCell();
    Position getPosition() { return currentLocation; }
    Direction getDirection() { return currentDirrection; }
    Action changeState(bool);
};

#endif // ANT_H
