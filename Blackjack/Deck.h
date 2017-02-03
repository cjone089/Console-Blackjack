/* 
Creates a standard deck of 52 playing cards and provides functionality for
shuffling and drawing individual cards from the top of the deck 
*/
#pragma once

#include <iostream>
#include <cstdlib>
#include <random>
#include <string>
#include "Card.h"

using namespace std;

extern const int DeckSize;
extern const int NumberOfRanks;
extern const int NumberOfSuites;

class Deck 
{
	public:
		Deck();
		Card drawCard();
		void shuffle();

	private:
		Card *deck;
		Card *shuffledDeck;
		void initializeDeck();
		int topOfDeck;	// Index of card currently at the top of the deck
};