struct Position
{
    int colsIndex;
    int rowsIndex;
};

struct Movement
{
    bool enableUp;
    bool enableDown;
    bool enableLeft;
    bool enableRight;
};

enum obstacleType
{
    green,
    guards,
    bombs,
    alarm,
};

struct Access
{
    bool _isUp;
    bool _isDown;
    bool _isLeft;
    bool _isRight;
};