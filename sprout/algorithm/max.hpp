/*=============================================================================
  Copyright (c) 2011-2013 Bolero MURAKAMI
  Copyright (C) 2011 RiSK (sscrisk)
  https://github.com/bolero-MURAKAMI/Sprout

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
=============================================================================*/
#ifndef SPROUT_ALGORITHM_MAX_HPP
#define SPROUT_ALGORITHM_MAX_HPP

#include <initializer_list>
#include <sprout/config.hpp>
#include <sprout/algorithm/max_element.hpp>
#include <sprout/iterator/ptr_index_iterator.hpp>
#include HDR_FUNCTIONAL_SSCRISK_CEL_OR_SPROUT

namespace sprout {

	// 25.4.7 Minimum and maximum
	template<typename T, typename Compare>
	inline SPROUT_CONSTEXPR T const&
	max(T const& a, T const& b, Compare comp) {
		return comp(a, b) ? b : a;
	}

	template<typename T>
	inline SPROUT_CONSTEXPR T const&
	max(T const& a, T const& b) {
		return sprout::max(a, b, NS_SSCRISK_CEL_OR_SPROUT::less<T>());
	}

#ifdef SPROUT_NO_CXX14_INITIALIZER_LIST
	template<typename T, typename Compare>
	inline SPROUT_CONSTEXPR T
	max(std::initializer_list<T> t, Compare comp) {
		return *sprout::max_element(sprout::ptr_index(t.begin(), 0), sprout::ptr_index(t.begin(), t.size()), comp);
	}

	template<typename T>
	inline SPROUT_CONSTEXPR T
	max(std::initializer_list<T> t) {
		return sprout::max(t, NS_SSCRISK_CEL_OR_SPROUT::less<T>());
	}
#else	// #ifdef SPROUT_NO_CXX14_INITIALIZER_LIST
	template<typename T, typename Compare>
	inline T
	max(std::initializer_list<T> t, Compare comp) {
		return *sprout::max_element(sprout::ptr_index(t.begin(), 0), sprout::ptr_index(t.begin(), t.size()), comp);
	}

	template<typename T>
	inline T
	max(std::initializer_list<T> t) {
		return sprout::max(t, NS_SSCRISK_CEL_OR_SPROUT::less<T>());
	}
#endif	// #ifdef SPROUT_NO_CXX14_INITIALIZER_LIST
}	// namespace sprout

#endif	// #ifndef SPROUT_ALGORITHM_MAX_HPP
