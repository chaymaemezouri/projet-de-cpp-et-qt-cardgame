#ifndef GAME_H
#define GAME_H


#include "player.h"
#include "deck.h"

class Game {
public:
    Game();
    void start();
    void end();

private:
    Deck deck;
    Player player1;
    Player player2;
    // Add more players or other game-specific variables as needed
};




#endif // GAME_H
