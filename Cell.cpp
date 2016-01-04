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
