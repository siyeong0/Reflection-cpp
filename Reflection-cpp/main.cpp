#include "Sample/Sample.h"
#include "Reflection-cpp/Reflection.h"

#include <iostream>

struct Foo
{
	int a = 3;
	int b = 4;
};

template <typename T, FixedString str>
void Func(const std::string_view& name)
{
	if constexpr(FixedString{"foo"} == FixedString{"foo"})
	{
		std::cout << "a" << std::endl;
	}
}

int main(void)
{
	Func<int, "foo">("abc");
	Func<int, "foo">("foo");

	DynamicCastSample();
	FactorySample();
	MemberReflectionSample();

	return 0;
}
