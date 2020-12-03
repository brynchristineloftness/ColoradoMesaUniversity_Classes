#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>

using namespace std;

int main() {
cout << "Hello, Welcome to Bryn's Amortization Calculator..."<< endl;
cout << endl;
//Define Variables
double A; //A=Payment Amount/Period
double P; //P=initial Principle (loan amount)
double R; //R=interest rate per period
double N; //N=total number of payments or periods

//Define Values
cout << "Please enter loan amount, (P)" << endl;
cin >> P;
cout << "Please enter annual interest rate in percent, (R)" << endl;
cin >> R;
R = R /100 ;
cout << "Please enter the loan term in years, (N)" << endl;
cin >> N;
N = N * 12;

//Begin Calculations		
double MonthlyRate;
double FirstPartofEquation;
double SecondPartofEquation;

MonthlyRate = pow((1 + R),.0833333333) - 1;
FirstPartofEquation = P * MonthlyRate;
SecondPartofEquation = (1 - pow(1+ MonthlyRate,-N));

A = (FirstPartofEquation) / (SecondPartofEquation) ;
cout << endl;
cout << "Your Payment amount per month is $" << fixed << setprecision(2) << A << endl;
cout << endl;

// Table
double MonthlyInterestAmount;
double PrincipletobePaid;

cout << setw(20) << setprecision(5) << "Payment Required" << setw(20) << "Principle Amount" << setw(20) << "Interest Amount" << setw(20) << "Remaining Balance" << endl;

while (P >= .000001) {
MonthlyInterestAmount = P * MonthlyRate;
PrincipletobePaid = A - MonthlyInterestAmount;
P = P - PrincipletobePaid;
cout << fixed;
cout << setw(20) << setprecision(2) << A << setw(20) << setprecision(2) << PrincipletobePaid << setw(20) << setprecision(2) << MonthlyInterestAmount << setw(20) << setprecision(2) << P << endl;
}

//End Table
cout << endl;
cout << "Thanks!" << endl;
return 0;	
}


