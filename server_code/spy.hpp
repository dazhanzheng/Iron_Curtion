#include "./block.hpp"
#include <spdlog/spdlog.h>

class Spy
{
private:
    int _pos;
    int hp;

public:
    enum towards
    {
        toUp = -5,
        toDown = +5,
        toLeft = -1,
        toRight = +1,
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
