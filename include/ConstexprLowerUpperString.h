#pragma once

#include <string>
#include <array>

template<std::size_t SIZE>
class ConstexprLowerUpperString {
	friend struct ConstexprLowerUpperStringHelper;

public:
	template<std::size_t SIZE_OTHER>
	constexpr bool operator==(const ConstexprLowerUpperString<SIZE_OTHER>& str) const noexcept {
		return *this == static_cast<std::string_view>(str);
	}

	template<std::size_t SIZE_OTHER>
	constexpr bool operator!=(const ConstexprLowerUpperString<SIZE_OTHER>& str) const noexcept {
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
	constexpr ConstexprLowerUpperString(const char(&str)[SIZE], std::index_sequence<INDEX...>, bool lower) noexcept
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

struct ConstexprLowerUpperStringHelper {
	template<std::size_t SIZE>
	static constexpr ConstexprLowerUpperString<SIZE> CreateLower(const char(&str)[SIZE]) noexcept {
		return ConstexprLowerUpperString(str, std::make_index_sequence<SIZE - 1>(), true);
	}

	template<std::size_t SIZE>
	static constexpr ConstexprLowerUpperString<SIZE> CreateUpper(const char(&str)[SIZE]) noexcept {
		return ConstexprLowerUpperString(str, std::make_index_sequence<SIZE - 1>(), false);
	}
};
