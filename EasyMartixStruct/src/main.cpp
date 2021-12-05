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


    //Matrix Addition
    EasyMatrix matrix_d(3, 3);
    AskMatrixVals( matrix_d );
    cout << "Matrix D " << matrix_d << endl;
    EasyMatrix matrix_f(3, 3);
    AskMatrixVals( matrix_f );
    cout << "Matrix F " << matrix_f << endl;

    EasyMatrix matrix_add = matrix_d + matrix_f; 
    cout << " Matrix " << matrix_add << endl;

    return 0;
}