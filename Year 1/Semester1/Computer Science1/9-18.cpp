#include <iostream>

using namespace std;

int main (){
	int N;
	cout << "Enter total numbers to be entered." << endl;
	cin >> N;
	for (int i=0; i < N; i++) {
		int Number;
		//cout << "Enter a number." << endl;
		cin >> Number;
		bool Good = true;
		//cout << Number << '	'; 
		if (Good) 	cout << "Yes";
		else 		cout << "No";
	}
	return 0;
}
