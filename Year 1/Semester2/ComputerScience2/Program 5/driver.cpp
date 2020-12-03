#include <fstream>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "header.h"
#include "implementation.cpp"

int main() {
ifstream inf("inputfile.txt");
ofstream outf("outputfile.ot");

while (!inf.eof()) {
	RatNum firstfrac;
	RatNum secondfrac;
	inf >> firstfrac >> secondfrac;
	RatNum sumanswer, differenceanswer, productanswer, quotientanswer;
	sumanswer = firstfrac + secondfrac;
	differenceanswer = firstfrac - secondfrac;
	productanswer = firstfrac * secondfrac;
	quotientanswer = firstfrac / secondfrac;
	outf << "Calculations for " << firstfrac << " and " << secondfrac << endl;
	outf << setw(40) << left << "The sum of the two fractions is " <<  sumanswer << endl;
	outf << setw(40) << left << "The difference of the two fractions is " <<   differenceanswer << endl;
	outf << setw(40) << left << "The product of the two fractions is " <<  productanswer << endl;
	outf << setw(40) << left << "The quotient of the two fractions is " << quotientanswer << endl;
	outf << endl << endl;
	}
		
system("pause");	
}
