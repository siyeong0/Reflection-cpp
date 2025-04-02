#include "Sample/Sample.h"
#include "Reflection-cpp/Reflection.h"

struct Foo
{
	int a = 3;
	int b = 4;
};

int main(void)
{
	DynamicCastSample();
	FactorySample();
	MemberReflectionSample();

	return 0;
}
