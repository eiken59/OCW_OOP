#include <iostream>
#include <string.h>
using namespace std;

int main() {
    char wd[100];
    char *wv[50];
    int n = 0;
    while (cin >> wd) {
        int len = strlen(wd) + 1;
        char *nw = new char [len];
        strcpy(nw, wd);
        wv[n++] = nw;
    }
}