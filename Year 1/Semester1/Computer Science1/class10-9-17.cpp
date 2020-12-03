#include <iostream>

using namespace std;

int main() {

int NumberofTasks;
int MaxMinutes;

cout << "Please enter number of tasks for the day (Must be < or = 50)" << endl;
cin >> NumberofTasks;
cout << "Please enter max minutes for the day (Must be < or = 500)" << endl;
cin >> MaxMinutes;

cout << "Enter Minutes for Tasks" << endl;
for (int i; i <= NumberofTasks ; i++) {
int Task;
int RunningTaskSum = 0;
cin >> Task;
if (RunningTaskSum < MaxMinutes) {
	RunningTaskSum= Task + RunningTaskSum;
	}
}
return 0;
}

