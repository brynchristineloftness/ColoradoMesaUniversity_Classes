#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int maxstack = 100;
const char initstack = '$';

void CreateStack(char Stack[], int &top) {
for (int i=0;i<maxstack;i++) Stack[i]=initstack;
top = -1; }
	
int priority(char oper) {
	if (oper == '+') return 2;
	else if (oper == '-') return 2;
	else if (oper == '/') return 4;
	else if (oper == '*') return 4;
	else return 100;
}
	
bool EmptyStack(int top) {
return top < 0; }

bool FullStack(int top) {
return top>=maxstack-1;
}

char pop(char Stack[], int &top) {
char temp = initstack;
if (!EmptyStack(top)) {
		temp = Stack[top];
		Stack[top] = initstack;
		top--;
	}
return temp;
}

void push(char Stack[], int &top, char data) {
if (!FullStack(top)) {
	top++;
	Stack[top]=data;}
else cout << "Stack is full" << endl;
}

void ReadFileandWriteFile(char Stack[], int top) {
ifstream inf;
inf.open("infileinfixtorpn.txt");
ofstream outf;
outf.open("outfileinfixtorpn.txt");
string instring;
char ch;
outf << setw(10) << "Infix" << setw(22) << setfill(' ') << " " << setw(8) << "RPN" << endl;
outf << setw(15) << setfill('-') << "-" << setw(15) << setfill(' ') << " " << setw(15) << setfill('-') << "-" << endl;
	while (!inf.eof()) {
		inf >> instring>>ws;
		string outstring;
		for (unsigned int i =0; i < instring.length(); i++) {
			ch = instring[i];
			if (ch >= 'a' && ch <= 'z') {outstring += ch;}
			else {
				if (EmptyStack(top)) {
					push(Stack, top, ch);}
				else {
					if (priority(ch) > priority(Stack[top])) {
						push(Stack, top, ch); }
					else {
						while(!EmptyStack(top) && priority(ch) <= priority(Stack[top])) {
							outstring += pop(Stack,top); }
							push(Stack, top, ch); 
						 }
					}
				} 
			}
		while (!EmptyStack(top)) { outstring += pop(Stack,top); } 
		outf << setw(2) << setfill(' ') << " " << setw(15) << setfill(' ') << left << instring;
		outf << setw(15) << setfill(' ') << " " << setw(10) << outstring << endl;
		}
}


int main() {
char Stack[maxstack];
int top;
CreateStack(Stack, top);
ReadFileandWriteFile(Stack,top);
}
