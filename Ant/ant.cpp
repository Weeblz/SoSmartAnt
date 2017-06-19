#include "ant.h"

Ant::Ant(Position initialLocation) : currentLocation(initialLocation),
                                     currentDirrection(RIGHT), applesEaten(0), lastAction(FORWARD) {}

void Ant::turnLeft() {
     currentDirrection = currentDirrection ? (Direction)(((int)currentDirrection-1)%4) : UP;
}

void Ant::turnRight() {
    currentDirrection = (Direction)(((int)currentDirrection+1)%4);
}

void Ant::move() {
    currentAction = changeState(checkNextCell());
    if (grid->isApple(currentLocation)) {
        grid->eatApple(currentLocation);
        applesEaten++;
    }
    switch (currentAction)
    {
    case FORWARD:
        currentLocation = grid->nextCell(currentPosition, currentDirection);
        break;
    case LEFT:
        turnLeft();
        break;
    case RIGHT:
        turnRight();
        break;
    default:
        break;
    }
}

bool Ant::checkNextCell() {
    return grid->isApple(nextCell(currentLocation, currentDirrection));
}

Action Ant::changeState(bool canSeeApple) {
    Action chosenAction;
    currentState = states[currentState.makeDecision(canSeeApple, chosenAction)];
    return chosenAction;
}


