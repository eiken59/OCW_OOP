#include <iostream>
using namespace std;

int main() {
    int x = 9;
    const int &xref = x;
    x = 33;
    cout << xref << endl;
    x = 50;
    cout << xref << endl;
    return 0;
}

//Remark: The read-only reference `xref` cannot be directly assigned.
//        However, its original variable can be changed.