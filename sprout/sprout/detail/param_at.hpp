#ifndef SPROUT_DETAIL_PARAM_AT_HPP
#define SPROUT_DETAIL_PARAM_AT_HPP

#include <cstddef>
#include <type_traits>
#include <sprout/config.hpp>

namespace sprout {
		namespace detail {
			template<typename R, typename T, typename... Values>
			SPROUT_CONSTEXPR inline typename std::enable_if<
				sizeof...(Values) == 0,
				R
			>::type param_at(
				std::size_t n,
				T const& v,
				Values const&... values
				)
			{
				return v;
			}
			template<typename R, typename T, typename... Values>
			SPROUT_CONSTEXPR inline typename std::enable_if<
				sizeof...(Values) != 0,
				R
			>::type param_at(
				std::size_t n,
				T const& v,
				Values const&... values
				)
			{
				return n == 0 ? v : sprout::detail::param_at<R>(n - 1, values...);
			}
		}	// namespace detail
}	// namespace sprout

#endif	// #ifndef SPROUT_DETAIL_PARAM_AT_HPP
