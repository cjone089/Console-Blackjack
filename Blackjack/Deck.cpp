#include "Deck.h"

const int DeckSize = 52;
const int NumberOfRanks = 13;
const int NumberOfSuites = 4;

Deck::Deck()
{
	deck = new Card[DeckSize];
	initializeDeck();
	topOfDeck = 0;
}

Card Deck::drawCard()
{
	if (topOfDeck < DeckSize)
	{
		Card drawnCard = deck[topOfDeck];
		topOfDeck++;
		return drawnCard;
	}
	else
	{
		// delete[] shuffledDeck;
		shuffle();	// Deck is automatically shuffled when cards run out
		Card drawnCard = deck[topOfDeck];
		topOfDeck++;
		return drawnCard;
	}
	
}

void Deck::shuffle()
{
	// Array to monitor which cards are present/missing from shuffled deck
	bool isCardUsed[DeckSize];
	for (int i = 0; i < DeckSize; i++)
		isCardUsed[i] = false;

	shuffledDeck = new Card[DeckSize];

	// Random number generator
	random_device rd;
	default_random_engine generator(rd());
	uniform_int_distribution<int> distribution(0, 51);

	int currentSizeOfShuffledDeck = 0;

	// Place random cards in shuffled deck one at a time
	while (currentSizeOfShuffledDeck < DeckSize)
	{
		int nextCard = distribution(generator);

		if (!isCardUsed[nextCard])
		{
			shuffledDeck[currentSizeOfShuffledDeck] = deck[nextCard];
			currentSizeOfShuffledDeck++;
			// Card is now used
			isCardUsed[nextCard] = true;
		}
	}

	// Clear deck array and replace it with shuffled deck
	delete[] deck;
	deck = shuffledDeck;
	// Reset top of deck index
	topOfDeck = 0;
}

void Deck::initializeDeck()
{
	// Give each card a unique id [0..51]
	int id = 0;

	// Loop through the ranks and suites to initialize deck
	for(int i = Card::ACE; i < NumberOfRanks; i++)
	{
		for (int j = Card::SPADE; j < NumberOfSuites; j++)
		{
			Card::Rank newRank = static_cast<Card::Rank>(i);
			Card::Suite newSuite = static_cast<Card::Suite>(j);
			Card newCard(newRank, newSuite, id);
			// Use id also as an index for card deck
			deck[id] = newCard;
			id++;
		}
	}
}