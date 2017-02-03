#include "Blackjack.h"
const int YES = 1;
const int NO = 2;
const int ScoreForBlackjack = 21;
const int MaxScoreForDealerToHit = 17;
const int MaxHandSize = 11;
Player dealer;
Player player;

Blackjack::Blackjack()
{
	deck = new Deck;
	deck->shuffle();
	dealer.hand = new Card[MaxHandSize];
	player.hand = new Card[MaxHandSize];
	dealer.handSize = 0;
	player.handSize = 0;
	dealer.handSum = 0;
	player.handSum = 0;
	dealer.done = false;
	player.done = false;
	dealer.numberOfAces = 0;
	player.numberOfAces = 0;
}

void Blackjack::playGame()
{
	// Start the player and dealer with two cards
	addCardToHand(dealer);
	addCardToHand(player);
	addCardToHand(dealer);
	addCardToHand(player);
	sumHands();
	printHands();

	if (dealer.handSum == ScoreForBlackjack)
	{
		cout << "Dealer has blackjack. Dealer wins.\n\n";
		return;
	}
	else if (player.handSum == ScoreForBlackjack)
	{
		cout << "Player has blackjack. Player wins.\n\n";
		return;
	}

	while (dealer.done == false || player.done == false)
	{
		if (player.done == false)
		{
			cout << "Would you like to hit? (1 - Yes, 2 - No)\n";
			cin >> playerHit;

			if (playerHit == YES)
			{
				addCardToHand(player);
				printHands();
				sumHands();

				if (player.handSum > ScoreForBlackjack)
				{
					cout << "Player's hand exceeded 21. Player loses.\n";
					return;
				}
			}
		}

		if (player.done == false)
		{
			cout << "Would you like to stand? (1 - Yes, 2 - No)\n";
			cin >> playerStand;
		}

		if (playerStand == YES)
		{
			player.done = true;
		}

		if (dealer.handSum < MaxScoreForDealerToHit && dealer.done == false)
		{
			addCardToHand(dealer);
			printHands();
			sumHands();

			if (dealer.handSum > ScoreForBlackjack)
			{
				cout << "Dealer hand exceeded 21. Dealer loses.\n";
				return;
			}
		}
		else if (dealer.handSum >= MaxScoreForDealerToHit)
		{
			dealer.done = true;
		}

		if (player.handSum == ScoreForBlackjack && dealer.handSum == ScoreForBlackjack)
		{
			cout << "Push, player and dealer reached 21.\n";
			return;
		}
		else if (player.handSum == ScoreForBlackjack)
		{
			cout << "Player reached 21. Player wins.\n";
			return;
		}
		else if (dealer.handSum == ScoreForBlackjack)
		{
			cout << "Dealer reached 21. Dealer wins.\n";
			return;
		}

		if ((player.done == true && dealer.done == true) || (player.handSize == MaxHandSize && player.handSize == MaxHandSize))
		{
			if (dealer.handSum < player.handSum)
			{
				cout << "Sum of your hand exceeds the dealer's sum of " << dealer.handSum << "! You win!";
				return;
			}
			else if (player.handSum == dealer.handSum)
			{
				cout << "Dealer sum of " << dealer.handSum << " is equal to the sum of your hand. Tie game.";
				return;
			}
			else if (dealer.handSum > player.handSum)
			{
				cout << "Sum of your hand is lower than the dealer's sum of " << dealer.handSum << ". You lose!";
				return;
			}
		}
	}
}

void Blackjack::addCardToHand(Player &blackjackPlayer)
{
	if (blackjackPlayer.handSize <= MaxHandSize)
	{
		Card drawnCard = deck->drawCard();
		blackjackPlayer.hand[blackjackPlayer.handSize] = drawnCard;
		blackjackPlayer.handSize++;

		if (drawnCard.getRank() == Card::ACE)
			blackjackPlayer.numberOfAces++;
	}
	else
	{
		blackjackPlayer.done = true;
	}
}

void Blackjack::printHands()
{
	cout << "\nYour current hand is...\n\n";

	for (int i = 0; i < player.handSize; i++)
		cout << "    -" << player.hand[i].getName() << "-    \n\n";

	cout << "\nDealer's current hand is...\n\n";

	for (int j = 0; j < dealer.handSize; j++)
		cout << "    -" << dealer.hand[j].getName() << "-   \n\n";
}

void Blackjack::sumHands()
{
	dealer.handSum = 0;
	player.handSum = 0;
	for (int i = 0; i < dealer.handSize; i++)
		dealer.handSum += getValue(dealer.hand[i]);

	for (int j = 0; j < player.handSize; j++)
		player.handSum += getValue(player.hand[j]);

	// Calculate value of ace cards for dealer/player hands
	if (dealer.numberOfAces > 0)
	{
		int dealerMinValueOfAces = dealer.numberOfAces;
		int dealerMaxValueOfAces = (dealer.numberOfAces - 1) + 11;

		if (dealer.handSum + dealerMaxValueOfAces <= 21)
			dealer.handSum += dealerMaxValueOfAces;
		else
			dealer.handSum += dealerMinValueOfAces;
	}
	
	if (player.numberOfAces > 0)
	{
		int playerMinValueOfAces = player.numberOfAces;
		int playerMaxValueOfAces = (player.numberOfAces - 1) + 11;

		if (player.handSum + playerMaxValueOfAces <= 21)
			player.handSum += playerMaxValueOfAces;
		else
			player.handSum += playerMinValueOfAces;
	}

	cout << "\nPlayer's current hand value is: " << player.handSum << endl;
	
}

int Blackjack::getValue(Card card)
{
	// Ignore value of ace cards, determine it in sumHands()
	if (card.getRank() == Card::ACE)
		return 0;
	// Rank is in [Two...Ten]
	else if (card.getRank() <= Card::TEN)
		return card.getRank() + 1;
	else // Rank is in [Jack...King]
		return 10;
}