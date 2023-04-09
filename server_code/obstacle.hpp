#include "./log.hpp"
#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP
class Obstacle
{
private:
    obstacleType _id;
    bool _isUsed;

public:
    // TODO:
    Obstacle()
    {
        _isUsed = false;
        log("Obstacle.init:Success!");
        return;
    }
    bool initialize(obstacleType _initId)
    {
        _id = _initId;
        _isUsed = false;
        log("Obstacle.init:Success!");
        return true;
    }
    bool setObsType(obstacleType setType)
    {
        _id = setType;
        log("Obstacle.setType:Success!");
        return true;
    }

    ~Obstacle() {}
};
#endif