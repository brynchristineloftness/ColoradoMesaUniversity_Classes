#include "iostream"
#include <string>
#include <stdlib.h>
using namespace std;



int main()
{
	int result;
	int num;
	int bet = 0;
	int money = 1000;
	string size;
	cout << "What wheel size would you like? (big/small)?" << endl;
	cin >> size;
	if (size != "big" && size != "small") {
		cout << "Invalid Size ";
	}
	for (size == "big" && size == "small"; money > 0; ) {
		cout << "How much money would you like to bet? " << "Current Funds: " << money << endl;
		cin >> bet;
		if (bet > money) {
			cout << "You don't have enough funds!" << endl;
		}
		 if (size == "big") {
			cout << "Pick a number between 1 and 25 " << endl;
			cin >> num;
			if (num > 25 || num < 0) {
				cout << "Invalid Number " << endl;
			}
			result = rand() % 25 + 1;
			cout << "You landed on " << result << endl;
			if (result == num) {
				cout << "Congratulations you win $" << bet * 10 << endl;
				money = (bet * 10) + money;

			}
			else cout << "Better Luck next time! You lost $" << bet << endl;
			money = money - bet;
		}
		else {
			cout << "Pick a number between 1 and 10 " << endl;
			cin >> num;
			if (num > 10 || num < 0) {
				cout << "Invalid Number " << endl;
			}
			result = rand() % 10 + 1;
			cout << "You landed on " << result << endl;
			if (result == num) {
				cout << "Congratulations you win $" << bet * 5 << endl;
				money = (bet * 5) + money;
			}
			else cout << "Better Luck next time! You lost $" << bet << endl;
			money = money - bet;
		}

	}
	return 0;
}

