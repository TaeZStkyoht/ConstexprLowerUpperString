#pragma once

#include <string>
#include <array>

namespace ConstexprLowerUpperString {
	template<std::size_t SIZE>
	class CLUString {
		friend struct CLUStringHelper;

	public:
		template<std::size_t SIZE_OTHER>
		constexpr bool operator==(const CLUString<SIZE_OTHER>& str) const noexcept {
			return *this == static_cast<std::string_view>(str);
		}

		template<std::size_t SIZE_OTHER>
		constexpr bool operator!=(const CLUString<SIZE_OTHER>& str) const noexcept {
			return !(*this == str);
		}

		constexpr bool operator==(std::string_view str) const noexcept {
			return static_cast<std::string_view>(*this) == str;
		}

		constexpr bool operator!=(std::string_view str) const noexcept {
			return !(*this == str);
		}

		constexpr operator std::string_view() const noexcept {
			return { data.data(), data.size() };
		}

		operator std::string() const {
			return { data.data(), data.size() };
		}

	private:
		template<std::size_t ...INDEX>
		constexpr CLUString(const char(&str)[SIZE], std::index_sequence<INDEX...>, bool lower) noexcept
			: data{ (lower ? ToLower(str[INDEX]) : ToUpper(str[INDEX]))... } {
		}

		static constexpr char ToLower(char c) noexcept {
			return (c >= 'A' && c <= 'Z') ? static_cast<char>(c + ('a' - 'A')) : c;
		}

		static constexpr char ToUpper(char c) noexcept {
			return (c >= 'a' && c <= 'z') ? static_cast<char>(c - ('a' - 'A')) : c;
		}

		std::array<char, SIZE - 1> data;
	};

	struct CLUStringHelper {
		template<std::size_t SIZE>
		static constexpr CLUString<SIZE> CreateLower(const char(&str)[SIZE]) noexcept {
			return CLUString(str, std::make_index_sequence<SIZE - 1>(), true);
		}

		template<std::size_t SIZE>
		static constexpr CLUString<SIZE> CreateUpper(const char(&str)[SIZE]) noexcept {
			return CLUString(str, std::make_index_sequence<SIZE - 1>(), false);
		}
	};
}
