#include "struct.hpp"
#include "obstacle.hpp"
class Block
{
private:
    Access _access;
    Obstacle _obstacleList[10];
    uint obstacleIndex;
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

        obstacleIndex = 0;
        bool _isCity = false;
        bool _isDestroy = false;
        log("Block.init:Success!");
        return;
    }

    ~Block() {}
    Access getAccess()
    {
        log("Block.getAccess:Success!");
        return _access;
    }

    void setCity()
    {
        log("Block.setCity:Success!");
        _isCity = true;
        return;
    }

    bool setObstacle(obstacleType obsId)
    {
        bool check = _obstacleList[obstacleIndex].setObsType(obsId);
        if (check)
        {
            obstacleIndex++;
            log("Block.setObstacle:Success!");
            return true;
        }
        else
        {
            log("Block.setObstacle:Error!");
            return false;
        }
    }

    bool setAccess(Access accIn)
    {
        _access = accIn;
        log("Block.setAccess:Success!");
        return true;
    }

    bool getIsCity()
    {
        log("Block.getIsCity:Success!");
        return _isCity;
    }
};
