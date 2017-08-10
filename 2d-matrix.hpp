// This program is made in expectation of C ++ 14.
// When running on C ++ 11, you will get a warning about the constexpr function.

#ifndef UTIL_TOW_DIMENSION_MATRIX
#define UTIL_TOW_DIMENSION_MATRIX

#include <array>
#include <stdexcept>

namespace Utilpack
{

template<typename value_T, std::size_t row_Num, std::size_t column_Num>
class array_matrix
{
  public:
    using array_type			= std::array<value_T, row_Num * column_Num>;
    using value_type			= value_T;
    using reference			= value_type&;
    using const_reference		= const value_type&;
    using iterator			= typename array_type::iterator;
    using const_iterator		= typename array_type::const_iterator;
    using size_type			= std::size_t;
    using reverse_iterator		= typename array_type::reverse_iterator;
    using const_reverse_iterator	= typename array_type::const_reverse_iterator;
    using row_iterator			= iterator;
    using const_row_iterator		= const_iterator;
    using stride_iterator		= typename stride_iterator<value_type, row_Num>;
    using column_iterator		= stride_iterator;
    using const_column_iterator		= const stride_iterator;
    
    constexpr static size_type elem_Num = row_Num * column_Num;
    
    array_matrix() {};
    array_matrix(value_T value)
    {
	fill_n(value);
    };
    
    void fill(const value_type& i)
    {std::fill_n(begin(), size(), i); }

    //iterator
    iterator begin() noexcept
    { return content.begin(); }

    const_iterator begin() const noexcept
    { return content.begin(); }

    iterator end() noexcept
    { return content.end(); }

    const_iterator end() const noexcept
    { return content.end(); }
    
    reverse_iterator rbegin() noexcept
    { return reverse_iterator(end()); }

    const_reverse_iterator rbegin() const noexcept
    { return const_reverse_iterator(end()); }

    reverse_iterator rend() noexcept
    { return reverse_iterator(begin()); }

    const_reverse_iterator rend() const noexcept
    { return const_reverse_iterator(begin()); }

    const_iterator cbegin() const noexcept
    { return content.cbegin(); }

    const_iterator cend() const noexcept
    { return content.cend(); }

    const_reverse_iterator crbegin() const noexcept
    { return content.cend(); }

    const_reverse_iterator crend() const noexcept
    { return content.cbegin(); }

//for 2-D iterator
    iterator rowbegin(size_type row) noexcept
    { return content.begin() + row * column_Num; }
    
    const_iterator rowbegin(size_type row) const noexcept
    { return content.begin() + row * column_Num; }

    iterator rowend(size_type row) noexcept
    { return rowbegin(row) + column_Num; }

    const_iterator rowend(size_type row) const noexcept
    { return rowbegin(row) + column_Num; }

    const_iterator crowbegin(size_type row) const noexcept
    { return content.cbegin() + row * column_Num; }
    
    const_iterator crowend(size_type row) const noexcept
    { return crowend(row) + column_Num; }

    stride_iterator
    
// Capacity
    constexpr size_type size() const noexcept
    { return elem_Num; }

    constexpr size_type max_size() const noexcept
    { return elem_Num; }

    constexpr size_type xsize() const noexcept
    { return row_Num; }

    constexpr size_type ysize() const noexcept
    { return column_Num; }
    
    constexpr bool empty() const noexcept
    { return content.empty(); }

    //Element access.
    reference at(size_type n, size_type m) noexcept
    {
	if (n >= row_Num)
	    std::out_of_range("array_matrix row index is bigger than row size.");
	else if (m >= column_Num)
	    std::out_of_range("array_matrix column index is bigger than column size.");
	return content.at(n * column_Num + m);
    }

    constexpr const_reference at(size_type n, size_type m) const noexcept
    {
	if (n >= row_Num)
	    std::out_of_range("array_matrix row index is bigger than row size.");
	else if (m >= column_Num)
	    std::out_of_range("array_matrix column index is bigger than column size.");
	return content.at(n * column_Num + m);
    }
    
  private:
    array_type content;
    
};

//Array_matrix comparisons.
template<typename value_T, std::size_t column_Num, std::size_t row_Num>
inline bool operator==(const array_matrix<value_T, column_Num, row_Num>& one,
		       const array_matrix<value_T, column_Num, row_Num>& two)
{ return std::equal(one.begin(), one.end(), two.begin()); }

template<typename value_T, std::size_t column_Num, std::size_t row_Num>
inline bool operator!=(const array_matrix<value_T, column_Num, row_Num>& one,
		       const array_matrix<value_T, column_Num, row_Num>& two)
{ return !(one == two); }

} /* Utilpack */

#endif /*UTIL_TOW_DIMENSION_MATRIX*/

