#include <iostream>

#include "EasyMatrix.h"

using namespace std;


int main()
{
    // Easy declaration and prinitng out 
    EasyMatrix matrix_a(2, 3);
    AskMatrixVals( matrix_a );
    cout << "Matrix A " << matrix_a << endl;

    EasyMatrix matrix_b(3, 5);
    AskMatrixVals( matrix_b );
    cout << "Matrix B " << matrix_b << endl;


    // Matix multiplication
    EasyMatrix matrix_c = matrix_a * matrix_b; 
    cout << " Matrix C " << matrix_c << endl;

    return 0;
}