#include <fstream>
using namespace std;
#include "playaround.h"

playclass1::playclass1() {
length = 2.0;
width = 1.0; }

playclass2::playclass2(){
length = 4.0;
width = 2.0; }

double playclass2::getlength() {
return length; }

double playclass2::getwidth() {
return width; }

void playclass2::setlength(double l) {
length = l; }

void playclass2::setwidth(double w) {
width = w; }

playclass1::playclass1(double l, double w) {
length = l;
width = w;
}

playclass2::playclass2(double l, double w){
length = l;
width = w;
}

void playclass1::printem(ofstream &outf) {
outf.setf(ios::fixed);
outf.precision(3);
outf << "PlayClass1 object has:  length = " << length << " and width = " << width << endl << endl; }

void playclass2::printem(ofstream &outf) {
outf.setf(ios::fixed);
outf.precision(3);
outf << "PlayClass2 object has:  length = "<< length << " and width = "<< width << endl << endl; }
