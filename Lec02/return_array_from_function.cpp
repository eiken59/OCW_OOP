#include <iostream>
using namespace std;

int *display();

int main() {
    cout << *display() << endl;
}

int *display() {
    int *pt = new int[2];
    pt[0] = 0;
    pt[1] = 0;
    int b[2] = {10, 20};
    for (int i = 0; i < 2; i++){
        *pt = b[i];
    }
    return pt;
}