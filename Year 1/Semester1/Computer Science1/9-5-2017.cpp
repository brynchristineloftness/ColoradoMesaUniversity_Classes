#include <iostream>
using namespace std;

int main () {
    for (int i=0;i<10;i=i++) {
        if (i==1 || i==5) {
            cout << (2+i) <<'  ';
        } else {
            cout << i <<'  ';
        }
    }
    cout << endl;
    return 0;
}
