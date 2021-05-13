#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include "libforlab.h"



int main() {

    int maxDegree, sequence;                                                            //int n, n/2

    int i;
    double coef;
   std::cout << "Enter the maximum degree of the polynomial." << std::endl;
    std::cin >> maxDegree;
    check();
    if (maxDegree < 0) {
       std:: cout << "Error!Negative degree of the derivative!";
        return 1;
    }
    if (maxDegree > 1000) {
       std:: cout << "Error! Too big degree man relax dont break my lab! ";
        return -1;
    }
    double* arrCoef = new(std::nothrow) double[maxDegree];
    double* arrCoefCopy = new(std::nothrow) double[maxDegree+1];
    if ((!arrCoef)||(!arrCoefCopy)) {
       std:: cout << "Memory error!";
        return -1;
    }
    for (i = 0; i < maxDegree + 1; i++) {
        arrCoefCopy[i] = 0;
    }
    for (i = 0; i < maxDegree; i++) {
        std::cout << "Enter the coefficient at x" << std::endl;
        std::cin >> coef;
        check();
        arrCoef[i] = coef;
    }   
    
        for (int j = 0; j < maxDegree; j++) {
            deriv(arrCoef, arrCoef + maxDegree,arrCoefCopy,arrCoefCopy+maxDegree+1, j);
        }

    

    for (i = 0; i < maxDegree+1; i++) {
        std::cout << "Coefficient at the degree of " << i << " = " << arrCoefCopy[i] << std::endl;
    }

    delete[] arrCoefCopy;
    delete[] arrCoef;
    return 0;
}