#include <iostream>

#include "EasyMatrix.h"

using namespace std;

ostream & operator<< (ostream & out, const EasyMatrix & matrix);

int main()
{
    EasyMatrix matrix_a(3, 4);
    cout << "Matrix A" <<matrix_a;

    return 0;
}