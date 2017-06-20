#include "ant.h"
#include "evolution.h"
#include "field.h"
#include <iostream>

Ant::Ant() {}

Ant::Ant(Position initialLocation, Field* _grid) : currentLocation(initialLocation),
                                     currentDirrection(RIGHT), applesEaten(0), currentAction(FORWARD), grid(_grid)
{
    Evolution evolution;
    states = evolution.evolve();
}

Ant::Ant(Position _currentLocation, const std::vector<State>& _states, Field* _grid) :
                currentLocation(_currentLocation), states(_states),
                currentDirrection(RIGHT), applesEaten(0), currentAction(FORWARD),
                grid(_grid), currentState(_states.front()) {}

void Ant::turnLeft() {
     currentDirrection = currentDirrection ? (Direction)(((int)currentDirrection-1)%4) : UP;
}

void Ant::turnRight() {
    currentDirrection = (Direction)(((int)currentDirrection+1)%4);
}

void Ant::move() {
    currentAction = changeState(checkNextCell());
    //std::cout << currentDirrection << std::endl;
    if (grid->isApple(currentLocation)) {
        grid->eatApple(currentLocation);
        applesEaten++;
    }
    switch (currentAction)
    {
    case FORWARD:
        currentLocation = grid->nextCell(currentLocation, currentDirrection);
        break;
    case LTURN:
        turnLeft();
        break;
    case RTURN:
        turnRight();
        break;
    default:
        break;
    }
}

bool Ant::checkNextCell() {
    return grid->isApple(grid->nextCell(currentLocation, currentDirrection));
}

Action Ant::changeState(bool canSeeApple) {
    Action chosenAction;
    currentState = states[currentState.makeDecision(canSeeApple, chosenAction)];
    return chosenAction;
}


