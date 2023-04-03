#include "RouletteGame.h"

RouletteGame RouletteGame::rouletteGame()
{
	return RouletteGame();
}

RouletteGame::~RouletteGame() = default;

int RouletteGame::play(char * bet, int amount)
{
	int betToInt = atoi(bet);
	int rouletteWheelValue = rouletteWheel.spin();

	cout << "You bet on number " << betToInt << " and the roulette stopped at number "
		<< rouletteWheelValue << ".\n";

	if (betToInt == rouletteWheelValue)
	{
		cout << "You have won " << amount * 2 << "sek! \n";
		return amount * 2;
	}

	cout << "You lost all the money you bet! \n";
	//int negativeAmount = abs(amount);
	return amount;
}

int RouletteGame::getID() const
{
	return ROULETTE_ID;
}
