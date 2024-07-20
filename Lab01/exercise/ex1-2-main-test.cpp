#include <fstream>
#include <iostream>
using namespace std;

const int MAX = 1000;

typedef struct {
    char coeff[10];
    int power;
}Items;

typedef struct {
    Items items[MAX];
    int num_items;
}Poly;

void ReadTextFile(Poly &);
void DifferenetiationPoly(Poly &);
void PrintResult(Poly);

int main() {
    Poly eq;
    ReadTextFile(eq); // process text file
    //DifferentationPoly(eq); // differentiation of polynomials
    PrintResult(eq); // print the results on file.
    return 0;
}

void ReadTextFile(Poly &expression) {
    std::ifstream fin;
    fin.open("input_file.txt");
    char tempCoeff[10];
    int tempPower;
    char temp;
    char tempSign;
    int numberOfItems = 0;
    int posOfCoeff = 0;

    while (fin.get(temp)) {
        if (isdigit(temp)) {
            tempCoeff[posOfCoeff] = temp;
            posOfCoeff++;
        }
        else if (temp == '+' || temp == '-') {
            if (numberOfItems == 0 && posOfCoeff == 0) {
                tempCoeff[posOfCoeff] = temp;
                posOfCoeff++;
            }
            else {
                tempCoeff[posOfCoeff] = '\0';
                for (int i = 0; i < posOfCoeff; i++) {
                    expression.items[numberOfItems].coeff[i] = tempCoeff[i];
                }
                expression.items[numberOfItems].power = tempPower;
                numberOfItems++;
                tempCoeff[0] = '\0';
                tempPower = 0;
                tempCoeff[0] = temp;
                posOfCoeff = 1;
            }
        }
        else if (temp == 'X') tempPower = 1;
        else if (temp == '^') fin >> tempPower;
    }
    
    tempCoeff[posOfCoeff] = '\0';
    for (int i = 0; i < posOfCoeff; i++) {
        expression.items[numberOfItems].coeff[i] = tempCoeff[i];
    }
    expression.items[numberOfItems].power = tempPower;
    numberOfItems++;
    
    expression.num_items = numberOfItems;
    fin.close();
}

void DifferentiationPoly(Poly &expression) {
    // 好難
}

void PrintResult(Poly expression) {
    int n = expression.num_items;
    int arrayOfPowers[MAX];
    for (int i = 0; i < n; i++) {
        arrayOfPowers[i] = expression.items[i].power;
    }
    int max = arrayOfPowers[0];
    for (int i = 1; i < n; i++) {
        if (arrayOfPowers[i] > max) max = arrayOfPowers[i];
    }
    for (int i = max; i > 0 || i == 0; i--) {
        for (int ii = 0; ii < n; ii++) {
            if (expression.items[ii].power == i) {
                if (expression.items[ii].coeff[0] == '+' || expression.items[ii].coeff[0] == '-') {
                    for (int iii = 0; iii < sizeof expression.items[ii] - 1; iii++) {
                        cout << expression.items[ii].coeff[iii];
                    }
                }
                else {
                    cout << '+';
                    for (int iii = 0; iii < sizeof expression.items[ii] - 1; iii++) {
                        cout << expression.items[ii].coeff[iii];
                    }
                }
                if (i == 0) ;
                else if (i == 1) cout << 'X';
                else cout << "X^" << expression.items[ii].power;
            }
        }
    }
}