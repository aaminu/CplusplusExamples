#include <iostream>

#include "EasyMatrix.h"

using namespace std;


//Define EasyMatrix Streamer by overloading the operator <<
// eg 
ostream & operator<< (ostream & out, const EasyMatrix & matrix)
{
    out << " is a " << matrix.getRows() << "x";
    out << matrix.getColumns() << " matrix:" << endl;

    for (const auto & row : matrix.fData) //
    {
        for (const auto & col_val : row )
            out << col_val << "\t";
        
        out << endl;
    };
    
    return out;
}
