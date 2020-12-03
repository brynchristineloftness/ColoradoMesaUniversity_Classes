#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

struct bryntype{
int x;
string y;
};


template <class Bryn>
void swapme(Bryn &first, Bryn &second) {
Bryn temp = first;
first = second;
second = temp;
}

int main() {
ofstream outf;
outf.open("outputfile.txt");
int j = 3;
int t = 5;
outf << "integer j = " << j << " and integer t = " << t << "." << endl;
outf << "Inititating Swapme Function" << endl;
swapme(j,t);
outf << "integer j = " << j << " and integer t = " << t << "." << endl << endl;
string name1 = "John";
string name2 = "Jane";
outf << "string name1 = " << name1 << " and string name2 = " << name2 << "." << endl;
outf << "Inititating Swapme Function" << endl;
swapme(name1,name2);
outf << "string name1 = " << name1 << " and string name2 = " << name2 << "." << endl << endl;
bryntype firststruct = {1234, "Link"};
bryntype secondstruct = {9894, "Zelda"};
outf << "firststruct.x = " << firststruct.x << " and firststruct.y = " << firststruct.y << "." << endl;
outf << "secondstruct.x = " << secondstruct.x << " and secondstruct.y = " << secondstruct.y << "." << endl;
outf << "Inititating Swapme Function" << endl;
swapme(firststruct,secondstruct);
outf << "firststruct.x = " << firststruct.x << " and firststruct.y = " << firststruct.y << "." << endl;
outf << "secondstruct.x = " << secondstruct.x << " and secondstruct.y = " << secondstruct.y << "." << endl;
system("pause");
}

