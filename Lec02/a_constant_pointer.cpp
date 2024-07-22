#include <iostream>
using namespace std;

int main() {
    int x = 4, y = 7;
    int *const cpt = &x;
        //The `const` indicates that the variable1 `cpt` cannot be changed;
        //Imagine it is written in the way of `int *const(cpt)`.
    *cpt = 8;
    cout << "x = " << x << endl;
    return 0;
}

//Remark: The read-only (pointer) varaible `cpt` cannot be changed.
//        However, the reference `*cpt` can be changed.