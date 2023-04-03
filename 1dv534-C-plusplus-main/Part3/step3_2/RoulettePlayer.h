#ifndef ROULETTEPLAYER_H
#define ROULETTEPLAYER_H

#include "IPlayer.h"
#include "IGame.h"
#include "RouletteMenu.h"
#include "RouletteBet.h"
#include "RouletteGame.h"

class RoulettePlayer : public IPlayer
{
public:
	RoulettePlayer(int money);
	~RoulettePlayer();
	virtual bool setGame(IGame* game);		// Gives the player a game object to use
	virtual bool play(int numberOfTimes);	// Tells player to play the game numberOfTimes times
	virtual int	 getMoney() const;			// Returns the amount of player's money
	virtual int  getBetCount() const;		// Returns the total number of bets placed during object life time

private:
	IGame *iGame;
	RouletteMenu rouletteMenu;
	RouletteBet rouletteBet;
	RouletteGame rouletteGame;
	bool infinityLoop = true;
	int money;
	int betCount;
	const int ROULETTE_ID;
	void playRounds(int amount);
};
#endif
