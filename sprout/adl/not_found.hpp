/*=============================================================================
  Copyright (c) 2011-2013 Bolero MURAKAMI
  https://github.com/bolero-MURAKAMI/Sprout

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
=============================================================================*/
#ifndef SPROUT_ADL_NOT_FOUND_HPP
#define SPROUT_ADL_NOT_FOUND_HPP

#include <type_traits>
#include <sprout/config.hpp>

namespace sprout {
	//
	// not_found_via_adl
	//
	struct not_found_via_adl {};

	//
	// is_not_found_via_adl
	//
	template<typename T>
	struct is_not_found_via_adl
		: public std::is_same<T, sprout::not_found_via_adl>
	{};
	template<typename T>
	struct is_not_found_via_adl<T const>
		: public sprout::is_not_found_via_adl<T>
	{};
	template<typename T>
	struct is_not_found_via_adl<T volatile>
		: public sprout::is_not_found_via_adl<T>
	{};
	template<typename T>
	struct is_not_found_via_adl<T const volatile>
		: public sprout::is_not_found_via_adl<T>
	{};

	//
	// is_found_via_adl
	//
	template<typename T>
	struct is_found_via_adl
		: public std::integral_constant<bool, !sprout::is_not_found_via_adl<T>::value>
	{};
}	// namespace sprout

#endif	// #ifndef SPROUT_ADL_NOT_FOUND_HPP
