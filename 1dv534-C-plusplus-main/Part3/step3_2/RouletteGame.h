#ifndef ROULETTEGAME_H
#define ROULETTEGAME_H

#include "RouletteWheel.h"
#include "IGame.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;

class RouletteGame : public IGame
{
public:
	RouletteGame rouletteGame();
	~RouletteGame();
	int play(char* bet, int amount);		// Place amount money on position bet and return winnings
	int getID() const;
private:
	static const int ROULETTE_ID = 1234567;
	RouletteWheel rouletteWheel;
};

#endif