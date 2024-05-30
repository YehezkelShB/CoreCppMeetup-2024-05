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

	constexpr auto parse(auto& ctx)
	{
		return m_underlying.parse(ctx);
	}

	auto format(const Complex& complex, auto& ctx) const
	{
		auto out = std::format_to(ctx.out(), "(");
		ctx.advance_to(out);
		out = m_underlying.format(complex.real(), ctx);
		out = std::format_to(out, " + ");
		ctx.advance_to(out);
		out = m_underlying.format(complex.imag(), ctx);
		out = std::format_to(out, "i)");
		return out;
	}
};
