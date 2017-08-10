#ifndef UTIL_STRIDE_ITERATOR
#define UTIL_STRIDE_ITERATOR

#include <iterator>

namespace Utilpack
{

template<typename value_T, std::size_t stride, typename container_T>
class stride_iterator
{
    friend container_T;
    
  public:
    using value_type		= value_T;
    using difference_type	= std::ptrdiff_t;
    using pointer               = value_type*;
    using reference		= value_type&;
    using iterator_category	= std::random_access_iterator_tag;
    using self_type             = stride_iterator<value_type, stride, container_T>;
    
    //operators
    stride_iterator& operator++();
    stride_iterator operator++(int);
    stride_iterator& operator--();
    stride_iterator operator--(int);
    stride_iterator& operator+=(const difference_type);
    stride_iterator& operator-=(const difference_type);

    reference operator*() const;
    pointer operator->() const;
    
    friend bool operator==(const self_type&, const self_type&) const;
    friend bool operator!=(const self_type&, const self_type&) const;
    friend bool operator<(const self_type&, const self_type&) const;
    friend bool operator>(const self_type&, const self_type&) const;
    friend bool operator<=(const self_type&, const self_type&) const;
    friend bool operator>=(const self_type&, const self_type&) const;
    
    friend stride_iterator operator+(const difference_type, const self_type&) const;
    friend stride_iterator operator+(const self_type&, const difference_type) const;
    friend stride_iterator operator-(const self_type&, const difference_type) const;
    friend difference_type operator-(const self_type&, const self_type&) const;
    
  private:
    pointer elem_p;
    
    stride_iterator()
    { elem_p = nullptr; }

    stride_iterator(pointer value_p)
    { elem_p = value_p; }    
    
};

template<typename value_T, std::size_t stride, typename container_T>
stride_iterator& operator++()
{
    return elem_p += stride;
}

template<typename value_T, std::size_t stride, typename container_T>
stride_iterator operator++(int)
{
    stride_iterator result(elem_p);
    ++elem_p;
    return result;
}

template<typename value_T, std::size_t stride, typename container_T>
stride_iterator& operator--()
{
    return elem_p -= stride;
}

template<typename value_T, std::size_t stride, typename container_T>
stride_iterator operator--(int)
{
    stride_iterator result(elem_p);
    --elem_p;
    return result;
}


template<typename value_T, std::size_t stride, typename container_T>
stride_iterator& operator+=(difference_type arg)
{
    return elem_p += stride * arg;
}

template<typename value_T, std::size_t stride, typename container_T>
stride_iterator& operator-=(difference_type arg)
{
    return elem_p -= stride * arg;
}

template<typename value_T, std::size_t stride, typename container_T>
reference operator*() const
{
    return *elem_p;
}

template<typename value_T, std::size_t stride, typename container_T>
pointer operator->() const
{
    return elem_p;
}

//friend operator for stride_iterator

template<typename value_T, std::size_t stride, typename container_T>
bool operator==(const stride_iterator<value_type, stride, container_T>& one,
		       const stride_iterator<value_type, stride, container_T>& two) const
{
    return one.elem_p == two.elem_p;
}

template<typename value_T, std::size_t stride, typename container_T>
bool operator!=(const stride_iterator<value_type, stride, container_T>& one,
		       const stride_iterator<value_type, stride, container_T>& two) const
{
    return !(one == two);
}

template<typename value_T, std::size_t stride, typename container_T>
bool operator<(const stride_iterator<value_type, stride, container_T>& one,
		const stride_iterator<value_type, stride, container_T>& two) const
{
    return one.elem_p < two.elem_p;
}

template<typename value_T, std::size_t stride, typename container_T>
bool operator>(const stride_iterator<value_type, stride, container_T>& one,
		const stride_iterator<value_type, stride, container_T>& two) const
{
    return one.elem_p > two.elem_p;
}

template<typename value_T, std::size_t stride, typename container_T>
bool operator<=(const stride_iterator<value_type, stride, container_T>& one,
		const stride_iterator<value_type, stride, container_T>& two) const
{
    return !(one > two);
}

;emplate<typename value_T, std::size_t stride, typename container_T>
bool operator>=(const stride_iterator<value_type, stride, container_T>& one,
		const stride_iterator<value_type, stride, container_T>& two) const
{
    return !(one < two);
}


template<typename value_T, std::size_t stride, typename container_T>
stride_iterator operator+(
    const difference_type p_diff,
    const stride_iterator<value_T, stride, container_T>& arg_itr) const
{
    return stride_iterator(arg_itr.elem_p + p_diff * stride);
}

template<typename value_T, std::size_t stride, typename container_T>
stride_iterator operator+(
    const stride_iterator<value_T, stride, container_T)>& arg_itr,
    const difference_type p_diff) const
{
    return p_diff + arg_itr;
}

template<typename value_T, std::size_t stride, typename container_T>
stride_iterator operator-(
    const stride_iterator<value_T, stride, container_T>& arg_itr,
    const difference_type p_diff) const
{
    return stride_iterator(arg_itr.elem_p - p_diff * stride);
}

template<typename value_T, std::size_t stride, typename container_T>
difference_type operator-(
    const stride_iterator<value_T, stride, container_T>& one,
    const stride_iterator<value_T, stride, container_T>& two)
{
    difference_type result one.elem_p - two.elem_p;
    if(result % stride != 0)
	throw std::invalid_argument("stride iterators of arguments are not correspond.");
    return result / stride;
}
    
} /* Utilpack */

#endif
