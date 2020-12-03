#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main () {
/Define Variables
	string Name;
	int Bank = 250.0;
	int Guess;
	int Bet;
	int WheelSize;
	int Actual;
/Introduction
	cout << "Player, please enter name " << endl;
	cin >> Name >> endl;
	cout << Name << ", please enter the size of the desired wheel" << endl;
	cin >> WheelSize >> endl;
	cout << Name << ", you will begin with $250.00" << endl;
/Start Game
	while (Bank > 0.0)
		{
		cout << Name << ", please enter your guess." << endl;
		cin << Guess << endl;
		cout << Name << ", please enter your bet." << endl;
		cin << Bet << endl; 
		Actual = rand() % WheelSize; 
		if (Guess) = (Actual); {
			Bank = (Bank) + (Bet); }
		else {
			Bank = (Bank) - (Bet); }
		}
cout << "You have " << Bank << " remaining in your bank." << endl;
}
return 0 
}
