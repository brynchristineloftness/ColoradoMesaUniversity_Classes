#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int maxc = 30;

struct CityHighSchool
{
int crn;
string course;
int crhrs, numstu;
string prof;
int stucrhrs;
};

const CityHighSchool initrec = { 0 , "Course" , 0 , 0 , "Professor" , 0 };

void initialize(CityHighSchool C[], int &numc) {
int i;
for (i=0; i < maxc; i++) C[i] = initrec;
numc = 0;
}

void read(CityHighSchool C[], ifstream &inf, int &numc ) {
int curnum = 0;
while (!inf.eof()) {
inf >> C[curnum].crn >> C[curnum].course >> C[curnum].crhrs >> C[curnum].numstu >> C[curnum].prof >> ws;
curnum++; 
}
numc = curnum;
}

void computestucrhrs(CityHighSchool C[], int numc) {
for (int j=0; j<numc; j++) {
	C[j].stucrhrs = C[j].crhrs * C[j].numstu; }
}

int computetotalcrhrs(CityHighSchool C[], int numc) {
int totalcredithours = 0;
for (int i=0; i < numc; i++) {
totalcredithours += C[i].crhrs; }
return totalcredithours;
}

int computetotalnumofstudents(CityHighSchool C[], int numc) {
int totalnumofstudents = 0;
for (int i=0; i < numc; i++) {
totalnumofstudents += C[i].numstu; }
return totalnumofstudents;
}

int computetotalstucrhrs(CityHighSchool C[], int numc) {
int totalstucrhrs = 0;
for (int i=0; i < numc; i++) {
totalstucrhrs += C[i].stucrhrs; }
return totalstucrhrs;
}

void print(CityHighSchool C[], int numc, ofstream &outf) {
outf<< setw(21) <<" " << "City High School - Mathematics Department" << endl;
outf << right << setw(5) << "CRN" << setw(14) << "Course";
outf << setw(16) << "Credit Hrs" << setw(15) << "Stu. Count";
outf << setw(13) << "Professor" << setw(17) << "Sum Credit Hrs" << endl;
outf << setw(80) << setfill('-') << '-' << setfill(' ') << endl;
for (int i=0; i < numc; i++) {
	outf << " " << left << setw(12)<< C[i].crn;
	outf << left<< setw(16) << C[i].course << " ";
	outf << left << setw(13) << C[i].crhrs;
	outf << left << setw(10) << C[i].numstu << " ";
	outf  << setw(16) << C[i].prof;
	outf << right << setw(3) << C[i].stucrhrs << endl; }
outf << setw(80) << setfill('-') << '-' << setfill(' ') << endl;
outf << right << setw(11) << " " << "Totals:";
outf << setw(13) << computetotalcrhrs(C, numc);
outf << setw(14) << computetotalnumofstudents(C, numc);
outf << setw(28) << computetotalstucrhrs(C, numc);
outf << endl << endl;
}

void swap(CityHighSchool &x, CityHighSchool &y) {
	CityHighSchool temp;
	temp = x;
	x=y;
	y = temp;
}

void sortbystucrhrs(CityHighSchool C[], int numc) {
int a, b;
for (b = 0; b < numc - 1; b++) {
	for (a = 0; a < numc - 1; a++) {
		if (C[a].stucrhrs > C[a+1].stucrhrs) {
			swap(C[a], C[a+1]); } } }
}

void sortbyalpha(CityHighSchool C[], int numc) {
for (int i = 0; i< numc -1; i++) {
	for (int j = 0; j < numc - 1; j++) {
		if (C[j].course < C[j+1].course) {
			swap(C[j], C[j+1]); } } }
}

void computeavgstu(CityHighSchool C[], int numc, ofstream &outf) {
int TotalStu=0;
for (int i=0; i< numc; i++) {
	TotalStu +=	C[i].numstu; }
int OverallAvg = TotalStu/numc;
outf << endl << "The average number of students in each section within the Math Department is " << OverallAvg << ".";
outf << endl;
}

void dividesubjects(CityHighSchool C[], int numc, ofstream &outf) {
string previouscourse = C[0].course;
int totalnumstu = C[0].numstu;
int countofsections = 1;
outf << endl << endl;
outf << "City High School - Mathematics Department" << endl;
outf << setw(2) << " " << "Number of Students by Course Subject" << endl;
outf << setw(1) << " "<< setw(23) << left << "Course" << setw(2) << "Num of Students" << endl;
outf << setw(40) << setfill('-') << '-' << setfill(' ') << endl;
for (int i=1; i<numc;i++) {
	if (C[i].course == previouscourse) {
		totalnumstu = totalnumstu + C[i].numstu;
		countofsections++; }
	else {
		outf << setw(1) << " " << setw(26) << left << C[i-1].course;
		outf << right << setw(12) << totalnumstu << endl;
		previouscourse = C[i].course;
		totalnumstu = C[i].numstu;
		countofsections = 1; } } 
outf << setw(1) << " " << setw(26) << left << previouscourse;
outf << right << setw(12) << totalnumstu << endl;
outf << setw(40) << setfill('-') << '-' << setfill(' ') << endl;
}

	
int main(){
CityHighSchool C[maxc];
int numc;
ifstream inf;
inf.open("datafile.txt");
ofstream outf;
outf.open("outputfile.txt");
initialize(C, numc);
read(C, inf, numc);
computestucrhrs(C, numc);
print(C, numc, outf);
sortbystucrhrs(C, numc);
print(C, numc, outf);
sortbyalpha(C, numc);
computeavgstu(C, numc, outf);
dividesubjects(C, numc, outf);
system("pause");
return 0;
}
