#ifndef UTIL_TEST_TOW_DIMENSION_MATRIX
#define UTIL_TEST_TOW_DIMENSION_MATRIX

#include <iostream>
#include "2d-matrix.hpp"

using namespace std;
using namespace Utilpack;

int main()
{
    cout  << "generate array_matrix<int, 0, 0>" << endl;    
    array_matrix<int, 0, 0> empty_matrix;
    cout << "judge empty = " << boolalpha << empty_matrix.empty() << endl;
    const size_t culum_Num{3}, row_Num{4};
    cout  << "generate array_matrix<int, "
	  << culum_Num << ", " << row_Num << ">" << endl;
    array_matrix<int, culum_Num, row_Num> test_matrix;
    cout << "judge empty = " << boolalpha << test_matrix.empty() << endl;
    cout << "fill with 1." << endl;
    test_matrix.fill(1);
    cout << "elem num = " << test_matrix.size() << endl;
    cout << "row num = " << test_matrix.xsize() << endl;
    cout << "culum num = " << test_matrix.ysize() << endl;

    cout << "access and output." << endl;
    for(size_t i = 0; i < culum_Num; ++i){
	for(size_t j = 0; j < row_Num; ++j)
	    cout << test_matrix.at(i,j) << " ";
	cout << endl;
    }

    cout << "access with for each." << endl;
    for(auto elem : test_matrix)
	cout << elem << " ";
    cout << endl;

    cout << "fill with rowculum num" << endl;
    for(size_t i = 0; i < culum_Num; ++i){
	for(size_t j = 0; j < row_Num; ++j)
	    test_matrix.at(i,j) = i * 10 + j;
    }

    cout << "test rowbegin() and rowend()." << endl;
    for(array_matrix<int, row_Num, culum_Num>::iterator itr =
	    test_matrix.rowbegin(row_Num / 2);
	itr != (test_matrix.rowend(row_Num / 2)); ++itr)
	cout << *itr << " ";
    cout << endl;
    return 0;
}

#endif /*UTIL-TEST-TOW-DIMENSION-MATRIX*/
