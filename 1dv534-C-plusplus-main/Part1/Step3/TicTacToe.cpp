/**********************************************************************
 File:		TicTacToe.cpp  - File where the games functions comes together
 Summary:	Class TicTacToe uses all the functions from the other classes
			and makes the game run as it is supposed. The TakeFive.obj
			is not included when I run it since it stops working when it
			it included. Don't know the purpose of the file, so if the 
			program does not work when it is included try remove it.

 Version:	1.0 - 2020-04-12
 Author:	Vilhelm Park, Linnéuniversitetet
 --------------------------------------------------------------------
 Log:		2020-04-12	First iteration of the class
**********************************************************************/
#include "Menu.h"
#include "TakeFive.h"

class TicTacToe
{
public:
	void run();	//Method which runs the application and all its functions.

private:
	int rows;	//Values for the row and column player wants to mark.
	char cols;
	int rowSize = 5;	//Row and colum size of the board, default sisze is 5x5.
	int colSize = 5;
	int whoStart = 1;	//Value which decides who starts, player or ai, default is player.
	bool continueLoopOrNot = true;	//Boolean which decides if we quit program or not.
	Player player = Player::CROSS;	//Player, default value is Cross, ai default value is ring.
	Player ai = Player::RING;

	int chooseWhoStarts();	//Function where user decides who starts the game.
	void chooseCrossOrRing(Player &player, Player &ai);	//Function where player decides what mark type they want.
	void chooseBoardSize();	//Function where user can decide the board size.
	void startTheGame();	//Function which starts the game.
	void chooseWhereToPutMark();	//Function where player choose where to put their mark.
	void playerStart(TakeFive takeFive);	//Function if the player choose to start the game and the function below when ai start.
	void aiStart(TakeFive takeFive);
	char playAgain();	//Function where player can decide to play again or quit to menu.
};

/******************************************************************************
				run ( )
				----------------
 Description:	This method use all methods to run the TicTacToe game.

 Pre:			

 Post:			The TicTacToe game has been played.

 Parameters:	None

******************************************************************************/
void TicTacToe::run()
{
	Menu menu;

	//Create the menu we want.
	char title[] = "Welcome to a game of Tic Tac Toe";
	char content1[] = "1) Choose whether you or the computer will start";
	char content2[] = "2) Choose whether to have \"X\" or \"O\" ";
	char content3[] = "3) Choose the size of the board ";
	char content4[] = "4) Start the game";
	char content5[] = "5) Quit the program ";

	menu.setMenuTitle(title);
	menu.createMenuContent(content1);
	menu.createMenuContent(content2);
	menu.createMenuContent(content3);
	menu.createMenuContent(content4);
	menu.createMenuContent(content5);

	while (continueLoopOrNot)
	{
		system("cls");
		menu.printMenuTitle();
		menu.theMenuContent();
		menu.readMenuChoice();

		switch (menu.getMenuChoice())
		{
		case '1':
			this->whoStart = chooseWhoStarts();
			break;
		case '2':
			chooseCrossOrRing(player, ai);
			break;
		case '3':
			chooseBoardSize();
			break;
		case '4':
			startTheGame();
			break;
		default:
			cout << "Exits program.";
			this->continueLoopOrNot = false;
			break;
		}
	}
}

/******************************************************************************
				chooseWhoStarts ( )
				----------------
 Description:	This method allows user to choose who starts the player or the
				ai.

 Pre:			The user choose the first option in menu.

 Post:			The user choose who starts.

 Parameters:	None

******************************************************************************/
int TicTacToe::chooseWhoStarts()
{
	char whoStarts;
	int toInt;
	cout << "Who starts player or ai (1 player, 2 ai): ";
	cin >> whoStarts;
	toInt = whoStarts - 48;

	while (toInt != 1 && toInt != 2)
	{
		cout << "Who starts player or ai (1 player, 2 ai): ";
		cin >> whoStarts;
		toInt = whoStarts - 48;
	}

	return toInt;
}

/******************************************************************************
				chooseCrossOrRint (Player &player, Player &ai )
				----------------
 Description:	This method will allow the user to choose their mark type.

 Pre:			The user choose the second option in the menu.

 Post:			The user choose their mark.

 Parameters:	
 player:	The users avatar in the tic tac toe game.
 ai:	The computers avatar in the tic tac toe game.

******************************************************************************/
void TicTacToe::chooseCrossOrRing(Player &player, Player &ai)
{
	char choice;
	int choiceToInt;
	cout << "Choose whether you want to be ring or cross (1 ring, 2 cross): ";
	cin >> choice;
	choiceToInt = choice - 48;

	while (choiceToInt < 1 && choiceToInt > 2)
	{
		cout << "Choose whether you want to be ring or cross (1 ring, 2 cross): ";
		cin >> choice;
		choiceToInt = choice - 48;
	}

	if (choiceToInt == 1)
	{
		this->player = Player::RING;
		this->ai = Player::CROSS;
	}

	else
	{
		this->player = Player::CROSS;
		this->ai = Player::RING;
	}
}

