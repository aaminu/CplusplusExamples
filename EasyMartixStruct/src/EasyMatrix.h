#ifndef EASYMATRIX_H_
#define EASYMATRIX_H_

#include <vector>
using namespace std;

//Define a Realmatrix of type vector of vecto<double>
using RealVec = vector< double >; 
using Dim = RealVec::size_type;
using DataType = RealVec::value_type;

using RealMatrix = vector< RealVec >;

//Structure declaration
struct EasyMatrix;

#endif /*EASYMATRIX_H_*/

