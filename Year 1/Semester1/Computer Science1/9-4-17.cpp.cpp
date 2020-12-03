#include<iostream>
#include <iomanip>
using namespace std;

int main(void)
{
     cout << "A multiplication table:" << endl
          << "  0\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\t11\t12" << endl
          << "  " <<endl;
        
     for(int c = 0; c < 13; c++)
     {
          cout << c;
          for(int i = 0; i < 13; i++)
          {
          cout << i * c << '\t';
          }
          cout << endl;
     }
     return 0;
}

