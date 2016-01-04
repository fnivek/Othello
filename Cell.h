#ifndef CELL_H
#define CELL_H

#include <map>
#include <set>
#include <array>
#include <utility>

using namespace std;

typedef pair<unsigned short, unsigned short> cellpos;
typedef set<cellpos> cellposset;


struct Cell
{
public:
    static const bool WHITE = true;
    static const bool BLACK = false;

    Cell(bool type = WHITE, bool surrounded = false);

    bool type_ = WHITE;
    bool surrounded_ = false;

};

typedef map<cellpos, Cell> cellmap;
typedef array<short, 2> celldir;

void operator+=(cellpos& pos, const celldir& dir);
cellpos operator+(const cellpos& pos, const celldir& dir);


#endif // CELL_H
