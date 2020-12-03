#include <iostream>

using namespace std;

int main() {
	// Inputs
	int Length, Width;
	// Outputs
	int Area,Perimeter;
	cout<<"Hey user enter Length and Width" <<endl;
	cin>> Length >> Width;
	Area=Lenth*Width;
	Perimeter=2*Length+2*Width;
	cout << "Area is " << Area << endl;
	cout << "Perimeter is " << Perimeter << endl;
	return 0;
}
