/*=============================================================================
  Copyright (c) 2011-2013 Bolero MURAKAMI
  https://github.com/bolero-MURAKAMI/Sprout

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
=============================================================================*/
#ifndef SPROUT_CONFIG_STDLIB_HPP
#define SPROUT_CONFIG_STDLIB_HPP

#ifdef __cplusplus
#	include <cstddef>
#else
#	include <stddef.h>
#endif

#if defined(__SGI_STL_PORT) || defined(_STLPORT_VERSION)
#	include <sprout/config/stdlib/stlport.hpp>
#else

#	include <utility>

#	if defined(__LIBCOMO__)
#		include <sprout/config/stdlib/libcomo.hpp>
#	elif defined(__STD_RWCOMPILER_H__) || defined(_RWSTD_VER)
#		include <sprout/config/stdlib/roguewave.hpp>
#	elif defined(_LIBCPP_VERSION)
#		include <sprout/config/stdlib/libcpp.hpp>
#	elif defined(__GLIBCPP__) || defined(__GLIBCXX__)
#		include <sprout/config/stdlib/libstdcpp3.hpp>
#	elif defined(__STL_CONFIG_H)
#		include <sprout/config/stdlib/sgi.hpp>
#	elif defined(__MSL_CPP__)
#		include <sprout/config/stdlib/msl.hpp>
#	elif defined(__IBMCPP__)
#		include <sprout/config/stdlib/vacpp.hpp>
#	elif defined(MSIPL_COMPILE_H)
#		include <sprout/config/stdlib/modena.hpp>
#	elif (defined(_YVALS) && !defined(__IBMCPP__)) || defined(_CPPLIB_VER)
#		include <sprout/config/stdlib/dinkumware.hpp>
#	endif
#endif

#endif	// #ifndef SPROUT_CONFIG_STDLIB_HPP
