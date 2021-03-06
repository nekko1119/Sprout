/*=============================================================================
  Copyright (c) 2011-2013 Bolero MURAKAMI
  https://github.com/bolero-MURAKAMI/Sprout

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
=============================================================================*/
#ifndef SPROUT_MATH_ISINF_HPP
#define SPROUT_MATH_ISINF_HPP

#include <type_traits>
#include <sprout/config.hpp>
#include <sprout/limits.hpp>
#include <sprout/math/detail/config.hpp>
#include <sprout/type_traits/enabler_if.hpp>

namespace sprout {
	namespace math {
		namespace detail {
			template<
				typename FloatType,
				typename sprout::enabler_if<std::is_floating_point<FloatType>::value>::type = sprout::enabler
			>
			inline SPROUT_CONSTEXPR bool
			isinf(FloatType x) {
				return x == sprout::numeric_limits<FloatType>::infinity()
					|| x == -sprout::numeric_limits<FloatType>::infinity()
					;
			}
		}	// namespace detail

		using NS_SPROUT_MATH_DETAIL::isinf;
	}	// namespace math

	using sprout::math::isinf;
}	// namespace sprout

#endif	// #ifndef SPROUT_MATH_ISINF_HPP
