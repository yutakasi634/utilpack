#ifndef UTIL_TOW_DIMENSION_MATRIX
#define UTIL_TOW_DIMENSION_MATRIX

#include <array>
#include <stdexcept>

namespace Utilpack
{

template<typename value_T, std::size_t row_Num, std::size_t culum_Num>
class array_matrix
{
    using array_type			= std::array<value_T, row_Num * culum_Num>;

    using value_type			= value_T;
    using reference			= value_type&;
    using const_reference		= const value_type&;
    using iterator			= typename array_type::iterator;
    using const_iterator		= typename array_type::const_iterator;
    using size_type			= std::size_t;
    using reverse_iterator		= typename array_type::reverse_iterator;
    using const_reverse_iterator	= typename array_type::const_reverse_iterator;

  private:
    const size_type elem_Num;
    array_type content;    

  public:
    array_matrix():elem_Num(row_Num * culum_Num){};
    array_matrix(value_T value):elem_Num(row_Num * culum_Num)
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
    { return content.begin(); }

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

    // Capacity
    constexpr size_type size() const noexcept
    { return elem_Num; }

    constexpr size_type max_size() const noexcept
    { return elem_Num; }

    constexpr size_type xsize() const noexcept
    { return row_Num; }

    constexpr size_type ysize() const noexcept
    { return culum_Num; }
    
    constexpr bool empty() const noexcept
    { return content.empty(); }

    //Element access.
    reference at(size_type n, size_type m) noexcept
    {
	if (n >= row_Num)
	    std::out_of_range("array_matrix row index is bigger than row size.");
	else if (m >= culum_Num)
	    std::out_of_range("array_matrix culum index is bigger than culum size.");
	return content.at(n * culum_Num + m);
    }

    constexpr const_reference at(size_type n, size_type m) const noexcept
    {
	if (n >= row_Num)
	    std::out_of_range("array_matrix row index is bigger than row size.");
	else if (m >= culum_Num)
	    std::out_of_range("array_matrix culum index is bigger than culum size.");
	return content.at(n * culum_Num + m);
    }
    
};

//Array_matrix comparisons.
template<typename value_T, std::size_t culum_Num, std::size_t row_Num>
inline bool operator==(const array_matrix<value_T, culum_Num, row_Num>& one,
		       const array_matrix<value_T, culum_Num, row_Num>& two)
{ return std::equal(one.begin(), one.end(), two.begin()); }

template<typename value_T, std::size_t culum_Num, std::size_t row_Num>
inline bool operator!=(const array_matrix<value_T, culum_Num, row_Num>& one,
		       const array_matrix<value_T, culum_Num, row_Num>& two)
{ return !(one == two); }

} /* Utilpack */

#endif /*UTIL_TOW_DIMENSION_MATRIX*/

