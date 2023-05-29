#include <iostream>
#include "./block.hpp"
#include "./spy.hpp"
#include "./sheriff.hpp"
#include "./struct.hpp"
#ifndef MAP_HPP
#define MAP_HPP

/*
    File Name: map.hpp
    Author: dazhanzheng

    Description: Map contains blocks. I put the move function of spy in this class to avoid the problem of circular reference.
*/

class Map
{
private:
    Block _blocks[5][5];
    Sheriff _srf;
    Spy _spy;
    Position _base;
    Position _intel;

public:
    Map()
    {
        // set the city area;
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
        log("Map.construct:Success!");
        return;
    }

    bool moveSpy(Movement _to)
    {
        int checkSum = _to.enableUp + _to.enableDown + _to.enableLeft + _to.enableRight;
        if (checkSum != 1)
        {
            log("Map.moveSpy:move directions not equal to 1!");
            return false;
        }
        if (_to.enableUp == true)
        {
            _spy._pos.rowsIndex -= 1;
        }
        if (_to.enableDown == true)
        {
            _spy._pos.rowsIndex += 1;
        }
        if (_to.enableLeft == true)
        {
            _spy._pos.colsIndex -= 1;
        }
        if (_to.enableRight == true)
        {
            _spy._pos.colsIndex += 1;
        }
        log("Map.moveSpy:Success!");
        return true;
    }

    Movement getSpyMoveLegalAction()
    {
        Movement result;
        result.enableUp = true;
        result.enableDown = true;
        result.enableLeft = true;
        result.enableRight = true;
        // check the boundary
        if (_spy._pos.colsIndex == 0)
        {
            result.enableLeft = false;
        }
        if (_spy._pos.colsIndex == 4)
        {
            result.enableRight = false;
        }
        if (_spy._pos.rowsIndex == 0)
        {
            result.enableDown = false;
        }
        if (_spy._pos.rowsIndex == 4)
        {
            result.enableUp = false;
        }

        // check the access
        if (result.enableUp)
        {
            if (((**_blocks).getAccess()._isUp) && ((**(_blocks + 5)).getAccess()._isDown))
            {
                result.enableUp = true;
            }
            else
                result.enableUp = false;
        }

        if (result.enableDown)
        {
            if (((**_blocks).getAccess()._isDown) && ((**(_blocks - 5)).getAccess()._isUp))
            {
                result.enableDown = true;
            }
            else
                result.enableDown = false;
        }

        if (result.enableLeft)
        {
            if (((**_blocks).getAccess()._isLeft) && ((**(_blocks - 1)).getAccess()._isRight))
            {
                result.enableLeft = true;
            }
            else
                result.enableLeft = false;
        }

        if (result.enableRight)
        {
            if (((**_blocks).getAccess()._isRight) && ((**(_blocks + 1)).getAccess()._isLeft))
            {
                result.enableRight = true;
            }
            else
                result.enableRight = false;
        }

        // check the sheriff and city
        if (result.enableUp)
        {
            if ((**(_blocks + 5)).getIsCity())
            {
                if (_srf._pos.colsIndex == _spy._pos.colsIndex && _srf._pos.rowsIndex == _spy._pos.rowsIndex + 1)
                    ;
                result.enableUp = false;
            }
        }
        if (result.enableDown)
        {
            if ((**(_blocks - 5)).getIsCity())
            {
                if (_srf._pos.colsIndex == _spy._pos.colsIndex && _srf._pos.rowsIndex == _spy._pos.rowsIndex - 1)
                    ;
                result.enableDown = false;
            }
        }
        if (result.enableLeft)
        {
            if ((**(_blocks - 1)).getIsCity())
            {
                if (_srf._pos.colsIndex == _spy._pos.colsIndex - 1 && _srf._pos.rowsIndex == _spy._pos.rowsIndex)
                    ;
                result.enableLeft = false;
            }
        }
        if (result.enableRight)
        {
            if ((**(_blocks + 1)).getIsCity())
            {
                if (_srf._pos.colsIndex == _spy._pos.colsIndex + 1 && _srf._pos.rowsIndex == _spy._pos.rowsIndex)
                    ;
                result.enableRight = false;
            }
        }

        log("Spy.getLegalAction:Success!");
        return result;
    }

    bool initialize(Position base)
    {
        // set position of base and intel;
        _base = base;
        _intel.colsIndex = 4 - base.colsIndex;
        _intel.rowsIndex = 4 - base.rowsIndex;

        // initialize the spy with the position of base;
        _spy = Position(_base);

        log("Map.initialize:Success!");
        return true;
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
        bool check = _blocks[blockPtr.rowsIndex][blockPtr.colsIndex].setAccess(acc);
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
#endif