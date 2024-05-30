#pragma once

#include <string>
#include <format>

class MyString
{
public:
	MyString(const std::string& str);

private:
	std::string m_str;
	friend std::formatter<MyString>;
};

template <>
struct std::formatter<MyString> : std::formatter<std::string_view>
{
	using Base = std::formatter<std::string_view>;

	template <typename FormatContext>
	auto format(const MyString& str, FormatContext& ctx) const
	{
		return Base::format(str.m_str, ctx);
	}
};
