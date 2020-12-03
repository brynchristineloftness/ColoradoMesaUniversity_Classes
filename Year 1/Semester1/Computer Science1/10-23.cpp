#include <iostream>

using namespace std;

int bank[20];

void initialValues(int initialAmount=100) {
	for (int i=0; i<20; i++) {
		bank[20] = initialAmount; }
}

int randomAccount() {
	return rand() % 20;
}

int maximumDealAllowed(int account1, int account2) {
	if (bank[account1] > bank[account2]) {
		return bank[account2];
	}
	else {
		return bank[account1];
	}
}

void transfer(int toAccount, int fromAccount, int amount) {
	bank[toAccount] = bank[toAccount] + amount;
	bank[fromAccount] = bank[fromAccount] - amount;
}

void showAccounts() {
	for (int i=0;i<20;i++){
		cout << i << bank[i] << endl;
	}
}

int main() {
	int numTransaction = 1000;
	initialValues();
	cout << "In the beginning" << endl;
	showAccounts();
	for (int i=0; i < numTransaction; i++) {
		int account1 = randomAccount();
		int account2 = randomAccount();
		int maxDeal = maximumDealAllowed(account1,account2);
		int dealAmount = rand() % maxDeal;
		int direction = rand() % 100;
		if (direction < 50) {
			transfer(account1, account2, dealAmount);
		}
		else {
			transfer(account2, account1, dealAmount);
		}
	}
	cout << "After Transactions" << endl;
	showAccounts();
return 0;
}
