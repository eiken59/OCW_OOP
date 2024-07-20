#include "ex1-1.h"

namespace Complex{
    Cplex ComplexOperation(Cplex c1, Cplex c2, char sign){
        Cplex rComplexNumber;
        switch (sign){
            case '+':
                rComplexNumber.real = c1.real + c2.real;
                rComplexNumber.image = c1.image + c2.image;
                break;
            case '-':
                rComplexNumber.real = c1.real - c2.real;
                rComplexNumber.image = c1.image - c2.image;
                break;
            case '*':
                rComplexNumber.real = c1.real * c2.real - c1.image * c2.image;
                rComplexNumber.image = c1.real * c2.image + c1.image * c2.real;
                break;
            case '/':
                Cplex c2conj;
                c2conj.real = c2.real;
                c2conj.image = -c2.image;
                Cplex tComplexNumber = ComplexOperation(c1, c2conj, '*');
                rComplexNumber.real = tComplexNumber.real / (c2.real * c2.real + c2.image * c2.image);
                rComplexNumber.image = tComplexNumber.image / (c2.real * c2.real + c2.image * c2.image);
                break;
        }
        return rComplexNumber;
    }
}