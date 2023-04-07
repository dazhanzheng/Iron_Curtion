class Block
{
private:
    class Obstacle
    {
    private:
        // type of obstacle
        enum obstacleType
        {
            green,
            guards,
            bombs,
            alarm,
        };
        obstacleType _id;

    public:
        // TODO:
        Obstacle() {}
        ~Obstacle() {}
    };

    // access to other block
    struct Access
    {
        bool _isUp;
        bool _isDown;
        bool _isLeft;
        bool _isRight;
    };
    bool isCity;

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

    struct ObstacleList
    {
        int _pointer;
        Obstacle _list[10];
    };

    Access _acc;
    ObstacleList _obslist;

public:
    // TODO:
    Block() {}
    ~Block() {}
    Access getAccess()
    {
        return _acc;
    }
    void setCity()
    {
        isCity = true;
    }

    bool getIsCity()
    {
        return isCity;
    }
};
