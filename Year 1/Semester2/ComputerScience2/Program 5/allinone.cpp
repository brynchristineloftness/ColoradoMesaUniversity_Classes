/*#include <fstream>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class RatNum {
	friend RatNum operator *(RatNum x, RatNum y);
	friend RatNum operator /(RatNum x, RatNum y);
	friend RatNum operator +(RatNum x, RatNum y);
	friend RatNum operator -(RatNum x, RatNum y);
	friend istream& operator >>(istream& insert, RatNum& number);
	friend ostream& operator <<(ostream& output, RatNum number);
	public:
		RatNum();
		RatNum(int, int);
		void printvalues(ofstream &outf);
		int getnum();
		int getden();
		void setnum(int);
		void setden(int);
		void reduceme();
	private:
		int num;
		int den;
};
RatNum operator *(RatNum x, RatNum y);
RatNum operator /(RatNum x, RatNum y);
RatNum operator +(RatNum x, RatNum y);
RatNum operator -(RatNum x, RatNum y);
istream& operator >>(istream& insert, RatNum& number);
ostream& operator <<(ostream& output, RatNum number);

RatNum::RatNum() {
	num = 0;
	den = 1;
}

RatNum::RatNum(int top, int bottom) {
	num = top;
	den = bottom; 
	if (bottom == 0){
		num = 0;
		den = 1;
		cout << "Error! Denominator cannot be 0!"; }
}

void RatNum::printvalues(ofstream &outf) {
	outf.setf(ios::fixed);
	outf << "Numerator=" << num << " " << "Denominator=" << den << " 	";
}

int RatNum::getnum(){
	return num;
}

int RatNum::getden(){
	return den;
}

void RatNum::setnum(int top){
	num = top;
}

void RatNum::setden(int bottom){
	den = bottom;
	if (bottom == 0) {
		num = 0;
		den = 1;
		cout << "Error! Denominator cannot be 0!"; }
}

void RatNum::reduceme(){
	if (den < 0) {
		den *= -1;
		num *= -1; }
	if (num == 0) {
		den = 1; }
	if (num == den) {
		num = 1;
		den = 1;}
	if (den == 0) {
		num = 0;
		den = 1; }
	int stophere = min(abs(num),abs(den));
	for (int i = stophere; i > 1; i--){
		if (num % i ==0 && den % i ==0) {
			num /= i;
			den /= i;}
	}
}

RatNum operator -(RatNum x, RatNum y) {
	RatNum answer;
	if (x.den != y.den) {
		x.num = x.num * y.den;
		x.den = x.den * y.den;
		y.num = y.num * x.den;
		y.den = y.den * x.den; }
	answer.num = x.num - y.num;
	answer.den = x.den;
	answer.reduceme();
	return answer;
}

RatNum operator +(RatNum x, RatNum y) {
	RatNum answer;
	answer.num = x.num * y.den + x.den * y.num ;
	answer.den = x.den * y.den;
	answer.reduceme();
	return answer;
}

RatNum operator /(RatNum x, RatNum y) {
	RatNum answer;
	if (y.num == 0) y.den = 1;	
	answer.num = x.num * y.den;
	answer.den = x.den * y.num;
	answer.reduceme();
	return answer;
}

RatNum operator *(RatNum x, RatNum y) {
	RatNum answer;
	answer.num = x.num * y.num;
	answer.den = x.den * y.den;
	answer.reduceme();
	return answer;
}

istream& operator >>(istream& insert, RatNum& number){
	char eat;
	insert >> number.num >> eat >> number.den >> ws;
	if (number.den == 0) {
		number.num = 0;
		number.den = 1;
		cout << "Error! Denominator cannot be 0!";
	}
	number.reduceme();
	return insert;
}

ostream& operator <<(ostream& output, RatNum number){
	if (number.den == 1) {
		output << number.num; }
	else output << number.num << "/" << number.den;
	number.reduceme();
	return output;
}

int min(int a, int b){
	if (a < b) return a;
	else return b; 
}

int main() {
ifstream inf("inputfile.txt");
ofstream outf("outputfile.ot");

while (!inf.eof()) {
	RatNum firstfrac;
	RatNum secondfrac;
	inf >> firstfrac >> secondfrac;
	RatNum sumanswer, differenceanswer, productanswer, quotientanswer;
	sumanswer = firstfrac + secondfrac;
	differenceanswer = firstfrac - secondfrac;
	productanswer = firstfrac * secondfrac;
	quotientanswer = firstfrac / secondfrac;
	outf << "Calculations for " << firstfrac << " and " << secondfrac << endl;
	outf << setw(40) << left << "The sum of the two fractions is " <<  sumanswer << endl;
	outf << setw(40) << left << "The difference of the two fractions is " <<   differenceanswer << endl;
	outf << setw(40) << left << "The product of the two fractions is " <<  productanswer << endl;
	outf << setw(40) << left << "The quotient of the two fractions is " << quotientanswer << endl;
	outf << endl << endl;
	}
		
system("pause");	
}
*/
