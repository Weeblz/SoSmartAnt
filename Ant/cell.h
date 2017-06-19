#ifndef CELL_H
#define CELL_H

enum CellType {
    EMPTY,
    APPLE,
    APPLEWAY,
    PASSED,
    EATEN
};

class Cell {
public:
    Cell();
    Cell(bool isApple);

    CellType getType() { return type; }
    void setType(CellType t) { type = t; }
    void operator=(bool cell);
    void operator=(const Cell& cell);
    void operator=(CellType celltype);
    operator int();

private:
    CellType type;
public:
    int cellFactor;
};

#endif // CELL_H
