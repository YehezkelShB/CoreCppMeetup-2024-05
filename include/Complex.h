#pragma once

#include <format>
#include <cmath>
#include <numbers>

class Complex
{
public:
	Complex(double real, double imag)
		: m_real(real), m_imag(imag)
	{
	}

	double real() const
	{
		return m_real;
	}

	double imag() const
	{
		return m_imag;
	}

	double radius() const
	{
		return std::hypot(m_real, m_imag);
	}

	double angle() const
	{
		return std::atan2(m_imag, m_real) * (180.0 / std::numbers::pi_v<double>);
	}

private:
	double m_real;
	double m_imag;
};

template <>
struct std::formatter<Complex>
{
	std::formatter<double> m_underlying;
	bool m_polar = false;

	constexpr auto parse(auto& ctx)
	{
		auto it = ctx.begin();
		auto end = ctx.end();
		if (it == end || *it == '}')
		{
			return it;
		}

		auto endOfCustom = std::ranges::find(it, end, ':');

		if (it != endOfCustom) {
			if (*it != 'p') throw std::format_error("invalid format");
			m_polar = true;
			++it;
		}

		if (it == end || *it == '}')
		{
			return it;
		}

		if (it != endOfCustom) throw std::format_error("invalid format");

		ctx.advance_to(++endOfCustom);
		return m_underlying.parse(ctx);
	}

	auto format(const Complex& complex, auto& ctx) const
	{
		auto out = std::format_to(ctx.out(), "(");
		ctx.advance_to(out);
		out = m_underlying.format(m_polar ? complex.radius() : complex.real(), ctx);
		out = std::format_to(out, "{}", m_polar ? " * e^(" : " + ");
		ctx.advance_to(out);
		out = m_underlying.format(m_polar ? complex.angle() : complex.imag(), ctx);
		out = std::format_to(out, "{}", m_polar ? "i))" : "i)");
		return out;
	}
};
