#include <iostream>
using namespace std;



/* Read in a string from cin that is lowercase,
 * if the string that is inputed starts with a vowel write "vowel" out, otherwise write out the string. 

int main () {
string s;
cout << "input your word to check if the first letter is a vowel." << endl;
cin >> s;
if (s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u' || s[0] == 'y') {cout << "Vowel." << endl;}
else { cout << s << endl; }
}
*/

/*Write a program that reads a number and produces a grid where the diagonal says "match" otherwise outputs "nope"
 * 3
 * match nope nope
 * nope match nope
 * nope nope match */

int main () {
	int n;
	cout << "input n" << endl;
	cin >> n;
	for (int i = 0; i < n ; i++) {
		for (int j = 0; j < n ; j++) {
			if (i==j) cout << "Match " ;
			else cout << "Nope " ;
		}
		cout << endl;
	}
}
