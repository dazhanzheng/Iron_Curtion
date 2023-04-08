#include "./block.hpp"
#include "./log.hpp"
#include "./struct.hpp"
class Spy
{
private:
    Position _pos;
    int _hp;

public:
    Spy(){
        _hp = 3;
    }

    Spy(Position _initPos)
    {
        _pos = _initPos;
        _hp = 3;
    }

    ~Spy()
    {
    }
    Movement getLegalAction(Block *blocks, Position sheriffPosition)
    {
        Movement result;
        result.enableUp = true;
        result.enableDown = true;
        result.enableLeft = true;
        result.enableRight = true;
        // check the boundary
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

        // check the access
        if (result.enableUp)
        {
            if (((*blocks).getAccess()._isUp) && ((*(blocks + 5)).getAccess()._isDown))
            {
                result.enableUp = true;
            }
            else
                result.enableUp = false;
        }

        if (result.enableDown)
        {
            if (((*blocks).getAccess()._isDown) && ((*(blocks - 5)).getAccess()._isUp))
            {
                result.enableDown = true;
            }
            else
                result.enableDown = false;
        }

        if (result.enableLeft)
        {
            if (((*blocks).getAccess()._isLeft) && ((*(blocks - 1)).getAccess()._isRight))
            {
                result.enableLeft = true;
            }
            else
                result.enableLeft = false;
        }

        if (result.enableRight)
        {
            if (((*blocks).getAccess()._isRight) && ((*(blocks + 1)).getAccess()._isLeft))
            {
                result.enableRight = true;
            }
            else
                result.enableRight = false;
        }

        // check the sheriff and city
        if (result.enableUp)
        {
            if ((*(blocks + 5)).getIsCity())
            {
                if (sheriffPosition.colsIndex == _pos.colsIndex && sheriffPosition.rowsIndex == _pos.rowsIndex + 1)
                    ;
                result.enableUp == false;
            }
        }
        if (result.enableDown)
        {
            if ((*(blocks - 5)).getIsCity())
            {
                if (sheriffPosition.colsIndex == _pos.colsIndex && sheriffPosition.rowsIndex == _pos.rowsIndex - 1)
                    ;
                result.enableDown == false;
            }
        }
        if (result.enableLeft)
        {
            if ((*(blocks - 1)).getIsCity())
            {
                if (sheriffPosition.colsIndex == _pos.colsIndex - 1 && sheriffPosition.rowsIndex == _pos.rowsIndex)
                    ;
                result.enableLeft == false;
            }
        }
        if (result.enableRight)
        {
            if ((*(blocks + 1)).getIsCity())
            {
                if (sheriffPosition.colsIndex == _pos.colsIndex + 1 && sheriffPosition.rowsIndex == _pos.rowsIndex)
                    ;
                result.enableRight == false;
            }
        }

        log("Spy.getLegalAction:Success!");
        return result;
    }

    bool move(Movement _to)
    {
        int checkSum = _to.enableUp + _to.enableDown + _to.enableLeft + _to.enableRight;
        if (checkSum != 1)
        {
            log("Spy.move:move directions not equal to 1!");
            return false;
        }
        if (_to.enableUp == true)
        {
            _pos.rowsIndex -= 1;
        }
        if (_to.enableDown == true)
        {
            _pos.rowsIndex += 1;
        }
        if (_to.enableLeft == true)
        {
            _pos.colsIndex -= 1;
        }
        if (_to.enableRight == true)
        {
            _pos.colsIndex += 1;
        }
        log("Spy.move:Success!");
        return true;
    }
};
