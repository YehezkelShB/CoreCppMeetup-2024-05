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
	auto format(const MyString& str, auto& ctx) const
	{
		return std::format_to(ctx.out(), "{}", str.m_str);
	}
};
