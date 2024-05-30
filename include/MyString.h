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
struct std::formatter<MyString> // inheritance isn't relevant
{
	template <typename ParseContext>
	constexpr auto parse(ParseContext& ctx)
	{
		return ctx.begin();
	}

	auto format(const MyString& str, auto& ctx) const
	{
		return std::format_to(ctx.out(), "{}", str.m_str);
	}
};
