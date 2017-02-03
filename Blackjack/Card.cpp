#include "Card.h"

Card::Card()
{
}

Card::Card(Rank newRank, Suite newSuite, int cardId)
{
	rank = newRank;
	suite = newSuite;
	id = cardId;
	setName();
}

Card::Rank Card::getRank()
{
	return rank;
}

Card::Suite Card::getSuite()
{
	return suite;
}

string Card::getName()
{
	return name;
}

int Card::getId()
{
	return id;
}

void Card::setName()
{
	static const string RankNames[] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
	static const string SuiteNames[] = { "Spade", "Heart", "Club", "Diamond" };
	name = RankNames[rank] + " | " + SuiteNames[suite];
}