#ifndef CELL_H
#define CELL_H

struct Cell
{
public:
    enum cell_type {WHITE, BLACK, EMPTY};
    Cell(unsigned short row, unsigned short column, cell_type type);
private:
    unsigned short row_;
    unsigned short column_;
    cell_type type_;


};

#endif // CELL_H
