#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
ifstream inf;
ofstream outf;
inf.open("datafile.txt");
outf.open("outputfile.txt");
vector<int> intveclist;
vector <int>::iterator intveclistiterator;
float num=0;
outf << "Read In Data File:" << endl;
while (!inf.eof()){
	inf >> num >> ws;
	intveclist.push_back(num);
}
for (intveclistiterator = intveclist.begin(); intveclistiterator != intveclist.end(); intveclistiterator++) {
	outf << *intveclistiterator << " ";
}
outf << endl;
outf << "Impliment Sort Algorithm:" << endl;
sort(intveclist.begin(),intveclist.end());
for (intveclistiterator = intveclist.begin(); intveclistiterator != intveclist.end(); intveclistiterator++) {
	outf << *intveclistiterator << " ";
} 
}
