// By Christopher Roy Jones, with special thanks to Gregory Javier Nistal
// A simple Blackjack game

#include "Blackjack.h"

int main()
{
	int YES = 1;
	int exitGame = YES;

	cout << "Welcome to Blackjack!\n";

	do
	{
		Blackjack casino_royale;
		casino_royale.playGame();
		cout << "\nWould you like to play again? (1 - Yes, 2 - No)\n";
		cin >> exitGame;
		cout << "\n\n";
	}while (exitGame == YES);


	cout << "\nThanks for playing!\n";
	system("pause");
	return 0;
}
