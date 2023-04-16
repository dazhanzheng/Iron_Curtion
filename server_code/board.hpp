#include "./map.hpp"
#include "./card.hpp"
#include "./accessRotate.hpp"
#ifndef BOARD_HPP
#define BOARD_HPP
#define WHITE 0
#define BLACK 1
class Board
{
private:
    Map _map[2];
    Card _card[2];

public:
    bool setBase(Position (&basePosition)[2])
    {
        bool check1, check2;
        check1 = _map[WHITE].initialize(basePosition[WHITE]);
        check2 = _map[BLACK].initialize(basePosition[BLACK]);
        if (check1 && check2)
        {
            log("Board.setBase:Success!");
            return true;
        }
        else
        {
            log("Board.setBase:Error!");
            return false;
        }
    }

    bool playTileCard(int color, int tileHandPtr ,Position destination, int rotate)
    {
        Map *mapPtr;
        Card *cardPtr;
        mapPtr = &_map[color];
        cardPtr = &_card[color];
        if(cardPtr.)
        mapPtr->setAccess(destination,AccessRotate::)
    }
};
#endif