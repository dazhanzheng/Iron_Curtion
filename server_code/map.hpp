#include <iostream>
#include "block.hpp"
#include "./spy.hpp"
#include "./sheriff.hpp"
#include "./struct.hpp"
class Map
{
private:
    Block _blocks[5][5];
    Sheriff _srf;
    Spy _spy;
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
        _spy = Position(_base);
        log("Map.init:Success!");
        return;
    }

    bool addObstacle(Position blockPtr, obstacleType obsId)
    {
        bool check = _blocks[blockPtr.rowsIndex][blockPtr.colsIndex].setObstacle(obsId);
        if (check)
        {
            log("Map.addObstacle:Success!");
            return true;
        }
        else
        {
            log("Map.addObstacle:Error!");
            return false;
        }
    }

    bool setAccess(Position blockPtr, Access acc)
    {
        bool check = _blocks[blockPtr.rowsIndex][blockPtr.colsIndex].Block::setAccess(acc);
        if (check)
        {
            log("Map.setAccess:Success!");
            return true;
        }
        else
        {
            log("Map.setAccess:Error!");
            return false;
        }
    }
};