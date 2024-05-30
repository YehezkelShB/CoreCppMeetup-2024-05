#pragma once

#include <iosfwd>

class MyType
{
};

std::ostream& operator<<(std::ostream& os, const MyType& obj);
