#include "RouletteBet.h"

RouletteBet::RouletteBet() = default;

RouletteBet::~RouletteBet() = default;

char *RouletteBet::betting()
{
	string theBet = "";
	cout << "Input your bet (0-36): ";
	theBet = bettingInput();

	while (!checkBet(theBet))
	{
		cout << "Input your bet (0-36): ";
		theBet = bettingInput();
	}

	int newCharLength = theBet.size();
	char *theBetToChar = new char[newCharLength];
	memcpy(theBetToChar, theBet.c_str(), theBet.size());

	return  theBetToChar;
}

void RouletteBet::bettingMoney(int &money)
{
	int tempMoney = 0;
	cout << "Input how much you want to bet: ";
	tempMoney = moneyInput();

	while (tempMoney > money || tempMoney <= 0)
	{
		cerr << "You can't bet more than you have or bet less than 0! \n";
		cout << "Input how much you want to bet: ";
		tempMoney = moneyInput();
	}

	money -= tempMoney;
}

string RouletteBet::bettingInput()
{
	string input;
	cin >> input;
	return input;
}

int RouletteBet::moneyInput()
{
	int money;
	cin >> money;
	return money;
}

bool RouletteBet::checkBet(string input)
{
	int charInput = atoi(input.c_str());

	if (charInput > 36 || charInput < 0)
	{
		return false;
	}

	return true;
}