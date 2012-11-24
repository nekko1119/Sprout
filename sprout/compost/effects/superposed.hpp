#ifndef SPROUT_COMPOST_EFFECTS_SUPERPOSED_HPP
#define SPROUT_COMPOST_EFFECTS_SUPERPOSED_HPP

#include <sprout/config.hpp>
#include <sprout/functional/plus.hpp>
#include <sprout/utility/forward.hpp>
#include <sprout/utility/value_holder.hpp>
#include <sprout/range/adaptor/transformed.hpp>

namespace sprout {
	namespace compost {
		namespace effects {
			//
			// superpose_holder
			//
			template<typename RRange>
			class superpose_holder {
			public:
				typedef RRange range2_type;
			private:
				sprout::value_holder<range2_type&> range_;
			public:
				superpose_holder() = default;
				superpose_holder(superpose_holder const&) = default;
				explicit SPROUT_CONSTEXPR superpose_holder(range2_type& range)
					: range_(range)
				{}
				SPROUT_CONSTEXPR range2_type& range() const {
					return range_;
				}
			};

			//
			// superposed_forwarder
			//
			class superposed_forwarder {
			public:
				template<typename RRange>
				SPROUT_CONSTEXPR sprout::compost::effects::superpose_holder<
					typename std::remove_reference<typename sprout::lvalue_reference<RRange>::type>::type
				>
				operator()(RRange&& range) {
					return sprout::compost::effects::superpose_holder<
						typename std::remove_reference<typename sprout::lvalue_reference<RRange>::type>::type
					>(
						sprout::lvalue_forward<RRange>(range)
						);
				}
			};

			//
			// superposed
			//
			namespace {
				SPROUT_STATIC_CONSTEXPR sprout::compost::effects::superposed_forwarder superposed{};
			}	// anonymous-namespace

			//
			// operator|
			//
			template<typename Range, typename T>
			inline SPROUT_CONSTEXPR auto
			operator|(Range&& lhs, sprout::compost::effects::superpose_holder<T> const& rhs)
			-> decltype(
				sprout::forward<Range>(lhs)
					| sprout::adaptors::transformed(rhs.range(), sprout::plus<>())
				)
			{
				return sprout::forward<Range>(lhs)
					| sprout::adaptors::transformed(rhs.range(), sprout::plus<>())
					;
			}
		}	// namespace effects

		using sprout::compost::effects::superposed;
	}	// namespace compost
}	// namespace sprout

#endif	// #ifndef SPROUT_COMPOST_EFFECTS_SUPERPOSED_HPP
