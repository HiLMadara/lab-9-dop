#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include "libforlab.h"

using namespace std;

int main() {

    int maxDegree, sequence;                                                            //int n, n/2

    int i;
    double coef;
    cout << "Enter the maximum degree of the polynomial." << endl;
    cin >> maxDegree;
    check();
    if (maxDegree < 0) {
        cout << "Error!Negative degree of the derivative!";
        return 1;
    }
    if (maxDegree > 1000) {
        cout << "Error! Too big degree man relax dont break my lab! ";
        return -1;
    }
    double* arrCoef = new(nothrow) double[maxDegree];
    double* arrCoefCopy = new(nothrow) double[maxDegree+1];
    if ((!arrCoef)||(!arrCoefCopy)) {
        cout << "Memory error!";
        return -1;
    }
    for (i = 0; i < maxDegree + 1; i++) {
        arrCoefCopy[i] = 0;
    }
    for (i = 0; i < maxDegree; i++) {
        cout << "Enter the coefficient at x" << endl;
        cin >> coef;
        check();
        arrCoef[i] = coef;
    }   
    
        for (int j = 0; j < maxDegree; j++) {
            deriv(arrCoef, arrCoef + maxDegree,arrCoefCopy,arrCoefCopy+maxDegree+1, j);
        }

    

    for (i = 0; i < maxDegree+1; i++) {
        cout << "Coefficient at the degree of " << i << " = " << arrCoefCopy[i] << endl;
    }


    delete[] arrCoef;
    return 0;
}