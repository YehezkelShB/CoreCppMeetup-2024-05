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
	bool m_polar = false;

	constexpr auto parse(auto& ctx)
	{
		auto it = ctx.begin();

		if (it == ctx.end() or *it == '}')
		{
			return it;
		}

		if (*it++ == 'p')
		{
			m_polar = true;
		}
		else
		{
			throw std::format_error("invalid format");
		}

		return it;
	}

	auto format(const Complex& complex, auto& ctx) const
	{
		if (m_polar)
		{
			return std::format_to(ctx.out(), "({} * e^({}i))", complex.radius(), complex.angle());
		}
		return std::format_to(ctx.out(), "({} + {}i)", complex.real(), complex.imag());
	}
};
