#include "field.h"
#include <fstream>
#include <string>

Field::Field(Position _startingPoint) : startingPoint(_startingPoint), applesLeft(APPLES_COUNT){
    playingGrid = QVector<QVector<Cell>>(32, QVector<Cell>(32, Cell()));
    initField();
    playingGrid[startingPoint.x][startingPoint.y] = PASSED;
}

//creating gaming grid same way as in assignment
//NOT FOR THE FAINT HEARTED!
void Field::initField() {
    std::ifstream in("fieldinit.txt");
    std::string temp;
    for(int i=0; i<32; i++) {
        getline(in, temp);
        for(int j=0; j<32; j++) {
            if(temp[2*j] == '1') playingGrid[j][i] = APPLE;
            else if(temp[2*j] == '2') playingGrid[j][i] = APPLEWAY;
        }
    }
    in.close();
}
