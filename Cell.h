#ifndef CELL_H
#define CELL_H

#include <map>
#include <set>
#include <utility>

using namespace std;


struct Cell
{
public:
    static const bool WHITE = true;
    static const bool BLACK = false;

    Cell(bool type = WHITE, bool surrounded = false);

    bool type_ = WHITE;
    bool surrounded_ = false;

};

typedef pair<unsigned short, unsigned short> cellpos;
typedef set<cellpos> cellposset;
typedef map<cellpos, Cell> cellmap;


#endif // CELL_H
