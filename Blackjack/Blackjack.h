#pragma once

#include <iostream>
#include <cstdlib>
#include <random>
#include <string>
#include "Deck.h"

using namespace std;

extern const int YES;
extern const int NO;
extern const int ScoreForBlackjack;
extern const int MaxScoreForDealerToHit;
extern const int MaxHandSize;

struct Player {
	string role;
	Card * hand;
	int handSize;
	int handSum;
	bool done;
	int numberOfAces;
};

class Blackjack
{
public:
	Blackjack();
	void playGame();
	
private:
	Deck *deck;
	int playerHit;
	int playerStand;
	void addCardToHand(Player &blackjackPlayer);		// Add a card to the hand of the specified player
	void printHands();
	void sumHands();
	int getValue(Card card);
};