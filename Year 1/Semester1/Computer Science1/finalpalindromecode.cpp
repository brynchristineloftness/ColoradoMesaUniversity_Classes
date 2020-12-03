#include <iostream>

using namespace std;

long UserEntry;

long formReversed(long Entry) {
long holder = Entry; 
long ReversedNumber = 0;
long Palindrome = 0;
while (Entry != 0) {
ReversedNumber = ReversedNumber*10;
ReversedNumber = ReversedNumber + (Entry % 10);
Entry = Entry / 10;
Palindrome = holder + ReversedNumber; }
return Palindrome;
}

int main () {
	cout << "Please enter a (whole!) number between 10 and 100 (inclusive) to check if it is a palindrome." << endl;
	cout << "After checking if your number is a palindrome, your number can be made into a valid palindrome." << endl;
	cin >> UserEntry;
if (UserEntry <= 10 || UserEntry >= 100) {
	cout << "Your number must be between 10 and 100, inclusive. Please enter a new number.";
	cin >> UserEntry; }
long Palindrome = formReversed(UserEntry);
cout << "Your entry, " << UserEntry << " made into a palindrome is " << Palindrome << endl;
cout << endl<< endl << "Thanks for playing.";
return 0;
}



