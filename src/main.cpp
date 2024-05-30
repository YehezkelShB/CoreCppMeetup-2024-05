#include "MyType.h"
#include "MyString.h"
#include "Complex.h"

#include <iostream>

#include <format>
#include <print>

int main()
{
	MyType obj;
	std::cout << obj << '\n';

	std::print("Hello, {}!\n", "world");
	std::puts(std::format("Answer: {}!", 42).c_str());

	{
		MyString str("Hello, world!");
		std::print("{}\n", str);
		//std::print("{:*^20}\n", str);
	}

	{
		Complex complex(3.123, 2.7);
		std::print("{}\n", complex);
		std::print("{:p}\n", complex);
		std::print("{:p:f}\n", complex);
		std::print("{::f}\n", complex);
		std::print("{::}\n", complex);
	}
}
