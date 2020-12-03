#include <iostream>
#include <string>

using namespace std;

	
int main() {
    float Math;
    float English;
    float History;
    float Health;
    float Average;
    string Name;
    cout << "What is your name?" << endl;
    cin >> Name;
    cout << "Please enter average test score for Math" << endl;
    cin >> Math;
    cout << "Please enter average test score for English" << endl;
    cin >> English;
    cout << "Please enter average test score for History" << endl;
    cin >> History;
    cout << "Please enter average test score for Health" << endl;
    cin >> Health;
    Average = (Math + English + History + Health) / 4.0;
    //Start Math Grade Calculation;
    if (Math > 90.0) { 
        cout << "You got an A in Math!"<< endl;
    }
    else if (Math > 80.0) {
        cout << "You got a B in Math!"<< endl;
    }
    else if (Math > 70.0) {
        cout << "You got a C in Math!"<< endl;
    }
    else if (Math > 60.0) {
        cout << "You got a D in Math!" << endl;
    }
    else {
        cout << "You got a F in Math!" << endl;
    }
    //Start English Grade Calculation
    else if (English > 90.0) { 
        cout << "You got an A in English!" << endl;
    }
    else if (English > 80.0) {
        cout << "You got a B in English!" << endl;
    }
    else if (English > 70.0) {
        cout << "You got a C in English!" << endl;
    }
    else if (English > 60.0) {
        cout << "You got a D in English!" << endl;
    }
     else {
        cout << "You got a F in English!" << endl;
    }
    //Start History Grade Calculation
    else if (History > 90.0) { 
        cout << "You got an A in History!" << endl;
    }
    else if (History > 80.0) {
        cout << "You got a B in History!" << endl;
    }
    else if (History > 70.0) {
        cout << "You got a C in History!" << endl;
    }
    else if (History > 60.0) {
        cout << "You got a D in History!" << endl;
    }
    else {
        cout << "You got a F in History!" << endl;
    }
    //Start Health Grade Calculation
    else if (Health > 90.0) { 
        cout << "You got an A in Health!" << endl;
    }
    else if (Health > 80.0) {
        cout << "You got a B in Health!" << endl;
    }
    else if (Health > 70.0) {
        cout << "You got a C in Health!" << endl;
    }
    else if (Health > 60.0) {
        cout << "You got a D in Health!" << endl;
    }
    else {
        cout << "You got a F in Health!" << endl;
    }
    //Start Average Grade Calculation
    cout << "Your overall grade is..." << endl;
    if (Average > 90.0) { 
        cout << "You got an A!" << endl;
    }
    else if (Average > 80.0) {
        cout << "You got a B!" << endl;
    }
    else if (Average > 70.0) {
        cout << "You got a C!" << endl;
    }
    else if (Average > 60.0) {
        cout << "You got a D!" << endl;
    }
    else {
        cout << "You got a F!" << endl;
    }
	return 0;
}
