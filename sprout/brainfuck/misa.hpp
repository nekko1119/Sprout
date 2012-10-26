#ifndef SPROUT_BRAINFUCK_MISA_HPP
#define SPROUT_BRAINFUCK_MISA_HPP

#include <iterator>
#include <sprout/config.hpp>
#include <sprout/utility/pair.hpp>
#include <sprout/container/traits.hpp>
#include <sprout/container/functions.hpp>
#include <sprout/algorithm/fixed/result_of.hpp>
#include <sprout/weed/parse.hpp>
#include <sprout/weed/parser/lim.hpp>
#include <sprout/weed/parser/lit.hpp>
#include <sprout/weed/parser/char/char.hpp>
#include <sprout/weed/parser/char/char_class.hpp>
#include <sprout/weed/parser/string/string.hpp>
#include <sprout/weed/parser/directive/replace.hpp>
#include <sprout/weed/operator.hpp>
#include <sprout/brainfuck/detail/convert.hpp>

namespace sprout {
	namespace brainfuck {
		namespace misa {
			//
			// to_brainfuck
			//
			template<typename InputIterator, typename Result>
			inline SPROUT_CONSTEXPR sprout::pair<typename sprout::fixed::result_of::algorithm<Result>::type, bool>
			to_brainfuck(InputIterator first, InputIterator last, Result const& result) {
				return sprout::brainfuck::detail::parsed_to_brainfuck(
					sprout::weed::parse(
						first, last,
						*sprout::weed::lim<sprout::container_traits<Result>::static_size>(
							sprout::weed::replace('>')
								[sprout::weed::lit('>') | "��" | "�`" | "�["]
							| sprout::weed::replace('<')
								[sprout::weed::lit('<') | "��" | "��" | "��"]
							| sprout::weed::replace('+')
								[sprout::weed::lit('+') | "��" | "��" | "��" | "��"]
							| sprout::weed::replace('-')
								[sprout::weed::lit('-') | "��" | "�b"]
							| sprout::weed::replace('.')
								[sprout::weed::lit('.') | "�I"]
							| sprout::weed::replace(',')
								[sprout::weed::lit(',') | "�H"]
							| sprout::weed::replace('[')
								[sprout::weed::lit('[') | "�u" | "�w"]
							| sprout::weed::replace(']')
								[sprout::weed::lit(']') | "�v" | "�x"]
							| sprout::weed::replace(' ')
								[sprout::weed::char_]
							)
						),
					result
					);
			}

			//
			// exec_range
			//
			template<std::size_t BufferSize = 32, typename Source, typename Output, typename Input>
			inline SPROUT_CONSTEXPR typename sprout::fixed::result_of::algorithm<Output>::type
			exec_range(Source const& source, Output const& output, Input const& input) {
				typedef typename sprout::container_construct_traits<Source>::copied_type copied_type;
				return sprout::brainfuck::exec_range<BufferSize>(
					sprout::brainfuck::misa::to_brainfuck(sprout::begin(source), sprout::end(source), sprout::pit<copied_type>()).first,
					output, input
					);
			}
			template<std::size_t BufferSize = 32, typename Source, typename Output>
			inline SPROUT_CONSTEXPR typename sprout::fixed::result_of::algorithm<Output>::type
			exec_range(Source const& source, Output const& output) {
				typedef typename sprout::container_construct_traits<Source>::copied_type copied_type;
				return sprout::brainfuck::exec_range<BufferSize>(
					sprout::brainfuck::misa::to_brainfuck(sprout::begin(source), sprout::end(source), sprout::pit<copied_type>()).first,
					output
					);
			}
			template<std::size_t BufferSize = 32, typename Source>
			inline SPROUT_CONSTEXPR typename sprout::fixed::result_of::algorithm<
				sprout::array<typename sprout::container_traits<Source>::value_type, BufferSize>
			>::type
			exec_range(Source const& source) {
				typedef typename sprout::container_construct_traits<Source>::copied_type copied_type;
				return sprout::brainfuck::exec_range<BufferSize>(
					sprout::brainfuck::misa::to_brainfuck(sprout::begin(source), sprout::end(source), sprout::pit<copied_type>()).first
					);
			}
		}	// namespace misa
	}	// namespace brainfuck
}	// namespace sprout

#endif	// #ifndef SPROUT_BRAINFUCK_MISA_HPP