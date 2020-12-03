#include <iostream>
#include <cmath>
//Series Expansion//
using namespace std;

unsigned int factorial(unsigned int f) {
int end = 1;
for (unsigned int i = 1; i <= f; i++) {
end = end * i;
}
return end;
}


int mycos (int c) {
float cosine;
for (int k=0; k < 10; k++) {
cosine = (pow(-1.,k)) * pow(c,2*k) / factorial(2*k);
}
return cosine;
}

/*
int sin (long b) {
}

int squareroot (long c) {
}

int tan (long d) {
}


int main()
{
cout << "If you would like to compute the..." << endl;

return 0;
}

*/

int main () {
cout << mycos(5) << endl;
return 0;
}
