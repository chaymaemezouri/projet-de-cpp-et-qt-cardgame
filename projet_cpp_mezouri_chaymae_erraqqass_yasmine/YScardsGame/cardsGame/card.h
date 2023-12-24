// card.h
#ifndef CARD_H
#define CARD_H

#include <string>



enum Suit { syofa, jbabn, floss, zrawt };
enum Rank { ONE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, TEN = 10, JACK, QUEEN, KING };

class Card {
public:
    Card(Rank r, Suit s);
    Rank getRank() const;
    Suit getSuit() const;
    void display() const;
    bool isRondaWith(const Card& other) const;
    void check_rank();

private:
    Rank rank;
    Suit suit;
};

#endif // CARD_H
