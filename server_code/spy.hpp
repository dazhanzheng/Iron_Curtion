#include "./block.hpp"

class Spy
{
private:
    int _pos;
    int hp;

public:
    enum towards
    {
        toUp,
        toDown,
        toLeft,
        toRight,
    };

    bool move(towards _to, const Block *src)
    {
        int posSrc = _pos;
        int posDst = _pos + _to;
        // boundary
        if (posDst > 24 || posDst < 0){

        }
    }
};
