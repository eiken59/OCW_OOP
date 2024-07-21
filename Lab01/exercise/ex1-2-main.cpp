#include <fstream>
#include <iostream>
#include <string.h>
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

void ReadTextFile(char[], Poly &);
void DifferentiationPoly(Poly &);
void PrintResult(char[], Poly);

int main(int argc, char *argv[]) {
    Poly eq;
    ReadTextFile(argv[1], eq); // process text file
    DifferentiationPoly(eq); // differentiation of polynomials
    PrintResult(argv[2], eq); // print the results on file.
    return 0;
}

void ReadTextFile(char fileName[], Poly &expression) {
    std::ifstream fin;
    fin.open(fileName);
    char tempCoeff[10];
    tempCoeff[0] = '\0';
    int tempPower = -1;
    char temp;
    int numberOfItems = 0;
    int posOfCoeff = 0;

    while (fin.get(temp)) {
        if (isdigit(temp)) {
            tempCoeff[posOfCoeff] = temp;
            posOfCoeff++;
        }
        else if (temp == '+' || temp == '-') {
            if (numberOfItems == 0 && posOfCoeff == 0 && tempPower == -1) {
                tempCoeff[posOfCoeff] = temp;
                posOfCoeff++;
            }
            else {
                if (strlen(tempCoeff) == 0) {
                    tempCoeff[0] = '1';
                    posOfCoeff = 1;
                }
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
    if (strlen(tempCoeff) == 0) {
        tempCoeff[0] = '1';
        posOfCoeff = 1;
    }
    for (int i = 0; i < posOfCoeff; i++) {
        expression.items[numberOfItems].coeff[i] = tempCoeff[i];
    }
    expression.items[numberOfItems].power = tempPower;
    numberOfItems++;
    
    expression.num_items = numberOfItems;
    fin.close();
}

void DifferentiationPoly(Poly &expression) {
    for (int i = 0; i < expression.num_items; i++) {
        if (expression.items[i].power == 0) {
            expression.items[i].coeff[0] = '\0';
        }
        else {
            int coeff = 0;
            if (expression.items[i].coeff[0] == '+' || expression.items[i].coeff[0] == '-') {
                if (strlen(expression.items[i].coeff) == 1) {
                    if (expression.items[i].coeff[0] == '+') coeff = expression.items[i].power;
                    else coeff = -1 * expression.items[i].power;
                }
                else {
                    coeff = atoi(expression.items[i].coeff) * expression.items[i].power;
                }
            }
            else {
                coeff = atoi(expression.items[i].coeff) * expression.items[i].power;
            }
            string temp_str = to_string(coeff);
            char const* tempCoeff = temp_str.c_str();
            for (int j = 0; j < strlen(tempCoeff); j++) {
                expression.items[i].coeff[j] = tempCoeff[j];
            }
            expression.items[i].coeff[strlen(tempCoeff)] = '\0';
        }
        expression.items[i].power--;
    }
}

void PrintResult(char fileName[], Poly expression) {
    std::ofstream fout;
    fout.open(fileName);

    int n = expression.num_items;
    int numberOfTerms = 0;
    int arrayOfPowers[MAX];
    for (int i = 0; i < n; i++) {
        arrayOfPowers[i] = expression.items[i].power;
    }
    int max = arrayOfPowers[0];
    for (int i = 1; i < n; i++) {
        if (arrayOfPowers[i] > max) max = arrayOfPowers[i];
    }
    for (int i = max; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            if (expression.items[j].power == i) {
                if (((expression.items[j].coeff[0] == '+' || expression.items[j].coeff[0] == '-') && expression.items[j].coeff[1] == '0') || expression.items[j].coeff[0] == '0' || expression.items[j].coeff[0] == '\0') {
                    continue;
                }
                else if (numberOfTerms) {
                    if (expression.items[j].coeff[0] == '+' || expression.items[j].coeff[0] == '-') {
                        for (int k = 0; k < strlen(expression.items[j].coeff); k++) {
                            fout << expression.items[j].coeff[k];
                        }
                    }
                    else {
                        fout << '+';
                        for (int k = 0; k < strlen(expression.items[j].coeff); k++) {
                            fout << expression.items[j].coeff[k];
                        }
                    }
                    if (i == 0) ;
                    else if (i == 1) fout << 'X';
                    else fout << "X^" << expression.items[j].power;
                    numberOfTerms++;
                }
                else {
                    if (expression.items[j].coeff[0] == '+') {
                        for (int k = 1; k < strlen(expression.items[j].coeff); k++) {
                            fout << expression.items[j].coeff[k];
                        }
                    }
                    else {
                        for (int k = 0; k < strlen(expression.items[j].coeff); k++) {
                            fout << expression.items[j].coeff[k];
                        }
                    }
                    if (i == 0) ;
                    else if (i == 1) fout << 'X';
                    else fout << "X^" << expression.items[j].power;
                    numberOfTerms++;
                }
            }
        }
    }
    fout.close();
}