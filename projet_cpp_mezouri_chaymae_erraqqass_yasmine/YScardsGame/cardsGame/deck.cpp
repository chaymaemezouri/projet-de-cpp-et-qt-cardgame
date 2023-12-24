// Deck.cpp
#include "Deck.h"
#include <algorithm>
#include <ctime>
#include <iostream>


Deck::Deck() {
    for (int suit = syofa; suit <= zrawt; ++suit) {
        for (int rank = ONE; rank <= KING; ++rank) {
            if (rank != 8 && rank != 9) {
                cards.emplace_back(static_cast<Rank>(rank), static_cast<Suit>(suit));
            }
        }
    }

    limit = 0;
}

int Deck::get_limit() const{
    return limit;
}


void Deck::set_limit(int newlimit) {
    limit = limit + newlimit;
}


void Deck::shuffle() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::random_shuffle(cards.begin(), cards.end());
}

Card Deck::drawCard() {
    Card card = cards.back();
    cards.pop_back();
    return card;
}

std::vector<Card> Deck::dealHand(int numCards) {
    std::vector<Card> hand;
    for (int i = 0; i < numCards; ++i) {
        if (!cards.empty()) {
            hand.push_back(drawCard());
        }
    }
    return hand;
}

void Deck::displayHand(const std::vector<Card>& hand) {
    for (const auto& card : hand) {
        card.display();
    }
    std::cout << std::endl;
}
