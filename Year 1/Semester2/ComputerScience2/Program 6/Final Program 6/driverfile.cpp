#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

const int maxnum = 10000;
double numofcompares = 0;
double numofmoves = 0;


void printsort(ofstream &outf, string &sortname, double array[]){
float increment = 1000;
int j = 1;
outf <<  sortname << " " << " " << "N = " << maxnum << endl;
for (int i =0; i < maxnum; i+=increment) {
	outf << setw(13) << fixed << setprecision(3) << array[i];
	j++;
	if (j>5) {
		outf << endl;
		j = 1; } }
outf << endl <<  fixed << setprecision(0) << "Number of Compares = " << numofcompares << " ";
outf <<  fixed << setprecision(0) << " Number of Moves = " << numofmoves;
outf << endl << fixed << setprecision(4) << "Relative # of Compares = " << numofcompares/maxnum << " ";
outf << fixed << setprecision(4) << " Relative # of Moves = " << numofmoves/maxnum << endl;
outf << endl << endl;
}

void swapme(double &a, double &b) {
double temp = a;
a = b;
b = temp;
numofmoves+= 3;
}
	
void BubSort(double array[]) {
	for (int y = 0; y < maxnum-1; y++){
		for (int b = 0; b < maxnum - 1; b++) {
			numofcompares++;
			if (array[b] > array[b+1]) {
				swapme(array[b], array[b+1]); } } }
}

void SelSort(double array[]) {
	int min, k, j;
	for (k = 0; k < maxnum-1; k++) {
		min = k;
		for (j=k+1; j < maxnum; j++){
			numofcompares++;
			if (array[j] < array[min]) { min = j; } }
			swapme(array[k], array[min]);}
}

void InsSort(double array[]) {
double save;
int k, j;
for (k=maxnum-2; k >=0; k--) {
	j=k+1;
	save = array[k];
	numofmoves++;
	array[maxnum+1] = save;
	numofmoves++;
	numofcompares++;
	while (save > array[j]) {
		numofcompares++;
		array[j-1] = array[j];
		numofmoves++;
		j = j+1; }
	array[j-1]=save;
	numofmoves++; }
}

void QuiSort(double array[],int left, int right) {
int j, k;
numofcompares++;
if (left < right) {
	j= left;
	k= right + 1;
	do{
		do{numofcompares++; j++;} while((j<k) && array[j] < array[left]);
		do{numofcompares++; k--;} while((k>=0) && array[k] > array[left]);
		numofcompares++;
		if (j<k) { swapme(array[j],array[k]); }
	} while(j<=k);
	swapme(array[left],array[k]);
	QuiSort(array,left,k-1);
	QuiSort(array,k+1,right); }
}

int main() {
double RandNums[maxnum+1];
ofstream outf;
outf.open("outputfile.txt");
string sortname = "No Sort Routine Implemented";		
for (int i =0; i < 4; i++) {
	ifstream inf;
	inf.open("infilerandnums.txt");	
	numofcompares=0;
	numofmoves=0;
	for (int k = 0; k < maxnum; k++) {
		inf >> RandNums[k] >> ws; }
	if (i==0) {
		sortname = "Bubble Sort";
		BubSort(RandNums); }
	else if (i==1) {
		sortname = "Selection Sort";
		SelSort(RandNums); }
	else if (i==2) {
		sortname = "Insert Sort";
		InsSort(RandNums); }
	else {
		sortname = "Quick Sort";
		QuiSort(RandNums,0, maxnum); }
	printsort(outf, sortname, RandNums);
	}
system("pause");
}

