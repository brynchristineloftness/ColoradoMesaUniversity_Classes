#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>

using namespace std;

const int maxnum = 10000;
const double bound = 50000.0;

int main() {
double num;
double method;
int i = 0;
ofstream outf;
outf.open("outputfile.txt");
//Variables For Checking Random-ness:
int positive = 0, negative = 0, lowestfourth = 0, lowerfourth= 0, higherfourth= 0, highestfourth=0;

while (i<maxnum) {
	method = rand()%6+1;
	if (method ==1) {num = rand() / cos(num);}
	if (method ==2) {num = rand() / cos(num) + num;}
	if (method ==3) {num = rand() / cos(num) -rand();}
	if (method ==4) {num = rand() /cos(num) *-1;}
	if (method ==5) {num = rand() * cos(num);}
	if (method ==6) {num = rand() / cos(num) +rand();}
	
	if (abs(num) < bound) {
		outf << fixed << setprecision(3) << setw(13) << num << endl;
		i++;
		//Calculating Randomness:
		if (num <=0) negative = negative + 1;
		else positive = positive + 1;
		if (num <= -25000 && num >= -50000) lowestfourth = lowestfourth +1;
		else if (num > -25000 && num <= 0) lowerfourth = lowerfourth + 1;
		else if (num > 0 && num <= 25000) higherfourth = higherfourth +1;
		else highestfourth++;
	}	
}
//Checking Randomness:
cout << endl << endl << "Positive: " << positive << endl;
cout << "Negative: " << negative << endl;
cout << "Lowestfourth: " << lowestfourth << endl;
cout << "Lowerfourth: " << lowerfourth << endl;
cout << "Higherfourth: " << higherfourth << endl;
cout << "Highestfourth: " << highestfourth << endl;
system("pause");
}
