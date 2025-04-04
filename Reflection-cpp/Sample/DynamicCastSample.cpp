#include "Sample.h"

#include <iostream>
#include <chrono>
#include <typeinfo>

#include "../Reflection-cpp/Reflection.h"

class A
{
public:
	virtual ~A() = default;

	MAKE_DYNAMIC_TYPE_INFO(A);
};

class B : public A
{
	MAKE_DYNAMIC_TYPE_INFO(B);
};

class C : public B
{
	MAKE_DYNAMIC_TYPE_INFO(C);
};


void DynamicCastSample()
{
	constexpr size_t TEST_N = 100000;

	void** test = new void*[TEST_N];
	for (int i = 0; i < TEST_N; ++i)
	{
		if (i % 3 == 0)
		{
			test[i] = new B;
		}
		else
		{
			test[i] = new C;
		}
	}

	// rtti dynamic cast
	std::cout << "RTTI dynamic cast." << std::endl;
	auto start = std::chrono::system_clock::now();

	int count1 = 0;
	for (int i = 0; i < TEST_N; ++i)
	{
		if (B* b = dynamic_cast<B*>(reinterpret_cast<A*>(test[i])))
		{
			++count1;
		}
	}

	auto end = std::chrono::system_clock::now();

	auto d1 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	std::cout << "count : " << count1 << std::endl;
	std::cout << d1.count() << std::endl << std::endl;

	// my reflection
	std::cout << "Reflection-cpp dynamic cast." << std::endl;
	start = std::chrono::system_clock::now();

	int count2 = 0;
	for (int i = 0; i < TEST_N; ++i)
	{
		if (B* b = DynamicCast<B*>(reinterpret_cast<A*>(test[i])))
		{
			++count2;
		}
	}

	end = std::chrono::system_clock::now();

	auto d2 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	std::cout << "count : " << count2 << std::endl;
	std::cout << d2.count() << std::endl << std::endl;
}