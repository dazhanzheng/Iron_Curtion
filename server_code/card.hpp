#include "./struct.hpp"
#include <random>
#include "./preDeck.hpp"
#include "log.hpp"
#ifndef CARD_HPP
#define CARD_HPP
class Card
{
private:
    informantType informantPile[20];
    int informantPilePtr;
    informantType informantHand[3];
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
        shuffleInformant();
        shuffleObstacle();
        shuffleTile();
        log("Card.init:Success!");
        return;
    }

    bool shuffleInformant()
    {
        std::random_device rd;
        std::mt19937 gen(rd());

        std::shuffle(informantPile[0], informantPile[20], gen);
        log("Card.shuffleInformant:Success!");
        return true;
    }
    bool shuffleObstacle()
    {
        std::random_device rd;
        std::mt19937 gen(rd());

        std::shuffle(obstaclePile[0], obstaclePile[27], gen);
        log("Card.shuffleObstacle:Success!");
        return true;
    }
    bool shuffleTile()
    {
        std::random_device rd;
        std::mt19937 gen(rd());

        std::shuffle(tilePile[0], tilePile[35], gen);
        log("Card.shuffleTile:Success!");
        return true;
    }
};
#endif