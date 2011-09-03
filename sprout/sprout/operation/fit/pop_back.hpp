#ifndef SPROUT_OPERATION_FIT_POP_BACK_HPP
#define SPROUT_OPERATION_FIT_POP_BACK_HPP

#include <cstddef>
#include <sprout/config.hpp>
#include <sprout/fixed_container/traits.hpp>
#include <sprout/fixed_container/functions.hpp>
#include <sprout/operation/fixed/pop_back.hpp>
#include <sprout/sub_array.hpp>

namespace sprout {
	namespace fit {
		namespace result_of {
			//
			// pop_back
			//
			template<typename Container>
			struct pop_back {
			public:
				typedef sprout::sub_array<
					typename sprout::fixed_container_traits<
						typename sprout::fixed::result_of::pop_back<Container>::type
					>::internal_type
				> type;
			};
		}	// namespace result_of

		//
		// pop_back
		//
		template<typename Container>
		SPROUT_CONSTEXPR inline typename sprout::fit::result_of::pop_back<Container>::type pop_back(
			Container const& cont
			)
		{
			return sprout::sub_copy(
				sprout::get_fixed(sprout::fixed::pop_back(cont)),
				sprout::fixed_begin_offset(cont),
				sprout::fixed_end_offset(cont) - 1
				);
		}
	}	// namespace fit
}	// namespace sprout

#endif	// #ifndef SPROUT_OPERATION_FIT_POP_BACK_HPP
