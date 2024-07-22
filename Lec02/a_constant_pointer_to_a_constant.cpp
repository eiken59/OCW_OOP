#include <iostream>
using namespace std;

int main() {
    int x = 4, y = 7;
    const int *const cptc = &x;
    cout << *cptc << endl;
    x = y;
    cout << *cptc << endl;
    return 0;
}

//Remark: Nobody can be changed.
//        The first `const` shows that `*cptc` cannot be changed.
//        The second `const` shows that `cptc` cannot be changed.
//        Once `cptc` is initialized to point to `x`, you cannot modify `x`
//        through `cptc`, nor can you make `cptc` point to another integer.