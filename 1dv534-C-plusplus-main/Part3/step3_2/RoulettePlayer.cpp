#include "RoulettePlayer.h"

RoulettePlayer::RoulettePlayer(int money) : money(money), betCount(0), ROULETTE_ID(1234567)
{
}

RoulettePlayer::~RoulettePlayer() = default;

bool RoulettePlayer::setGame(IGame * game)
{

	if (game->getID() != ROULETTE_ID)
		return false;				// If the game specified is other than Roulette - return error

	if (iGame != NULL && iGame != game)
		delete iGame;				// If occupied by other game and not equal - delete it

	iGame = game;
	return true;
}

bool RoulettePlayer::play(int numberOfTimes)
{
	int option;

	while (infinityLoop)
	{
		option = rouletteMenu.fullMenu();
		switch (option)
		{
		case 1:
			cout << "Enter starting sum for player: ";
			cin >> money;

			while (money <= 0)
			{
				cerr << "Player needs more than 0 to play." << endl;
				cout << "Enter starting sum for player: ";
				cin >> money;
				cout << "\n\n";
			}

			break;

		case 2:
			cout << "Enter amount of rounds to play roulette: ";
			cin >> betCount;

			while (betCount <= 0)
			{
				cerr << "Player needs to play more than 0 rounds." << endl;
				cout << "Enter amount of rounds to play roulette: ";
				cin >> betCount;
				cout << "\n\n";
			}

			break;

		case 3:
			playRounds(betCount);
			break;

		case 4:
			infinityLoop = false;
			return true;
			break;
		}
	}

	return false;
}

int RoulettePlayer::getMoney() const
{
	return money;
}

int RoulettePlayer::getBetCount() const
{
	return betCount;
}

void RoulettePlayer::playRounds(int amountOfRounds)
{
	cout << "At the beginning of the game the player has " << getMoney()
		<< " sek and will play " << getBetCount() << " rounds." << endl;

	while (amountOfRounds != 0)
	{
		if (money <= 0)
		{
			infinityLoop = false;
			return;
		}

		char * aBet = rouletteBet.betting();
		rouletteBet.bettingMoney(money);
		money =+ rouletteGame.play(aBet, money); //Small error when winning try fix if time.
		amountOfRounds--;
		cout<< "With " << amountOfRounds
			<< " rounds left the player has " << getMoney() << " sek left.\n\n";
	}

}