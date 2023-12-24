// player.cpp
#include "player.h"

Player::Player() : score(0) {
    // Initialize player state
}

void Player::addCard(const Card& card) {
    hand.push_back(card);
}

void Player::playCard() {
    // Implement card playing logic
}

// Getters
Card Player::getCard(int index) const {
    if (index >= 0 && index < static_cast<int>(hand.size())) {
        return hand[index];
    }
    // Handle error scenario, e.g., throw an exception or return a default card
    return hand[0];
}

std::vector<Card> Player::getHand() const {
    return hand;
}

int Player::getScore() const {
    return score;
}

// Setters
void Player::setCard(int index, const Card& card) {
    if (index >= 0 && index < static_cast<int>(hand.size())) {
        hand[index] = card;
    }
    // Handle error scenario, e.g., do nothing or throw an exception
}

void Player::setScore(int newScore) {
    score = newScore;
}



void Player::setHand(const std::vector<Card>& newHand) {
    hand = newHand;
}

void Player::removeCard(int index) {
    if (index >= 0 && index <= static_cast<int>(hand.size())) {
        hand.erase(hand.begin() + index);
    }
}


int Player::getHandSize() const {
    return hand.size();
}
