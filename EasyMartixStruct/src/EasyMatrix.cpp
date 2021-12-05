#include <iostream>

#include "EasyMatrix.h"

using namespace std;


//Define EasyMatrix Streamer by overloading the operator <<
// eg 
ostream & operator<< (ostream & out, const EasyMatrix & matrix)
{
    out << "Object is a " << matrix.getRows() << "x";
    out << matrix.getColumns() << " matrix with elements:" << endl;

    for (const auto & row : matrix.fData) //
    {
        for (const auto & col_val : row )
            out << col_val << "\t";
        
        out << endl;
    };
    
    return out;
}


//Asking user for values per row
void AskMatrixVals( EasyMatrix &a)
{
    Dim rows = a.getRows();
    Dim columns = a.getColumns();

    for (Dim row = 0; row < rows ; row ++)
    {
        cout << "Enter data for row " << row+1 << " of " << rows << endl;
        for (Dim col = 0; col < columns ; col ++)
        {
            cout << col << ": ";
            cin >> a.fData[row][col];
        }
    }
}

// Multiplying two matixs
// matrix_a * matrix_b
EasyMatrix  operator* (const EasyMatrix &a, const EasyMatrix &b)
{
    assert(a.getColumns() == b.getRows());

    Dim rows = a.getRows();
    Dim columns = b.getColumns();

    //Define a new matrix
    EasyMatrix c(rows, columns);
    
    for( Dim i = 0; i < rows; i ++)
    {
        for (Dim j = 0; j < columns; j++)
        {
            for (Dim k = 0; k < a.getColumns(); k++)
            {
                c.fData[i][j] += (a.fData[i][k] * b.fData[k][j]);
            }
        }
    };

    return c;
    
}


EasyMatrix  operator+ (const EasyMatrix &a, const EasyMatrix &b)
{

    assert(a.getColumns() == b.getColumns());
    assert(a.getRows() == b.getRows());

    //Define a new matrix
    EasyMatrix c = a;

    for( Dim i = 0; i < a.getRows(); i ++)
    {
        for (Dim j = 0; j < b.getColumns(); j++)
        {
            c.fData[i][j] += b.fData[i][j];
        }
    };

    return c;
}