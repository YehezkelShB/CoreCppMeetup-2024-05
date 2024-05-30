#include "MyType.h"

#include <iostream>

std::ostream& operator<<(std::ostream& os, const MyType& /*obj*/)
{
	return os << "MyType";
}
