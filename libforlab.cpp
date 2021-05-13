#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cmath>

using namespace std;
void check() {
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "Error!Invalid input attempt!\n";
    }
}

void deriv(double* first, double* last, double* second, double* secLast, const int j) {
    if ((j > secLast - second) || (j == 0)) {
        return;
    }
    second[j + 1] = first[j] / (j+1);
    
}