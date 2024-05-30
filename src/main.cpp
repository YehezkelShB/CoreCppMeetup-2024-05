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
		Complex complex(1.0, 2.0);
		std::print("{}\n", complex);
		std::print("{:p}\n", complex);
	}
}
