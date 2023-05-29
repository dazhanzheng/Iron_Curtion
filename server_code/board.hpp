#include "./map.hpp"
#include "./card.hpp"
#include "./accessRotate.hpp"
#ifndef BOARD_HPP
#define BOARD_HPP
#define WHITE 0
#define BLACK 1

/*
    File Name: board.hpp
    Author: dazhanzheng

    Description: Define the board. Board contains two maps and two cards.Board is the main part of the game,and provides all the modular operations of the game.
*/

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

    bool whoPlayTileCard(int color, int tileHandPtr, Position destination, int rotate)
    {
        Map *myMapPtr, *yrMapPtr;
        Card *myCardPtr, *yrCardPtr;

        myMapPtr = &_map[color];
        yrMapPtr = &_map[1 - color];
        myCardPtr = &_card[color];
        yrCardPtr = &_card[1-color];

        // determine the type of tile and place it
        if (myCardPtr->viewTile()[tileHandPtr] == T || myCardPtr->viewTile()[tileHandPtr] == Tq)
        {
            myMapPtr->setAccess(destination, AccessRotate::T[rotate]);
            yrMapPtr->addObstacle(destination, yrCardPtr->pickObstacle());
        }
        if (myCardPtr->viewTile()[tileHandPtr] == I || myCardPtr->viewTile()[tileHandPtr] == Iq)
        {
            myMapPtr->setAccess(destination, AccessRotate::I[rotate]);
            yrMapPtr->addObstacle(destination, yrCardPtr->pickObstacle());
        }
        if (myCardPtr->viewTile()[tileHandPtr] == L || myCardPtr->viewTile()[tileHandPtr] == Lq)
        {
            myMapPtr->setAccess(destination, AccessRotate::T[rotate]);
            yrMapPtr->addObstacle(destination, yrCardPtr->pickObstacle());
        }
        if (myCardPtr->viewTile()[tileHandPtr] == Xq)
        {
            myMapPtr->setAccess(destination, AccessRotate::X[rotate]);
            yrMapPtr->addObstacle(destination, yrCardPtr->pickObstacle());
        }
        // if it is a question mark card, you need to pick an informant card
        if (myCardPtr->viewTile()[tileHandPtr] == Xq ||
            myCardPtr->viewTile()[tileHandPtr] == Lq ||
            myCardPtr->viewTile()[tileHandPtr] == Iq ||
            myCardPtr->viewTile()[tileHandPtr] == Tq)
        {
            myCardPtr->pickInformant();
        }
        // discard the used tile
        myCardPtr->discardTile(tileHandPtr);
        log("Board.playTileCard:Success!");
        return true;
    }
    Movement SpyGetLegalAction(int color){
        Map *myMapPtr, *yrMapPtr;
        Card *myCardPtr, *yrCardPtr;
        myMapPtr = &_map[color];
        yrMapPtr = &_map[1 - color];
        myCardPtr = &_card[color];
        yrCardPtr = &_card[1-color];
        Movement result;
        result = myMapPtr->getSpyMoveLegalAction();
        log("Board.SpyGetLegalAction:Success!");
        return result;
    }

    bool moveSpy(int color,Movement to){
        Map *myMapPtr, *yrMapPtr;
        Card *myCardPtr, *yrCardPtr;
        myMapPtr = &_map[color];
        yrMapPtr = &_map[1 - color];
        myCardPtr = &_card[color];
        yrCardPtr = &_card[1-color];
        myMapPtr->moveSpy(to);
        log("Board.moveSpy:Success!");
        return true;
    }
};
#endif