#include <iostream>
#include "Board.h"
#include "Player.h"
#include "Game.h"
#include "Throw.h"
#include "Results.h"
using namespace std;



int main()
{
	// Declarations and Player Object Creation
	std::string name;
	int accuracy{};
	cout << "Please enter Player 1 name: ";
	getline(cin, name);
	cout << endl;
	cout << "Please enter Player 1 Accuracy: ";
	cin >> accuracy;
	cout << endl;

	Player* player_1 = new Player(name, accuracy);

	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

	cout << endl;
	cout << "Please enter Player 1 name: ";
	getline(cin, name);
	cout << endl;
	cout << "Please enter Player 1 Accuracy: ";
	cin >> accuracy;
	cout << endl;

	Player* player_2 = new Player(name, accuracy);

	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	// Number of games to play
	int games{};
	cout << "How many games do you want to play: ";
	cin >> games;
	cout << endl;

	int first{};
	cout << "Who Plays First?" << endl;
	cout << "1) Player 1" << endl;
	cout << "2) Player 2" << endl;
	cout << "Answer: ";
	cin >> first;
	cout << endl;

	// Who Plays First
	first = first - 1;
	Results* results = new Results; 
	std::string winner;
	player_1->newGame();
	player_2->newGame();
	for (int loop = games; loop > 0; loop--)
	{
		Game* new_game = new Game;
		new_game->First_Player(player_1, 0);
		new_game->First_Player(player_2, 1);
		new_game->Play_Game(results, first);
		
		// results->Add_Results(new_game, player_1, player_2);
		//player_1->Reset_Wins();
		//player_2->Reset_Wins();
	}
	results->calculate(games); 
	results->get_results(games, player_1, player_2);
}