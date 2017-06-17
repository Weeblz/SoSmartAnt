#include "ant.h"

Ant::Ant(Position initialLocation) : currentLocation(initialLocation),
                                     currentDirrection(RIGHT), applesEaten(0), lastAction(FORWARD) {}

void Ant::turnLeft() {
     currentDirrection = currentDirrection ? (Direction)(((int)currentDirrection-1)%4) : UP;
}

void Ant::turnRight() {
    currentDirrection = (Direction)(((int)currentDirrection+1)%4);
}
