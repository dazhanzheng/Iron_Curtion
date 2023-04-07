#include <iostream>
#include "block.hpp"
#include "./spy.hpp"
#include "./sheriff.hpp"
#include "./struct.hpp"
class Map
{
private:
    Block _blocks[5][5];
    Spy _spy;
    Sheriff _srf;
    Position _base;
    Position _intel;

public:
    Map(Position base)
    {
        for (int rows = 0; rows <= 4; rows++)
        {
            for (int cols = 0; cols <= 4; cols++)
            {
                if (cols == 2 && rows == 2)
                {
                    _blocks[rows][cols].setCity();
                }
            }
        }
        _base = base;
        _intel.colsIndex = 4 - base.colsIndex;
        _intel.rowsIndex = 4 - base.rowsIndex;
        log("Map.init:Success!");
    }
};