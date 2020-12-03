#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

const int MaxStudents = 20;
const int MaxGrades = 10;

float ActualNumberofStudents;
float ActualNumberofGrades;
float grades[MaxStudents][MaxGrades];
float average[MaxStudents];
float averageClass[MaxGrades];

string FirstName[MaxStudents];
string LastName[MaxGrades];
string classLetterGrade;
float AverageGrade = 0;
float FinalTotal = 0;
char FinalLetterGrade = "I";

void ConvertAveragetoGrade () {
	if (AverageGrade >= 90.0) {
    FinalLetterGrade = "A";
    } else if ( AverageGrade >= 80.0 ) {
    FinalLetterGrade = "B";
    } else if ( AverageGrade >= 70.0 ) {
    FinalLetterGrade = "C";
    } else if ( AverageGrade >= 60.0 ) {
    FinalLetterGrade = "D";
    } else {
    FinalLetterGrade = "F";
    }
}

void WritetoOutFileTopLine (ostream &outFile) { //maybe not setw//
outFile << setw(5) << "First" << "Last";
for (int i=0; i < ActualNumberofGrades; i++) {
outFile << setw(2) << Grade[i];
}
outFile << setw(1) << "Avg Score" << setw(3) << "Final Grade" << endl;
}




void ReadFilewithGrades (istream &inFile) {
	inFile >> ActualNumberofGrades >> ActualNumberofStudents;
	for (int t = 0;t < ActualNumberofStudents; t++) {
		inFile >> FirstName[t] >> LastName[t];
		for (int q = 0; q < ActualNumberofGrades; q++){
			inFile >> grade[t][q];
		}
	}
}

void WriteFilewithGrades (ostream &outFile) {
	outFile << ActualNumberofStudents << endl;
	for (int i=0; i < ActualNumberofStudents; i++)
	outFile << setw(10) << first[i];
	outFile << endl;
}


getline(inFile, FirstName," ");
getline(inFile, LastName," ");
Name = FirstName + " " + LastName


void Line () {
	cout << "---------------------------------------------------" << endl;
}

void GetNamefromFile (istream &inFile) {
	string FullLine;
	ifstream myfile;
	myfile.open ("Grades.txt");
	//Get Line
	myfile.close();
}



char Line[];

while (!myfile.eof) {
	getline(myfile,FirstName," ");
	getline(myfile,LastName," ");
	getline(myfile, /Grades/);
}

void getlinefromfile(istream, string&);

int main () {
	ifstream myfile;
	myfile.open ("Grades.txt");
	cout << "Please enter the number of students, maximum 20" << endl;
	cin << ActualNumberofStudents;
	cout << "Please enter the number of grades you would like to enter for each student" << endl;
	cin << ActualNumberofGrades;

for (int s = 0; s < ActualNumberofStudents; s++) {
	for (int g = 0; g < ActualNumberofGrades; g++) {
		cin >> grades[s][g];
		}
	}
	
myfile.close();
return 0;
}
