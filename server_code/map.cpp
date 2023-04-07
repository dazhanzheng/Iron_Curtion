#include<iostream>

class Obstacle{
private:
    enum obstacleType{
        green,
        guards,
        bombs,
        alarm,
    };
    obstacleType _id;
public:
    Obstacle(){}
    ~Obstacle(){}
};

class Block{
private:
    // access to other block
    struct Access{
        bool _isUp;
        bool _isDown;
        bool _isLeft;
        bool _isRight;
    };

    /*
    struct Shape{
        // all shapes
        enum shapes{
            I,
            L,
            T,
            X,
        };
        shapes value;
    };
    */

    struct ObstacleList{
        int _pointer;
        Obstacle _list[10];
    };

    Access _acc;
    ObstacleList _obslist;

public:
    Block(){}
    ~Block(){}
};

class Map{
private:
    
public:
    
}