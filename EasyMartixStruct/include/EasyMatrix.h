#ifndef EASYMATRIX_H_
#define EASYMATRIX_H_

#include <vector>
#include <ctime>
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

// Overloaded operators
ostream & operator<< (ostream & out, const EasyMatrix & matrix);

EasyMatrix  operator+ (const EasyMatrix &a, const EasyMatrix &b);

EasyMatrix  operator* (const EasyMatrix &a, const EasyMatrix &b);

//others
void AskMatrixVals( EasyMatrix &a);


// Marsaglia's Xorshift random variable (provided in the Textbook)
struct MarsXorShift
{
    //Start value must be different from 0
    unsigned long value { (unsigned long) time (nullptr) & 0xFF };

    // Function to get random number
    unsigned long getNext( void )
    {
        value ^= value << 13;
        value ^= value << 17;
        value ^= value << 5;

        return value;
    }


};

// random initalizaton for Easy Matrix
void RandInit(EasyMatrix &m);


#endif /*EASYMATRIX_H_*/

