#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

typedef struct {
    int *data;
    int length;
    bool sign;
} BIGNUMBER;

void ReadTextFile(BIGNUMBER&, BIGNUMBER&);
BIGNUMBER BigNumberOperation(BIGNUMBER, BIGNUMBER, char);
void PrintResults(BIGNUMBER[]);

int main() {
    BIGNUMBER a, b;
    ReadTextFile(a, b);

    BIGNUMBER results[2];

    results[0] = BigNumberOperation(a, b, '+');
    results[1] = BigNumberOperation(a, b, '-');

    PrintResults(results);

    return 0;
}

void ReadTextFile(BIGNUMBER &big1, BIGNUMBER &big2) {
    ifstream fin;
    fin.open("bignumber.txt");
    string tempString;

    getline(fin, tempString);
    if (isdigit(tempString[0])) {
        big1.sign = true;
        big1.data = new int[tempString.length()];
        for (int i = 0; i < tempString.length(); i++) {
            big1.data[tempString.length() - 1 - i] = int(tempString[i]) - 48;
        }
        big1.data[tempString.length()] = '\0';
        big1.length = tempString.length();
    }
    else {
        if (tempString[0] == '+') big1.sign = true;
        else if (tempString[0] == '-') big1.sign = false;
        big1.data = new int[tempString.length() - 1];
        for (int i = 0; i < tempString.length() - 1; i++) {
            big1.data[tempString.length() - 2 - i] = int(tempString[i]) - 48;
        }
        big1.data[tempString.length() - 1] = '\0';
        big1.length = tempString.length() - 1;
    }

    getline(fin, tempString);
    if (isdigit(tempString[0])) {
        big2.sign = true;
        big2.data = new int[tempString.length()];
        for (int i = 0; i < tempString.length(); i++) {
            big2.data[tempString.length() - 1 - i] = int(tempString[i]) - 48;
        }
        big2.data[tempString.length()] = '\0';
        big2.length = tempString.length();
    }
    else {
        if (tempString[0] == '+') big2.sign = true;
        else if (tempString[0] == '-') big2.sign = false;
        big2.data = new int[tempString.length() - 1];
        for (int i = 0; i < tempString.length() - 1; i++) {
            big2.data[tempString.length() - 2 - i] = int(tempString[i]) - 48;
        }
        big2.data[tempString.length() - 1] = '\0';
        big2.length = tempString.length() - 1;
    }

    fin.close();
}

BIGNUMBER BigNumberOperation(BIGNUMBER big1, BIGNUMBER big2, char oper) {
    BIGNUMBER tempBig;
    switch (oper) {
        case '+':
            if (!(big1.sign ^ big2.sign)) {
                tempBig.sign = big1.sign;
                int max_len = max(big1.length, big2.length);
                tempBig.length = max_len;
                tempBig.data = new int[max_len + 1]();
                for (int i = 0; i < big1.length; i++) {
                    tempBig.data[i] = big1.data[i];
                }
                for (int i = 0; i < big2.length; i++) {
                    tempBig.data[i] += big2.data[i];
                }
                tempBig.data[max_len] = '\0';
                for (int i = 0; i < max_len - 1; i++) {
                    if (tempBig.data[i] >= 10) {
                        int carry = tempBig.data[i] / 10;
                        tempBig.data[i] %= 10;
                        tempBig.data[i + 1] += carry;
                    }
                }
                return tempBig;
            }
            else {
                if (big1.sign == true) {
                    big2.sign = !big2.sign;
                    return BigNumberOperation(big1, big2, '-');
                }
                else {
                    big1.sign = !big1.sign;
                    return BigNumberOperation(big2, big1, '-');
                }
            }
            break;
        case '-':
            if (!(big1.sign ^ big2.sign)) {
                if (big1.length > big2.length) {
                    tempBig.sign = big1.sign;
                    int max_len = max(big1.length, big2.length);
                    tempBig.length = max_len;
                    tempBig.data = new int[max_len + 1]();
                    for (int i = 0; i < big1.length; i++) {
                        tempBig.data[i] = big1.data[i];
                    }
                    for (int i = 0; i < big2.length; i++) {
                        tempBig.data[i] -= big2.data[i];
                    }
                    tempBig.data[max_len] = '\0';
                    for (int i = 0; i < max_len - 1; i++) {
                        if (tempBig.data[i] < 0) {
                            tempBig.data[i] += 10;
                            tempBig.data[i + 1] -= 1;
                        }
                    }
                }
                else if (big1.length == big2.length) {
                    //
                }
                else {
                    tempBig = BigNumberOperation(big2, big1, '-');
                    tempBig.sign = !(tempBig.sign);
                    return tempBig;
                }
            }
            else {
                if (big1.sign == true) {
                    big2.sign = !big2.sign;
                    return BigNumberOperation(big1, big2, '+');
                }
                else {
                    big1.sign = !big1.sign;
                    return BigNumberOperation(big2, big1, '+');
                }
            }
            break;
        default:
            break;
    }
}

void PrintResults(BIGNUMBER bigs[]) {
    for (int j = 0; j < 2; j++) {
        if (bigs[j].sign == false) cout << '-';
        for (int k = 0; k < bigs[j].length; k++) {
            if (k != 0) {
                cout << bigs[j].data[bigs[j].length - 1 - k] << "\'";
            }
            else {
                if (bigs[j].data[bigs[j].length - 1 - k] != 0) cout << bigs[j].data[bigs[j].length - 1 - k] << "\'";
                else cout << "\'";
            }
        }
        cout << endl;
    }
}