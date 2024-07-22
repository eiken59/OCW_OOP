#include <iostream>
using namespace std;

int main() {
    int x = 4, y = 7;
    const int *pt = &x;
        //The `const` indicates that the dereferenced variable cannot be changed.
        //This is why it is called "a pointer to a constant."
        //Imagine it is written in the way of `const(int *pt)`.
    cout << *pt << endl;
    pt = &y;
    cout << *pt << endl;
}

//Remark: The read-only location `*pt` cannot be changed.
//        However, the pointer itself `pt` can be changed.