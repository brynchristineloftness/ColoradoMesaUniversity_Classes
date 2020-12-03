#pragma once
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
