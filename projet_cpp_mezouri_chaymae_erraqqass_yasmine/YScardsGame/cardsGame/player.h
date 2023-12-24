#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "card.h"

class Player {
public:
    Player();
    void addCard(const Card& card);
    void playCard();
    void removeCard(int index); // New method to remove a card
    // Getters
    Card getCard(int index) const;
    std::vector<Card> getHand() const;
    int getScore() const;
     int getHandSize() const;

    // Setters
    void setHand(const std::vector<Card>& newHand);
    void setCard(int index, const Card& card);
    void setScore(int score);

private:
    std::vector<Card> hand;
    int score;
};

#endif // PLAYER_H
