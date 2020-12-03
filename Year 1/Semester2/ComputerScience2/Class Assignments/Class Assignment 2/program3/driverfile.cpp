#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <queue>

using namespace std;

struct bryntype {
	int numberofmajors;
	string fieldofstudy;
};

int main() {
ifstream inf;
ofstream outf;
inf.open("datafile.txt");
outf.open("outputfile.txt");
queue<bryntype> intstringqueue;
bryntype classdata;
while (!inf.eof()){
	inf >> classdata.numberofmajors >> classdata.fieldofstudy >> ws;
	intstringqueue.push(classdata);
}
outf << "Number of elements in queue: " << intstringqueue.size() << endl;
outf << "Elements in queue: " << endl;
while (!intstringqueue.empty()) {
	outf << setw(12) << left << intstringqueue.front().fieldofstudy << " " << intstringqueue.front().numberofmajors << endl;
	intstringqueue.pop();
}
outf << endl;
system("pause");
}


