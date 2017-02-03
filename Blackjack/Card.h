/*
Creates an individual playing card using a unique rank/suite
*/
#pragma once

#include <cstdlib>
#include <string>

using namespace std;

class Card 
{
	public:
		enum Rank
		{
			ACE = 0,
			TWO = 1,
			THREE = 2,
			FOUR = 3,
			FIVE = 4,
			SIX = 5,
			SEVEN = 6,
			EIGHT = 7,
			NINE = 8,
			TEN = 9,
			JACK = 10,
			QUEEN = 11,
			KING = 12
		};

		enum Suite
		{
			SPADE = 0,
			HEART,
			CLUB,
			DIAMOND 
		};


		Card();
		Card(Rank newRank, Suite newSuite, int cardId);
		Rank getRank();
		Suite getSuite();
		string getName();
		int getId();

	private:
		int id;
		string name;
		Rank rank;
		Suite suite;
		void setName();
};