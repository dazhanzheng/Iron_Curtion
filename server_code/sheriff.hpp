#include "./struct.hpp"
#ifndef SHERIFF_HPP
#define SHERIFF_HPP
class Sheriff
{
public:
    Position _pos;
    Sheriff()
    {
        _pos.colsIndex = 2;
        _pos.rowsIndex = 2;
        log("Sheriff.init:Success!");
        return;
    }

    Movement getLegalAction()
    {
        Movement result;
        result.enableUp = true;
        result.enableDown = true;
        result.enableLeft = true;
        result.enableRight = true;
        if (_pos.colsIndex == 0)
        {
            result.enableLeft = false;
        }
        if (_pos.colsIndex == 4)
        {
            result.enableRight = false;
        }
        if (_pos.rowsIndex == 0)
        {
            result.enableDown = false;
        }
        if (_pos.rowsIndex == 4)
        {
            result.enableUp = false;
        }
        log("Sheriff.legalAction:Success!");

        return result;
    }

    Position getPosition()
    {
        return _pos;
    }

    bool patrol(Movement _to, Position SpyPosition)
    {
        int checkSum = _to.enableUp + _to.enableDown + _to.enableLeft + _to.enableRight;
        if (checkSum != 1)
        {
            log("Sheriff.patrol:move directions not equal to 1!");
            return false;
        }
        if (_to.enableUp == true)
        {
            _pos.rowsIndex += 1;
        }
        if (_to.enableDown == true)
        {
            _pos.rowsIndex -= 1;
        }
        if (_to.enableLeft == true)
        {
            _pos.colsIndex -= 1;
        }
        if (_to.enableRight == true)
        {
            _pos.colsIndex += 1;
        }
        log("Sheriff.patrol:Success!");
        int distance = 0;
        distance += (_pos.colsIndex - SpyPosition.colsIndex) * (_pos.colsIndex - SpyPosition.colsIndex);
        distance += (_pos.rowsIndex - SpyPosition.rowsIndex) * (_pos.rowsIndex - SpyPosition.rowsIndex);
        if (distance <= 2)
        {
            log("Sheriff.patrol:result.true!");
            return true;
        }
        else
        {
            log("Sheriff.patrol:result.false!");
            return false;
        }
    }
};
#endif