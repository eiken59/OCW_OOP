#include <fstream>
#include <iostream>

using namespace std;

typedef struct {
    int *data;
    int length;
    bool sign;
} BIGNUMBER;

void ReadTextFile(char[], BIGNUMBER&, BIGNUMBER&);
void operator-(BIGNUMBER&);
BIGNUMBER BigNumberOperation(BIGNUMBER, BIGNUMBER, char);
void PrintResults(char[], BIGNUMBER[]);

int main(int argc, char *argv[]) {
    BIGNUMBER a, b;
    ReadTextFile(argv[1], a, b);

    BIGNUMBER results[2];

    results[0] = BigNumberOperation(a, b, '+');
    results[1] = BigNumberOperation(a, b, '-');

    PrintResults(argv[2], results);

    return 0;
}

void ReadTextFile(char fileName[], BIGNUMBER &big1, BIGNUMBER &big2) {
    ifstream fin;
    fin.open(fileName);
    char tempChar;
    n = 0;
    while (fin.get(tempChar)) {
        if (tempChar != '\n') {
            if (n > 0) {
                for (int i = 0; i < n; i++) {
                    big1[i+1] = big1[i];
                }
            }
            big1[0] = int(tempChar);
            n++;
        }
        else {
            big1.length = n;
            n = 0;
            break;
        }
    }
    while (fin.get(tempChar)) {
        if (tempChar != '\n') {
            if (n > 0) {
                for (int i = 0; i < n; i++) {
                    big2[i+1] = big2[i];
                }
            }
            big2[0] = int(tempChar);
            n++;
        }
        else {
            big1.length = n;
            n = 0;
            break;
        }
    }
    if (big1.data[big1.length - 1] == '-') {
        big1.sign = false;
        for (int i = 1; i < n; i++) {
            big1.data[i - 1] = big1.data[i];
        }
        big1.data[n] = '\0';
        big1.length--;
    }
    else if (big1.data[big1.length - 1] == '+') {
        big1.sign = true;
        for (int i = 1; i < n; i++) {
            big1.data[i - 1] = big1.data[i];
        }
        big1.data[n] = '\0';
        big1.length--;
    }
    else {
        big1.sign = true;
    }
    if (big2.data[big2.length - 1] == '-') {
        big2.sign = false;
        for (int i = 1; i < n; i++) {
            big2.data[i - 1] = big2.data[i];
        }
        big2.data[n] = '\0';
        big2.length--;
    }
    else if (big2.data[big2.length - 1] == '+') {
        big2.sign = true;
        for (int i = 1; i < n; i++) {
            big2.data[i - 1] = big2.data[i];
        }
        big2.data[n] = '\0';
        big2.length--;
    }
    else {
        big2.sign = true;
    }
}

void operator-(BIGNUMBER &big) {
    big.sign = !big.sign;
}

BIGNUMBER BigNumberOperation(BIGNUMBER big1, BIGNUMBER big2, char oper) {
    switch (oper) {
        case '+':
            BIGNUMBER tempBig;
            //`big1` and `big2` are with the same sign.
            if (!(big1 ^ big2)) {
                tempBig.sign = big1.sign;
                
            }
            break;
        case '-':
            return BigNumberOperation(big1, -big2, '+');
            break;
        default:
            break;
    }
}