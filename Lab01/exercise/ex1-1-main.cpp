#include <fstream>
#include "ex1-1.h"
#include <iomanip>
#include <cstdlib>
using namespace Complex;

void ReadTextFile(char[], Cplex &, Cplex &);
void PrintComplex(char[], Cplex[]);

int main(int argc, char *argv[]) {
    Cplex a, b; // use struct named Cplex under namespace Complex
    ReadTextFile(argv[1], a, b); // process text file
    Cplex results[4]; // store the results of diff. operation
    results[0] = ComplexOperation(a, b, '+');
    results[1] = ComplexOperation(a, b, '-');
    results[2] = ComplexOperation(a, b, '*');
    results[3] = ComplexOperation(a, b, '/');
    PrintComplex(argv[2], results); // print the results on file.
    return 0;
}

void ReadTextFile(char fileName[], Cplex &c1, Cplex &c2) {
    std::ifstream fin;
    fin.open(fileName);

    double tempA, tempB;
    char sign, imagUnit;
    fin >> tempA >> sign >> tempB >> imagUnit;
    c1.real = tempA;
    if (sign == '+')
        c1.image = tempB;
    else
        c1.image = -tempB;
    fin >> tempA >> sign >> tempB >> imagUnit;
    c2.real = tempA;
    if (sign == '+')
        c2.image = tempB;
    else
        c2.image = -tempB;

    fin.close();
}

void PrintComplex(char fileName[], Cplex complexResults[]) {
    std::ofstream fout;
    fout.open(fileName);
    fout.precision(4);
    for(int i = 0; i < 4; i++) {
        if (complexResults[i].image < 0)
            fout << std::fixed << complexResults[i].real << complexResults[i].image << "i" << std::endl;
        else
            fout << std::fixed << complexResults[i].real << "+" << complexResults[i].image << "i" << std::endl;
    }
    fout.close();
}