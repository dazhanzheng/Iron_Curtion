#include "./block.hpp"
#include "./log.hpp"
#include "./struct.hpp"
#ifndef SPY_HPP
#define SPY_HPP

/*
    File Name: spy.hpp
    Author: dazhanzheng

    Description: Only Store the position and hp of the spy.
*/

class Spy
{
public:
    Position _pos;
    int _hp;
    Spy()
    {
        _hp = 3;
    }

    Spy(Position _initPos)
    {
        _pos = _initPos;
        _hp = 3;
    }
};
#endif
