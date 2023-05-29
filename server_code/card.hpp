#include "./struct.hpp"
#include <random>
#include <algorithm>
#include "./preDeck.hpp"
#include "./log.hpp"
#ifndef CARD_HPP
#define CARD_HPP

/*
    File Name: card.hpp
    Author: dazhanzheng

    Description: Define the card. Card contains all the hand cards and provides all the modular operations of the card.
*/

class Card
{
private:
    informantType informantPile[20];
    int informantPilePtr;
    informantType informantHand[6];
    int informantHandPtr;
    informantType informantLib[20];
    int informantLibPtr;
    informantType informantDiscardPile[20];
    int informantDiscardPilePtr;
    obstacleType obstaclePile[27];
    int obstaclePilePtr;
    tileType tilePile[35];
    int tilePilePtr;
    tileType tileHand[35];
    int tileHandPtr;

public:
    Card()
    {
        for (int i = 0; i < 20; i++)
        {
            informantPile[i] = basicInformantDeck[i];
        }
        informantPilePtr = 0;
        for (int i = 0; i < 27; i++)
        {
            obstaclePile[i] = basicObstacleDeck[i];
        }
        obstaclePilePtr = 0;
        for (int i = 0; i < 35; i++)
        {
            tilePile[i] = basicTileDeck[i];
        }
        tilePilePtr = 0;
        informantHandPtr = 0;
        informantLibPtr = 0;
        informantDiscardPilePtr = 0;
        tileHandPtr = 0;
        shuffleInformant();
        shuffleObstacle();
        shuffleTile();
        log("Card.init:Success!");
        return;
    }

    informantType pickInformant()
    {
        informantHand[informantHandPtr] = informantPile[informantPilePtr];
        informantHandPtr++;
        informantPilePtr++;
        log("Card.informantPick:Success!");
        return informantHand[informantHandPtr-1];
    }

    bool discardInformant(int discardIndex)
    {
        for(int i=discardIndex;i<6-1;i++){
            informantHand[i] = informantHand[i+1]; 
        }
        informantHandPtr--;
        log("Card.discardInformant:Success!");
        return true;
    }

    bool storeInformant(int storeIndex)
    {
        informantType storeObj = informantHand[storeIndex];
        for(int i=storeIndex;i<6-1;i++){
            informantHand[i] = informantHand[i+1]; 
        }
        informantHandPtr--;
        informantLib[informantLibPtr] = storeObj;
        informantLibPtr++;
        log("Card.storeInformant:Success!");
        return true;
    }

    bool distoreInformant(int distoreIndex)
    {
        informantType distoreObj = informantLib[distoreIndex];
        for(int i=distoreIndex;i<20-1;i++){
            informantLib[i] = informantLib[i+1]; 
        }
        informantLibPtr--;
        informantHand[informantHandPtr] = distoreObj;
        informantHandPtr++;
        log("Card.distoreInformant:Success!");
        return true;
    }



    tileType pickTile()
    {
        tileHand[tileHandPtr] = tilePile[tilePilePtr];
        tileHandPtr++;
        tilePilePtr++;
        log("Card.pickTile:Success!");
        return tileHand[tileHandPtr-1];
    }

    const tileType* viewTile(){
        return tileHand;
    }

    bool discardTile(int discardIndex)
    {
        for(int i=discardIndex;i<35-1;i++){
            tileHand[i] = tileHand[i+1]; 
        }
        tileHandPtr--;
        log("Card.discardTile:Success!");
        return;
    }

    obstacleType pickObstacle()
    {
        obstaclePilePtr++;
        log("Card.pickObstacle:Success!");
        return obstaclePile[obstaclePilePtr-1];
    }

    bool shuffleInformant()
    {
        std::random_device rd;
        std::mt19937 gen(rd());

        std::shuffle(informantPile, informantPile + 20, gen);
        log("Card.shuffleInformant:Success!");
        return true;
    }
    bool shuffleObstacle()
    {
        std::random_device rd;
        std::mt19937 gen(rd());

        std::shuffle(obstaclePile, obstaclePile + 27, gen);
        log("Card.shuffleObstacle:Success!");
        return true;
    }
    bool shuffleTile()
    {
        std::random_device rd;
        std::mt19937 gen(rd());

        std::shuffle(tilePile, tilePile + 35, gen);
        log("Card.shuffleTile:Success!");
        return true;
    }
};
#endif