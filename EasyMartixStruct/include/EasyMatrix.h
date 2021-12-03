#ifndef EASYMATRIX_H_
#define EASYMATRIX_H_

#include <vector>
using namespace std;

//Define a Realmatrix of type vector of vecto<double>
using RealVec = vector< double >; 
using Dim = RealVec::size_type;
using DataType = RealVec::value_type;

using RealMatrix = vector< RealVec >;


//Define EasyMatrix as a wrapper for Real Matrix
struct EasyMatrix
{
    RealMatrix fData;

    //constructor
    EasyMatrix( Dim rows, Dim columns, DataType init_value=0.0 )
    : fData( rows, RealVec( columns, init_value ) )
    {
        assert( columns > 0 );
        assert( rows > 0 );

    }

    //helper functions
    auto getRows(void) const { return fData.size(); }
    auto getColumns(void) const { return fData[0].size(); }

    auto begin() const { return fData.begin(); }
    auto end()  const { return fData.end(); }

};

#endif /*EASYMATRIX_H_*/

