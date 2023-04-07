#include "struct.hpp"
#include "obstacle.hpp"
class Block
{
private:
    Access _access;
    Obstacle _list[10];
    uint obstacleListNum;
    bool _isCity;
    bool _isDestroy;

public:
    // TODO:
    Block()
    {
        // access init
        _access._isUp = false;
        _access._isDown = false;
        _access._isLeft = false;
        _access._isRight = false;

        obstacleListNum = 0;
        bool _isCity = false;
        bool _isDestroy = false;
        log("Block.init:Success!");
    }

    ~Block() {}
    Access getAccess()
    {
        return _access;
    }

    void setCity()
    {
        _isCity = true;
    }

    bool getIsCity()
    {
        return _isCity;
    }
};
