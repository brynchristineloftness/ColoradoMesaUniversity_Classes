#include <iostream>
using namespace std;
/*
int main() {
float sum=0;
float maxvalue = 100000000000;
for (int j=1;j<= maxvalue;j++) {
	sum=sum+(1/j);
	cout << sum << endl; }
return 0;
}
*/
 
#include <iostream>
using namespace std;

int main() {

int sum=0;
int n=1;

while (n != 0) {
	n++;
	sum=sum+(1/n);
	cout << sum << endl; 
}
return 0;
}
