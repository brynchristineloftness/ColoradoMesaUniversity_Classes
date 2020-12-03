#pragma once

class playclass1 {
public:
	double length, width;
	playclass1();
	playclass1(double l, double w);
	void printem(ofstream &outf);
};

class playclass2 {
private:
	double length, width;
public:
	void setlength(double l);
	void setwidth(double w);
	void printem(ofstream &outf);
	double getlength();
	double getwidth();
	playclass2();
	playclass2(double l, double w);
};

