#ifndef STRUCT_HPP
#define STRUCT_HPP
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
    guard,
    bombs,
    alert,
};

struct Access
{
    bool _isUp;
    bool _isDown;
    bool _isLeft;
    bool _isRight;
};

enum informantType
{
    explosiveExpert,
    detective,
    k9,
    newsBoy,
    protester,
    barGirl,
    surgen,
    waitress,
    taxiDriver,
    sniper,
    militaryPolice,
    plumber,
};

enum tileType
{
    I,
    Iq,
    L,
    Lq,
    T,
    Tq,
    Xq,
};
#endif