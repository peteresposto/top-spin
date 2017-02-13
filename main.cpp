//pesposto_Assignment2
#include <iostream>
#include <assert.h>
#include "CircularDoublyLinkedList.h"
#include "TopSpin.h"
using namespace std;

int main()
{
	unsigned int bSize(1), sSize(1), rndSS(0);

	//Have user enter board and spin sizes and validate whether or not they are correct
	cout << "Welcome to pesposto_Top Spin!" << endl;
	cout << "Enter a board size between 1 and 20: ";
	cin >> bSize;
	cout << "Enter a spinner size between 1 and " << bSize << ": ";
	cin >> sSize;

	TopSpin game(bSize, sSize);

	cout << "Enter a number of random shifts and spins to start the game: ";
	cin >> rndSS;
	game.randomize(rndSS);

	//Loop everything while the game is not solved - after every move, it checks to see if the game is solved
	//and once at the beginning
	while (!(game.isSolved()))
	{
		int choice(0);
		cout << game << endl;
		cout << "Please choose from the following options enter your choice by entering the corresponding number:" << endl;
		cout << "1. Shift" << endl << "2. Spin" << endl << "3. Quit" << endl;
		cin >> choice;
		if (choice == 1)
		{
			int shiftChoice(0);
			cout << "Which way would you like to shift? " << endl;
			cout << "1. Right " << endl;
			cout << "2. Left " << endl;
			cin >> shiftChoice;
			if (shiftChoice == 1)
				game.shiftRight();
			if (shiftChoice == 2)
				game.shiftLeft();
		}
		if (choice == 2)
			game.spin();
		if (choice == 3)
		{
			cout << "You quit :/" << endl;
			break;
		}
	}

	//If the game is solved this is the end
	if (game.isSolved())
	{
		cout << game << endl;
		cout << "CONGRATULATIONS!" << endl;
	}

	system("pause");
}