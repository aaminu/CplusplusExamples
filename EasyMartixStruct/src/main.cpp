#include <iostream>

#include "EasyMatrix.h"

using namespace std;


int main()
{
    // Easy declaration and prinitng out 
    EasyMatrix matrix_a(3, 4);
    cout << "Matrix A" << matrix_a;
    AskMatrixVals( matrix_a );
    cout << matrix_a;

    return 0;
}