#ifndef DECK_H
#define DECK_H


#include "Card.h"
#include <vector>

class Deck {
public:
    Deck();
    void shuffle();
    Card drawCard();
    std::vector<Card> dealHand(int numCards);
    static void displayHand(const std::vector<Card>& hand);
    int get_limit() const;
    void set_limit(int newlimit);

private:
    std::vector<Card> cards;
    int limit;
};


#endif // DECK_H
