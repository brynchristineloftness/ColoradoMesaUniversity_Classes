#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string findShort(string longName) {
	stringstream out;
	for (unsigned int i=0 ; i < longName.size() ; i++) {
		if (longName[i] >= 'A' && longName[i] <= 'Z') {
		out << longName[i];
		}
	}
return out.str();
}

int main() {
		string name;
		cout << "Please enter your name, make sure to use dashes." << endl;
		cin >> name;
		cout << findShort(name) << endl;
	return 0;
}

