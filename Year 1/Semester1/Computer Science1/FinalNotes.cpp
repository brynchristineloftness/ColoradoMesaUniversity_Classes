/*Final Notes:
1/2 Multiple Choice & Short Answer (10 questions)
	> No Syntax or Intentional Errors
1/2 Programs You Write By Hand

Things you should know:
assignments-
	> a = 10;
	> math a = a + 10; a+=10; a = a * 10; a*=10
declarations-
	> int a;
fundamental types (intrinsic types) -
	> float
	> int
	> string
	> bool
conditionals-
	> if(){..}, if(){..}->if else(){..}->else{..}
	> switch
	> aggregating boolean expressing
	> if (a!=4 || a<6) {...}
loops-
	> while
	> for
functions-
	> paragraphs of code that will be reused
*/

#include <iostream>
using namespace std;

int main() {
	
/*
Write a program to produce the following using for loop
 0 1 2 3 4 
 1 2 3 4 5
 2 3 4 5 6 	  

for (int j=0; j<3;J++) {
	for(int i=0;i<5;i++){
		cout<< (i+j) << ' ';
	}
	cout << endl;
*/

/*
Write a program to produce the following using for loop
 0 1 2 3 4 
 1 2 Boo 4 5
 2 3 4 5 6 	  

for (int j=0; j<3;J++) {
	for(int i=0;i<5;i++){
		if (i==2 && j++1) cout << "Boo ";
		else cout << (i+j) << ' ';
		}
	cout<< endl;
}
*/

/*
Write a program to produce the following using for loop
 0 1 2 Boo 4 
 1 2 Boo 4 5
 2 Boo 4 5 6 	  

for (int j=0; j<3;J++) {
	for(int i=0;i<5;i++){
		if ((i+j)==3) cout << "Boo ";
		else cout << (i+j) << ' ';
		}
	cout<< endl;
}
*/

}
return 0;
}
