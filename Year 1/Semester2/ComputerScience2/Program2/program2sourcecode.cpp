#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;


struct listtype {
string last;
string first;
int id;
listtype *link; };

void PrintTopTitles(ofstream &outf) {
outf << setw(13) << setfill(' ') << right << " " << "CSCI 112" << endl;
outf << setw(12) << setfill (' ') << right << " " << "Class List" <<endl;
outf << setw(35) << setfill('-') << right << "- " << endl;
outf << setw(6) << setfill(' ') << left << "ID" << " " << "Name" << endl;
outf << setw(35) << setfill('-') << right << "- " << endl;
}

void PrintBottomTitles(ofstream &outf) {
outf << setw(35) << setfill('-') << right << "- " << endl;
}

void CreateList(listtype *&head, listtype *&tail) {
	head = new listtype;
	tail = new listtype;
	head -> last = "  AAAA";
	tail -> last = "zzzzzz";
	head -> link = tail;
	tail -> link = NULL;
}

bool EmptyList(listtype *head, listtype *tail) {
	return (head -> link == tail);
}

void InsertList(listtype *head, listtype *tail, string last, string first, int id) {
	listtype *before, *after, *insert;
	insert = new listtype;
	insert -> last = last;	
	insert -> first = first;
	insert -> id = id;
	before = head;
	after = head -> link;
	while (after != tail && insert->last > after->last) {
		before = after;
		after = after -> link; }
	before -> link = insert;
	insert -> link = after;
}

void ReadData(listtype *head, listtype *tail) {
int id;
string last, first;
ifstream inf;
inf.open("program2datafile.txt");
int position = -1;
	while (!inf.eof()) {
		inf >> last >> first >> id >> ws;
		position = last.find(",");
		if (position >=0) last.erase(position,1);
		InsertList(head, tail, last, first, id);
	}
}

void TraverseList(listtype *head, listtype *tail, ofstream &outf) {
	listtype *c;
	string temp;
	if (!EmptyList(head, tail)) {
		PrintTopTitles(outf);
		c = head -> link;
		while (c!= tail) {
			temp = c -> first + " " + c -> last;
			outf << setw(6) << setfill(' ') << left << c->id << " " << temp << endl;
			c = c-> link;
		}
	PrintBottomTitles(outf);
	}
	else outf << "The List Is Empty" << endl;	
}

void DeletefromList(listtype *head, listtype *tail, string last, string first, int id, ofstream &outf){
	listtype *before, *next, *c;
	before = head;
	c = head -> link;
	next = c-> link;
	while (c!=tail && c->last < last) {
		before = c;
		c = next;
		next = next -> link; }
	if (c!=tail && c->last == last) {
		before -> link = next;
		delete c; }
	else {
		outf << "Element not in list" ;
		}
}

void PrintSpaces(ofstream &outf) {
	outf << endl << endl << endl << endl;
}

int main(){
ofstream outf;
outf.open("program2outputfile.txt");
listtype *head, *tail;
CreateList(head,tail);
ReadData(head, tail);
TraverseList(head,tail,outf);
PrintSpaces(outf);
InsertList(head, tail, "Skywalker", "Luke", 444);
TraverseList(head,tail,outf);
outf << "Luke Skywalker, ID #444, was added to the class." << endl;
PrintSpaces(outf);
DeletefromList(head, tail, "Organa", "Leia", 355, outf);
TraverseList(head, tail, outf);
outf << "Leia Organa, ID #355, was deleted from the class." << endl;
outf << endl;
system("pause");
}
