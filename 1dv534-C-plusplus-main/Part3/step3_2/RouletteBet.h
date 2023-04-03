#ifndef ROULETTEBET_H
#define ROULETTEBET_H

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::string;

class RouletteBet
{
public:
	RouletteBet();
	~RouletteBet();
	char *betting();
	void bettingMoney(int &money);

private:
	string bettingInput();
	int moneyInput();
	bool checkBet(string input);
};
#endif