/******************************************************************************
				chooseBoardSize ( )
				----------------
 Description:	This method user choose the boards size.

 Pre:			The user choose the third option in the menu.

 Post:			The board size is choosen.

 Parameters:	None

******************************************************************************/
void TicTacToe::chooseBoardSize()
{
	cout << "Choose the boards size(rows (5-75) and colums (5-55)): ";
	cin >> this->rowSize >> this->colSize;
	
	while (rows < 5 && rows > 75 && cols < 5 && cols > 55)
	{
		cout << "Choose the boards size(rows (5-75) and colums (5-55)): ";
		cin >> this->rows >> this->cols;
	}
}

/******************************************************************************
				startTheGame ( )
				----------------
 Description:	This method will start the tic tac toe game.

 Pre:			The user choose the fourth option in the menu.

 Post:			The game has concluded.

 Parameters:	None

******************************************************************************/
void TicTacToe::startTheGame()
{
	TakeFive takeFive(rowSize, colSize);
	takeFive.startNewGame();
	//Run the game where the player starts
	if (whoStart == 1)
	{
		playerStart(takeFive);		
	}
	//Run the game where the ai start
	else
	{	
		aiStart(takeFive);		
	}
	//Destroy takeFive.
	takeFive.~TakeFive();
}

/******************************************************************************
				chooseWhereToPutMark ( )
				----------------
 Description:	This method will let the user choose where they want to put the 
				mark.

 Pre:			The game has started.

 Post:			The user has choosen where to put their mark.

 Parameters:	None

******************************************************************************/
void TicTacToe::chooseWhereToPutMark()
{
	int colsToInt;
	//To get correct letters i start from 65 which in ascii table is A and then I add
	//the amount of colums with 65 to get max letter which could for example be 5 + 65 = 70 (F).
	int colsMinToInt = 65, colsMaxToInt = colSize + 65;
	cout << "Choose where to put your mark(rows and colums): ";
	cin >> this->rows >> this->cols;
	putchar(toupper(this->cols));
	colsToInt = cols;
	cout << colsToInt << endl;

	while (colsToInt > colsMaxToInt || colsToInt < colsMinToInt)
	{
		cout << "Choose where to put your mark(rows and colums): ";
		cin >> this->rows >> this->cols;
		putchar(toupper(this->cols));
		colsToInt = cols;
		cout << colsToInt << endl;
	}

}

/******************************************************************************
				playerStart (TakeFive takeFive )
				----------------
 Description:	This method will play the game where the player goes first.

 Pre:			The user has choosen to start the game.

 Post:			The game has concluded.

 Parameters:	
 takeFive:	The TakeFive object we need to run their class functions.

******************************************************************************/
void TicTacToe::playerStart(TakeFive takeFive)
{
	//While the game is still active keep playing(might be wrong).
	while (takeFive.gameIsActive()) 
	{
		system("cls");
		takeFive.show();	//Show the board then let user put their mark
		chooseWhereToPutMark();
		takeFive.makeMove(player, rows, cols);
		takeFive.makeMove(ai);	//Ai put their mark and then the board is shown.
		takeFive.show();
		cin.get();
	}
	//If user wants to play again, play again.
	if (playAgain() == 'Y')
	{
		takeFive.startNewGame();
	}
}

/******************************************************************************
				aiStart (TakeFive takeFive )
				----------------
 Description:	This method is the same as above but ai starts.

 Pre:			The user choose to play the game.

 Post:			The game has concluded.

 Parameters:	
 takeFive:	The TakeFive object we need to run their class functions.

******************************************************************************/
void TicTacToe::aiStart(TakeFive takeFive)
{

	while (takeFive.gameIsActive())
	{
		//system("cls");
		takeFive.makeMove(ai);
		takeFive.show();
		chooseWhereToPutMark();
		takeFive.makeMove(player, rows, cols);
		takeFive.show();
		cin.get();
	}

	if (playAgain() == 'Y')
	{
		takeFive.startNewGame();
	}
}

/******************************************************************************
				playAgain ( )
				----------------
 Description:	This method will ask the user if they want to play again.

 Pre:			The first iteration of the game has concluded.

 Post:			The user choose to play again or quit.

 Parameters:	None

******************************************************************************/
char TicTacToe::playAgain()
{
	char YesOrNo;
	cout << "Want to play again (Y/N): ";
	cin >> YesOrNo;
	putchar(toupper(YesOrNo));

	while (YesOrNo != 'Y' || YesOrNo != 'N')
	{
		cout << "Want to play again (Y/N): ";
		cin >> YesOrNo;
		putchar(toupper(YesOrNo));
	}
	return YesOrNo;
}

//Runs the game
int main()
{
	TicTacToe ticTacToe;
	ticTacToe.run();
	return 0;
}