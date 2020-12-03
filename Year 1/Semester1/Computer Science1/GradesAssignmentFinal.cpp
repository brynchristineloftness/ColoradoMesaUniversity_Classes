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
//int FirstNameColumnLength = MaxFirstNameStringLength;
//int LastNameColumnLength = MaxLastNameStringLength;
outFile << left << setw(12) << "First";
outFile << setw(13) << "Last";
for (int u = 0; u < ActualNumberofGrades; u++) {
	outFile << left << "Grade" << u+1 << setw(4) <<"  " ;
}
outFile << setw(10) << "Average";
outFile << setw(9) << "Grade" << endl;
LengthofLineHeader = (12 + 18 + (10*ActualNumberofGrades) + 10);
outFile << setw(LengthofLineHeader) << setfill('-')<< '-'<< setfill(' ')<<endl;
for (int c = 0; c < ActualNumberofStudents; c++) {
	outFile << left << setw(12)<<FirstName[c];
	outFile << setw(14.5) << LastName[c];
	for (int u = 0;u < ActualNumberofGrades;u++) {
		outFile << left << fixed << setprecision(1) << setw(8) << grades[c][u] << "  ";
	}
	outFile << setw(10) << average[c];
	outFile << setw(9) << ConvertAveragetoLetterGrade(average[c]) << endl;
}
outFile << endl;
outFile << setw(LengthofLineHeader)<< setfill('-')<< '-'<< setfill(' ')<< endl;
outFile << left << setw(5) <<" "<< "Class Averages:";
for (int i = 0; i< ActualNumberofGrades; i++) {
	CurrentTotal = 0;
	for (int b = 0; b < ActualNumberofStudents; b++) {
		CurrentTotal += grades[b][i];
	}
	ClassAverage = ActualNumberofStudents/CurrentTotal;
	outFile << setw(6) << setprecision(2) << " " << ClassAverage;
	FinalTotal += ClassAverage;
}
ClassOverallGrade = FinalTotal/ActualNumberofGrades;
outFile << setw(6) << " " << ClassOverallGrade << setw(6) << " " << ConvertAveragetoLetterGrade(ClassOverallGrade) << endl;
}	
startfile.close();
outFile.close();
return 0;
}
