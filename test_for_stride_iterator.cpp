#include <iostream>
#include <array>
#include "stride_iterator.hpp"

using namespace std;
using namespace Utilpack;

template<size_t size>
class test_array
{
  public:
    int inter_array[size];

    test_array()
    {
	for(size_t i = 0; i < size; ++i)
	    inter_array[i] = i;
    }

    int* begin() const
    { return *inter_array;}

    int* end() const
    { return begin() + size;}
};


int main(){
    constexpr size_t ar_size(28);
    test_array<ar_size> tes_ar;
    cout << "test for stride_iterator<int, 2, test_array<ar_size> >." << endl;
    for(stride_iterator<int, 2, test_array<ar_size> > itr(tes_ar.begin());
	itr != stride_iterator<int, 2, test_array<ar_size> > itr(tes_ar.end()); ++itr)
	cout << *itr << " ";
    cout << endl;
	
    return 0;
}
