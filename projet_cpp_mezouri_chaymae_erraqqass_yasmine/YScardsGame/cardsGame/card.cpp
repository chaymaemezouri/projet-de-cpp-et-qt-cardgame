// Card.cpp
#include "Card.h"
#include <iostream>
#include <vector>
#include <algorithm>

Card::Card(Rank r, Suit s) : rank(r), suit(s) {check_rank();}

Rank Card::getRank() const {
    return rank;
}


void Card::check_rank() {
    std::vector<int> validRanks = {1, 2, 3, 4, 5, 6, 7, 10, 11, 12};
    if (std::find(validRanks.begin(), validRanks.end(), static_cast<int>(rank)) == validRanks.end()) {
        std::cerr << "Invalid rank value provided for Card. Correcting to default rank 1." << std::endl;
        rank = static_cast<Rank>(1); // or Rank::Ace if you have a corresponding enum value
    }
}

Suit Card::getSuit() const {
    return suit;
}

void Card::display() const {
    const char* ranks[] = {"", "1", "2", "3", "4", "5", "6", "7", "", "", "10", "11", "12"};
    const char* suits[] = {"syofa", "jbabn", "floss", "zrawt"};
    std::cout << ranks[rank] << suits[suit] << " ";
}

bool Card::isRondaWith(const Card& other) const {
    return rank == other.rank;
}
