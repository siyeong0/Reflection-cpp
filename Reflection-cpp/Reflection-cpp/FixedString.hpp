#pragma once
#include <string_view>

template<class T, std::size_t Size>
struct FixedString 
{
    constexpr explicit(false) FixedString(const T* str) 
    {
        for (std::size_t i = 0; i < Size; ++i) 
        { 
            data[i] = str[i];
        }
        data[Size] = T();
    }
    [[nodiscard]] constexpr auto operator<=>(const FixedString&) const = default;
    [[nodiscard]] constexpr explicit(false) operator std::string_view() const { return { std::data(data), Size }; }
    [[nodiscard]] constexpr auto size() const { return Size; }
    T data[Size + 1u];
};
template<class T, std::size_t Capacity, std::size_t Size = Capacity - 1> FixedString(const T(&str)[Capacity]) -> FixedString<T, Size>;

static_assert(0u == std::size(FixedString{ "" }));
static_assert(FixedString{ "" } == FixedString{ "" });
static_assert(std::string_view{ "" } == std::string_view{ FixedString{""} });
static_assert(3u == std::size(FixedString{ "foo" }));
static_assert(std::string_view{ "foo" } == std::string_view{ FixedString{"foo"} });
static_assert(FixedString{ "foo" } == FixedString{ "foo" });