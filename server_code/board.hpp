#include "./map.hpp"
#include "./card.hpp"
#ifndef BOARD_HPP
#define BOARD_HPP
class Board
{
private:
    Map _mapWhite, _mapBlack;
    Card _cardWhite,_cardBlack;
public:
    Board(){

    }
    bool setBase(Position baseWhite,Position baseBlack){
        bool check1,check2;
        check1 = _mapWhite.initialize(baseWhite);
        check2 = _mapBlack.initialize(baseBlack);
        if(check1&&check2){
            log("Board.setBase:Success!");
            return true;
        }
        else{
            log("Board.setBase:Error!");
            return false;
        }
    }
    
};
#endif