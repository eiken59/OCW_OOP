#include <fstream>

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
void DifferenetiationPoly(Poly &);
void PrintResult(char[], Poly);

int main(int argc, char *argv[]) {
    Poly eq;
    ReadTextFile(argv[1], eq); // process text file
    //DifferentationPoly(eq); // differentiation of polynomials
    PrintResult(argv[2], eq); // print the results on file.
    return 0;
}

void ReadTextFile(char fileName[], Poly &expression) {
    std::ifstream fin;
    fin.open(fileName);
    char tempCoeff[10];
    int tempPower;
    char temp;
    char tempSign;
    int numberOfItems = 0;
    int posOfCoef = 0;

    while(true) {
        if (!fin.eof()) {
            fin.get(temp);
            if (isdigit(temp)) {
                tempCoeff[posOfCoef] = temp;
                posOfCoef++;
            }
            else if (temp == '+' || temp == '-') {
                if (numberOfItems == 0 && posOfCoef == 0) {
                    tempCoeff[posOfCoef] = temp;
                    posOfCoef++;
                }
                else {
                    tempCoeff[posOfCoef] = '\0';
                    for (int i = 0; i < posOfCoef + 1; i++) {
                        expression.items[numberOfItems].coeff[i] = tempCoeff[i];
                    }
                    expression.items[numberOfItems].power = tempPower;
                    numberOfItems++;
                    tempCoeff[0] = '\0';
                    tempPower = 0;
                    tempCoeff[0] = temp;
                }
            }
            else if (temp == 'X') {
                posOfCoef = 0;
            }
            else if (temp = '^') {
                fin >> tempPower;
            }
        }
        else {
            tempCoeff[posOfCoef] = '\0';
            for (int i = 0; i < posOfCoef + 1; i++) {
                expression.items[numberOfItems].coeff[i] = tempCoeff[i];
            }
            expression.items[numberOfItems].power = tempPower;
            numberOfItems++;
        }
    }
    
    expression.num_items = numberOfItems;
    fin.close();
}

void DifferentiationPoly(Poly &expression) {
    // 好難
}

void PrintResult(char fileName[], Poly expression) {
    std::ofstream fout;
    fout.open(fileName);

    int n = expression.num_items;
    int arrayOfPowers[MAX];
    for (int i = 0; i < n; i++) {
        arrayOfPowers[i] = expression.items[i].power;
    }
    int max = arrayOfPowers[0];
    for (int i = 1; i < n; i++) {
        if (arrayOfPowers[i] > max) max = arrayOfPowers[i];
    }
    for (int i = max; i > 0; i--) {
        for (int ii = 0; ii < n; ii++) {
            if (expression.items[ii].power == i) {
                if (expression.items[ii].coeff[0] == '+' || expression.items[ii].coeff[0] == '-') {
                    for (int iii = 0; i < sizeof(expression.items[ii]); iii++) {
                        fout << expression.items[ii].coeff[iii];
                    }
                }
                else {
                    fout << '+';
                    for (int iii = 0; i < sizeof(expression.items[ii]); iii++) {
                        fout << expression.items[ii].coeff[iii];
                    }
                }
                if (i == 0) ;
                else if (i == 1) fout << 'X';
                else fout << "X^" << expression.items[ii].power;
            }
        }
    }
    fout.close();
}