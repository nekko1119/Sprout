#ifndef SPROUT_DETAIL_ITERATOR_HPP
#define SPROUT_DETAIL_ITERATOR_HPP

#include <iterator>
#include <sprout/config.hpp>

namespace sprout {
	namespace detail {
		//
		// distance
		//
		template<typename Iterator>
		SPROUT_CONSTEXPR typename std::iterator_traits<Iterator>::difference_type distance(
			Iterator first,
			Iterator last
			)
		{
			return first == last ? 0 : 1 + sprout::detail::distance(first + 1, last);
		}

		template<typename Iterator>
		SPROUT_CONSTEXPR typename std::iterator_traits<Iterator>::difference_type bidirectional_distance_impl(
			Iterator first1,
			Iterator first2,
			Iterator last,
			typename std::iterator_traits<Iterator>::difference_type current = 1
			)
		{
			return first1 == last
				? current
				: first2 == last
				? -current
				: sprout::detail::bidirectional_distance_impl(first1 + 1, first2 - 1, last, current + 1)
				;
		}
		//
		// bidirectional_distance
		//
		template<typename Iterator>
		SPROUT_CONSTEXPR typename std::iterator_traits<Iterator>::difference_type bidirectional_distance(
			Iterator first,
			Iterator last
			)
		{
			return first == last ? 0 : sprout::detail::bidirectional_distance_impl(first + 1, first - 1, last);
		}
	}	// namespace detail
}	// namespace sprout

#endif	// #ifndef SPROUT_DETAIL_ITERATOR_HPP
