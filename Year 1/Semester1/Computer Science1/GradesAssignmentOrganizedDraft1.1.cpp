#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

//Initialize Variables
const int MaxStudents = 20;
const int MaxGrades = 10;
float ActualNumberofStudents;
float ActualNumberofGrades;
float grades[MaxStudents][MaxGrades];
float average[MaxStudents];
float AverageGrade = 0;
float CurrentTotal = 0;
float FinalTotal = 0;
float ClassAverage = 0;
float ClassOverallGrade = 0;
float LengthofLineHeader = 0;
float MaxLastNameStringLength = 0;
float MaxFirstNameStringLength = 0;
char FinalLetterGrade;
string FirstName[MaxStudents];
string LastName[MaxGrades];


void ReadFilewithGrades (istream &inFile) {
	for (int t = 0;t < ActualNumberofStudents; t++) {
		CurrentTotal = 0;
		inFile >> FirstName[t] >> LastName[t];
		for (int q = 0; q < ActualNumberofGrades; q++){
			inFile >> grades[t][q];
			CurrentTotal += grades[t][q];
		}
	average[t] = CurrentTotal/ActualNumberofGrades;
	}
}

bool ValidFile() {
if (ActualNumberofStudents > MaxStudents || ActualNumberofGrades > MaxGrades)
return false;
else return true;
}

void FindingColumnLengthFirstName() {
unsigned int MaxFirstNameStringLength = 0;
for (int y = 0; y < ActualNumberofStudents; y++) {
		if (MaxFirstNameStringLength < FirstName[y].size()) {
			MaxFirstNameStringLength = FirstName[y].size(); }
}
MaxFirstNameStringLength=MaxFirstNameStringLength + 3;
}

void FindingColumnLengthLastName() {
unsigned int MaxLastNameStringLength = 0;
for (int j = 0; j < ActualNumberofStudents; j++) {
		if (MaxLastNameStringLength < LastName[j].size()) {
			MaxLastNameStringLength = LastName[j].size(); }
}
MaxLastNameStringLength=MaxLastNameStringLength + 3;
}

char ConvertAveragetoLetterGrade(float AvgGrade) {
	char Final;
	if (AvgGrade >= 90.0) { Final = 'A';
    } else if ( AvgGrade >= 80.0 ) { Final = 'B';
    } else if ( AvgGrade >= 70.0 ) { Final = 'C';
    } else if ( AvgGrade >= 60.0 ) {Final = 'D';
    } else { Final = 'F'; }
return Final;
}

int main () {
	ifstream startfile;
	startfile.open ("Grades.txt");
	ofstream outFile;
	outFile.open ("Gradesout.txt");
	startfile >> ActualNumberofStudents >> ActualNumberofGrades;
	if (!ValidFile()) { cout << "Invalid File";  }
	else {
		ReadFilewithGrades(startfile);
		
//Begin Writing File
int FirstNameColumnLength = MaxFirstNameStringLength;
int LastNameColumnLength = MaxLastNameStringLength;
outFile << left << setw(FirstNameColumnLength) << "First";
outFile << setw(LastNameColumnLength) << "Last";
for (int u = 0; u < ActualNumberofGrades; u++) {
	outFile << right << setw(7) << "Grade " << u+1;
}
outFile << setw(8) << "Average";
outFile << setw(5) << "Grade" << endl;
LengthofLineHeader = (FirstNameColumnLength + LastNameColumnLength + (7*ActualNumberofGrades) + 13);
outFile << setw(LengthofLineHeader) << setfill('-')<< '-'<< setfill(' ')<<endl;
for (int c = 0; c < ActualNumberofStudents; c++) {
	outFile << left << setw(FirstNameColumnLength)<<FirstName[c];
	outFile << setw(LastNameColumnLength) << LastName[c];
	for (int u = 0;u < ActualNumberofGrades;u++) {
		outFile << right << fixed << setprecision(2) << grades[c][u];
	}
	outFile << setw(8) << average[c];
	outFile << setw(2) << ConvertAveragetoLetterGrade(average[c]) << endl;
}
outFile << endl;
outFile << setw(LengthofLineHeader)<< setfill('-')<< '-'<< setfill(' ')<< endl;
outFile << setw(FirstNameColumnLength + LastNameColumnLength) << "Class Averages:";
for (int i = 0; i< ActualNumberofGrades; i++) {
	CurrentTotal = 0;
	for (int b = 0; b < ActualNumberofStudents; b++) {
		CurrentTotal += grades[b][i];
	}
	ClassAverage = ActualNumberofStudents/CurrentTotal;
	outFile << setw(8) << ClassAverage;
	FinalTotal += ClassAverage;
}
ClassOverallGrade = FinalTotal/ActualNumberofGrades;
outFile << setw(8) << ClassOverallGrade << setw(2) << ConvertAveragetoLetterGrade(ClassOverallGrade) << endl;
}	
startfile.close();
outFile.close();
return 0;
}
