#include <iostream>
using namespace std;

void fun1(void (*fp)(void *), void *q) {
    fp(q);
}

void fun2(void *r) {
    int a = * (int *) r;
    cout << a << endl;
}

int main() {
    int var = 22;
    void *p = &var;
    fun1(fun2, p);
    return 0;
}

