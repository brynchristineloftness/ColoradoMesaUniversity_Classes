#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
	float amount;
	int totalPayments;
	float rate;

	cout << "Enter the amount: ";
	cin >> amount;
	cout << "Enter the number of payments: ";
	cin >> totalPayments;
	cout << "Enter the rate as a percentage per year: ";
	cin >> rate;

	rate /= 100; //makes the rate into decimal form

	double monthlyRate;

	double monthlyAmount;

	double monthlyInterest;

	double principlePaid;

	cout << setw(20) << "Month:" << setw(20) << "Payment Required:" << setw(20) << "Principal Payed:" << setw(20) << "Interest Payment:" << setw(20) << "Remaining Balance:" << endl;
	cout << setw(20) << 0 << setw(20) << ' ' << setw(20) << ' ' << setw(20) << ' ' << setw(20) << amount << endl;

	for (int i = 0; i < totalPayments; i++) {

		monthlyRate = pow(1 + rate, 1.0 / 12) - 1;

		if (i == 0) monthlyAmount = (amount * monthlyRate) / (1 - pow(1 + monthlyRate, -totalPayments));

		monthlyInterest = amount * monthlyRate;

		principlePaid = monthlyAmount - monthlyInterest;
		if (i == totalPayments - 1) {
			monthlyAmount -= monthlyInterest;
			principlePaid = amount;
		}

		amount -= principlePaid;

		cout << fixed;
		cout << setw(20) << setprecision(2) << i + 1 << setw(20) << monthlyAmount << setw(20) << principlePaid << setw(20) << monthlyInterest << setw(20) << amount << endl;


	}

    return 0;
}

