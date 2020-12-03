#include <fstream>
using namespace std;
#include "header.h"

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
		den = 1; 
		cout << "Error! Denominator cannot be 0!";}
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
		int xnum = x.num;
		int ynum = y.num;
		int xden = x.den;
		int yden= y.den;
		x.num = xnum * yden;
		y.num = ynum * xden;
		x.den = xden * yden;
		y.den = yden * xden; }
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
	if (y.den == 0 && y.num == 1) cout << "Error! Cannot divide by zero!";
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
