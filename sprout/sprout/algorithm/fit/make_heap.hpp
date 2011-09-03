#ifndef SPROUT_ALGORITHM_FIT_MAKE_HEAP_HPP
#define SPROUT_ALGORITHM_FIT_MAKE_HEAP_HPP

#include <sprout/config.hpp>
#include <sprout/fixed_container/traits.hpp>
#include <sprout/fixed_container/functions.hpp>
#include <sprout/algorithm/fixed/make_heap.hpp>
#include <sprout/algorithm/fit/result_of.hpp>
#include <sprout/sub_array.hpp>

namespace sprout {
	namespace fit {
		namespace detail {
			template<typename Container, typename Compare>
			SPROUT_CONSTEXPR inline typename sprout::fit::result_of::algorithm<Container>::type make_heap_impl(
				Container const& cont,
				Compare comp,
				typename sprout::fixed_container_traits<Container>::difference_type offset
				)
			{
				return sprout::sub_copy(
					sprout::get_fixed(sprout::fixed::make_heap(cont, comp)),
					offset,
					offset + sprout::size(cont)
					);
			}
		}	// namespace detail
		//
		// make_heap
		//
		template<typename Container, typename Compare>
		SPROUT_CONSTEXPR inline typename sprout::fit::result_of::algorithm<Container>::type make_heap(
			Container const& cont,
			Compare comp
			)
		{
			return sprout::fit::detail::make_heap_impl(cont, comp, sprout::fixed_begin_offset(cont));
		}

		namespace detail {
			template<typename Container>
			SPROUT_CONSTEXPR inline typename sprout::fit::result_of::algorithm<Container>::type make_heap_impl(
				Container const& cont,
				typename sprout::fixed_container_traits<Container>::difference_type offset
				)
			{
				return sprout::sub_copy(
					sprout::get_fixed(sprout::fixed::make_heap(cont)),
					offset,
					offset + sprout::size(cont)
					);
			}
		}	// namespace detail
		//
		// make_heap
		//
		template<typename Container>
		SPROUT_CONSTEXPR inline typename sprout::fit::result_of::algorithm<Container>::type make_heap(
			Container const& cont
			)
		{
			return sprout::fit::detail::make_heap_impl(cont, sprout::fixed_begin_offset(cont));
		}
	}	// namespace fit
}	// namespace sprout

#endif	// #ifndef SPROUT_ALGORITHM_FIT_MAKE_HEAP_HPP
