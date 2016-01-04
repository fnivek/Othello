#include "Cell.h"

Cell::Cell(bool type, bool surrounded):
    type_(type),
    surrounded_(surrounded)
{}

void operator+=(cellpos& pos, const celldir& dir)
{
    pos.first += dir[0];
    pos.second += dir[1];
}


cellpos operator+(const cellpos& pos, const celldir& dir)
{
    cellpos new_pos = pos;
    new_pos.first += dir[0];
    new_pos.second += dir[1];
    return new_pos;
}
