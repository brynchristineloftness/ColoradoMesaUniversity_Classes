#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
#include "playaround.h"
#include "playaround.cpp"

int main() {
	playclass1 a;
	playclass2 b;
	ofstream outf("playing.ot");
	outf << "Object has width = " << a.width << " length = " << a.length << endl;
	outf << "Object has width = " << b.getwidth() << " length = " << b.getlength() << endl << endl;
	playclass1 x(5.125 , 3.050);
	playclass2 y(21.375 , 15.125);
	x.printem(outf);
	y.printem(outf);
	double area = 0;
	area = x.width * x.length;
	outf << "The area of Playclass1 object x is " << area << endl << endl;
	area = y.getwidth() * y.getlength();
	outf << "The area of Playclass 2 object y is " << area << endl << endl;
	a.width=10.0;
	a.length=2.638;
	area = a.width * a.length;
	outf << "The area of Playclass1 object a is " << area << endl << endl;
	b.setwidth(25.25);
	b.setlength(11.125);
	area = b.getwidth() * b.getlength();
	outf << "The area of Playclass 2 object b is " << area << endl << endl;
	system("pause");
	return 0;
}

	
