#include "RoulettePlayer.h"
#include "IGame.h"
#include "IPlayer.h"

class Application
{
public:
	Application();
	~Application();

	void run();

private:
	IGame *_game;
	IPlayer *_player;
};
Application::Application()
{

}

Application::~Application() = default;

//FIX ISSUE
void Application::run()
{
	_game = new RouletteGame();
	_player = new RoulettePlayer(1000);
	_player->setGame(_game);
	_player->play(_player->getBetCount());	
}

int main()
{
	Application app;
	app.run();
	return 0;
}