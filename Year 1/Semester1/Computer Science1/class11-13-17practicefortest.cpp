#include <iostream>
using namespace std;

/* assuming that 2, 3, 5 , 7 , 11 are all the primes you know. read in a int number n and state whether it is prime or not. 
 
int main () {
	bool isPrime = true;
	int n;
	cout << "Please enter n";
	cin >> n;
	int primes = [2, 3, 5, 7, 11];
	int MaxPrime = 5;
	for (int i=0;i<MaxPrime;i++) {
		if ((n % primes[i])== 0) {isPrime = false; cout<< "not prime."<< endl; break; }
	}
	if (isPrime) cout << "is prime." << endl;
	}
*/



/* write a program which reads 5 floating point numbers and finds the min and max values
input : 1 10 .5 -1 20
output :

main () {
float min;
float max;

cin >> min;
max = min;
for (int i = 0; i <= 4; i++) {
	float next;
	cin >> next;
	if (next < min) min = next;
	if (next > max) max = next;
}
cout << min << "   " << max << endl;
}
*/



/* write a program that reads x and calculates summation i=1 to x of i^2
 
int main() {
int x;
cout << "input x" << endl;
cin >> x;
for (int i = 1; i <= x; i++) {
	f = f + (i*i) ;
}
cout << f << endl;
}
*/



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



/*Write a program that reads a number and produces a grid where the diagonal says "match" otherwise outputs "nope". example:
 * 3
 * match nope nope
 * nope match nope
 * nope nope match 

int main () {
	int n;
	cout << "input n" << endl;
	cin >> n;
	for (int i = 0; i < n ; i++) {
		for (int j = 0; j < n ; j++) {
			if (i==j) cout << "Match " ;
			else cout << "Nope " ;
		}
		cout << endl; }
}
*/
