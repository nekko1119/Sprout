/*=============================================================================
  Copyright (c) 2011-2013 Bolero MURAKAMI
  https://github.com/bolero-MURAKAMI/Sprout

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
=============================================================================*/
#ifndef SPROUT_ITERATOR_REVERSE_ITERATOR_HPP
#define SPROUT_ITERATOR_REVERSE_ITERATOR_HPP

#include <iterator>
#include <utility>
#include <sprout/config.hpp>
#include <sprout/iterator/next.hpp>
#include <sprout/iterator/prev.hpp>
#include <sprout/iterator/distance.hpp>
#include <sprout/utility/swap.hpp>

namespace sprout {
	//
	// reverse_iterator
	//
	template<typename Iterator>
	class reverse_iterator
		: public std::iterator<
			typename std::iterator_traits<Iterator>::iterator_category,
			typename std::iterator_traits<Iterator>::value_type,
			typename std::iterator_traits<Iterator>::difference_type,
			typename std::iterator_traits<Iterator>::pointer,
			typename std::iterator_traits<Iterator>::reference
		>
	{
	public:
		typedef Iterator iterator_type;
		typedef typename std::iterator_traits<iterator_type>::iterator_category iterator_category;
		typedef typename std::iterator_traits<iterator_type>::value_type value_type;
		typedef typename std::iterator_traits<iterator_type>::difference_type difference_type;
		typedef typename std::iterator_traits<iterator_type>::pointer pointer;
		typedef typename std::iterator_traits<iterator_type>::reference reference;
	protected:
		iterator_type current;
	public:
		reverse_iterator() = default;
		SPROUT_CONSTEXPR reverse_iterator(reverse_iterator const& other)
			: current(other.current)
		{}
		explicit SPROUT_CONSTEXPR reverse_iterator(iterator_type it)
			: current(it)
		{}
		template<typename U>
		SPROUT_CONSTEXPR reverse_iterator(reverse_iterator<U> const& it)
			: current(it.base())
		{}
		template<typename U>
		reverse_iterator& operator=(reverse_iterator<U> const& it) {
			reverse_iterator temp(it);
			temp.swap(*this);
			return *this;
		}
		SPROUT_CONSTEXPR iterator_type base() const {
			return current;
		}
		SPROUT_CONSTEXPR reference operator*() const {
			return *sprout::prev(current);
		}
		SPROUT_CONSTEXPR pointer operator->() const {
			return &*(*this);
		}
		reverse_iterator& operator++() {
			--current;
			return *this;
		}
		reverse_iterator operator++(int) {
			reverse_iterator result(*this);
			--current;
			return result;
		}
		reverse_iterator& operator--() {
			++current;
			return *this;
		}
		reverse_iterator operator--(int) {
			reverse_iterator temp(*this);
			++current;
			return temp;
		}
		SPROUT_CONSTEXPR reverse_iterator operator+(difference_type n) const {
			return reverse_iterator(current - n);
		}
		SPROUT_CONSTEXPR reverse_iterator operator-(difference_type n) const {
			return reverse_iterator(current + n);
		}
		reverse_iterator& operator+=(difference_type n) {
			reverse_iterator temp(current - n);
			temp.swap(*this);
			return *this;
		}
		reverse_iterator& operator-=(difference_type n) {
			reverse_iterator temp(current + n);
			temp.swap(*this);
			return *this;
		}
		SPROUT_CONSTEXPR reference operator[](difference_type n) const {
			return *(current - (n + 1));
		}
		SPROUT_CONSTEXPR reverse_iterator next() const {
			return reverse_iterator(sprout::prev(current));
		}
		SPROUT_CONSTEXPR reverse_iterator prev() const {
			return reverse_iterator(sprout::next(current));
		}
		void swap(reverse_iterator& other)
		SPROUT_NOEXCEPT_EXPR(
			SPROUT_NOEXCEPT_EXPR(swap(current, other.current))
			)
		{
			swap(current, other.current);
		}
	};

	template<typename Iterator1, typename Iterator2>
	inline SPROUT_CONSTEXPR bool
	operator==(sprout::reverse_iterator<Iterator1> const& lhs, sprout::reverse_iterator<Iterator2> const& rhs) {
		return lhs.base() == rhs.base();
	}
	template<typename Iterator1, typename Iterator2>
	inline SPROUT_CONSTEXPR bool
	operator!=(sprout::reverse_iterator<Iterator1> const& lhs, sprout::reverse_iterator<Iterator2> const& rhs) {
		return !(lhs == rhs);
	}
	template<typename Iterator1, typename Iterator2>
	inline SPROUT_CONSTEXPR bool
	operator<(sprout::reverse_iterator<Iterator1> const& lhs, sprout::reverse_iterator<Iterator2> const& rhs) {
		return lhs.base() < rhs.base();
	}
	template<typename Iterator1, typename Iterator2>
	inline SPROUT_CONSTEXPR bool
	operator>(sprout::reverse_iterator<Iterator1> const& lhs, sprout::reverse_iterator<Iterator2> const& rhs) {
		return rhs < lhs;
	}
	template<typename Iterator1, typename Iterator2>
	inline SPROUT_CONSTEXPR bool
	operator<=(sprout::reverse_iterator<Iterator1> const& lhs, sprout::reverse_iterator<Iterator2> const& rhs) {
		return !(rhs < lhs);
	}
	template<typename Iterator1, typename Iterator2>
	inline SPROUT_CONSTEXPR bool
	operator>=(sprout::reverse_iterator<Iterator1> const& lhs, sprout::reverse_iterator<Iterator2> const& rhs) {
		return !(lhs < rhs);
	}
	template<typename Iterator1, typename Iterator2>
	inline SPROUT_CONSTEXPR decltype(std::declval<Iterator1>() - std::declval<Iterator2>())
	operator-(sprout::reverse_iterator<Iterator1> const& lhs, sprout::reverse_iterator<Iterator2> const& rhs) {
		return rhs.base() - lhs.base();
	}
	template<typename Iterator>
	inline SPROUT_CONSTEXPR sprout::reverse_iterator<Iterator>
	operator+(
		typename sprout::reverse_iterator<Iterator>::difference_type n,
		sprout::reverse_iterator<Iterator> const& it
		)
	{
		return it + n;
	}

	//
	// make_reverse_iterator
	//
	template<typename Iterator>
	inline SPROUT_CONSTEXPR sprout::reverse_iterator<Iterator>
	make_reverse_iterator(Iterator it) {
		return sprout::reverse_iterator<Iterator>(it);
	}

	//
	// swap
	//
	template<typename Iterator>
	inline void
	swap(sprout::reverse_iterator<Iterator>& lhs, sprout::reverse_iterator<Iterator>& rhs)
	SPROUT_NOEXCEPT_EXPR(SPROUT_NOEXCEPT_EXPR(lhs.swap(rhs)))
	{
		lhs.swap(rhs);
	}

	//
	// iterator_next
	//
	template<typename Iterator>
	inline SPROUT_CONSTEXPR sprout::reverse_iterator<Iterator>
	iterator_next(sprout::reverse_iterator<Iterator> const& it) {
		return it.next();
	}

	//
	// iterator_prev
	//
	template<typename Iterator>
	inline SPROUT_CONSTEXPR sprout::reverse_iterator<Iterator>
	iterator_prev(sprout::reverse_iterator<Iterator> const& it) {
		return it.prev();
	}
}	// namespace sprout

#endif	// #ifndef SPROUT_ITERATOR_REVERSE_ITERATOR_HPP
