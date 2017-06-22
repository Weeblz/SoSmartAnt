#include "field.h"
#include "ant.h"
#include <fstream>
#include <string>
#include <qdebug.h>
#include <qstring.h>
#include <iostream>

Field::Field(Position _startingPoint) : startingPoint(_startingPoint), applesLeft(APPLES_COUNT), maxAntScore(0){
    playingGrid = std::vector<std::vector<Cell>>(32, std::vector<Cell>(32, Cell()));
    initField();
    playingGrid[startingPoint.x][startingPoint.y] = PASSED;

    ant = Ant(_startingPoint, this);
}

Field::Field(Position _startingPoint, const std::vector<State>& states) : startingPoint(_startingPoint), applesLeft(APPLES_COUNT), maxAntScore(0){
    playingGrid = std::vector<std::vector<Cell>>(32, std::vector<Cell>(32, Cell()));
    initField();
    playingGrid[startingPoint.x][startingPoint.y] = PASSED;

    ant = Ant(_startingPoint, states, this);
}

void Field::operator=(const Field& field) {
    startingPoint = field.startingPoint;
    playingGrid = field.playingGrid;
    ant = field.ant;
    applesLeft = field.applesLeft;
    maxAntScore = field.maxAntScore;
}

//creating gaming grid looking same way as in assignment
//NOT FOR THE FAINT HEARTED!
void Field::initField() {
    std::ifstream in("..\\..\\Ant\\fieldinit.txt");
    if(!in.is_open()) in.open("..\\Ant\\fieldinit.txt");
    std::string temp;
    for(int i=0; i<32; i++) {
        getline(in, temp);
        for(int j=0; j<32; j++) {
            if(temp[j*2] == '1') playingGrid[j][i].type = APPLE;
            else if(temp[j*2] == '2') playingGrid[j][i].type = APPLEWAY;
            else playingGrid[j][i].type = EMPTY;
        }
    }
    in.close();
}


bool Field::isApple(Position toCheck) {
    return playingGrid[toCheck.x][toCheck.y].getType() == APPLE;
}

void Field::eatApple(Position toEat) {
    playingGrid[toEat.x][toEat.y].setType(EMPTY);
    applesLeft--;
}

Position Field::nextCell(Position currentPosition, Direction currentDirrection) {
    switch(currentDirrection)
    {
    case UP:
        currentPosition.y--;
        if(currentPosition.y < 0) { currentPosition.y += GRID_SIZE; }
        break;
    case DOWN:
        currentPosition.y = (currentPosition.y+1)%GRID_SIZE;
        break;
    case RIGHT:
        currentPosition.x = (currentPosition.x+1)%GRID_SIZE;
        break;
    case LEFT:
        currentPosition.x--;
        if(currentPosition.x < 0) { currentPosition.x += GRID_SIZE; }
        break;
    }
    return currentPosition;
}

void Field::updateField() {
    Position p = ant.getPosition();
    playingGrid[p.x][p.y] = EMPTY;
    ant.move();
    p = ant.getPosition();
    playingGrid[p.x][p.y] = PASSED;
}
