#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
float x=3.14159;
cout << setw(10) << setprecision(3) << fixed << x << endl;
return 0;
}

//look at setfill and setprecision
