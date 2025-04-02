#include "Sample.h"

#include <iostream>

#include "../Reflection-cpp/Reflection.h"

class Foo
{
	MAKE_TYPE_INFO(Foo);
public:
	MEMBER(int, mData1);
	MEMBER(int, mData2);

	Foo() : mData1(1), mData2(2) {}
};

class Dumb : public Foo
{
	MAKE_TYPE_INFO(Dumb);
public:
	MEMBER(float, mValue);

	Dumb() : Foo(), mValue(3.0f) {}
};


void MemberReflectionSample()
{
	Dumb dumb;
	Foo* foo = &dumb;

	dumb.mValue = 0.4f;

	const auto& typeInfo = foo->GetTypeInfo();

	std::cout << "Member 'mValue' test" << std::endl;
	if (auto p = typeInfo.GetProperty("mValue"))
	{
		float val = p->Get<float>(foo);
		std::cout << "before: " << val << std::endl;

		p->Set<float>(foo, 125.5f);
		val = p->Get<float>(foo);
		std::cout << "after: " << val << std::endl << std::endl;
	}
	std::cout << "Member 'mData1' test" << std::endl;
	if (auto p = typeInfo.GetProperty("mData1"))
	{
		int val = p->Get<int>(foo);
		std::cout << "before: " << val << std::endl;

		p->Set<int>(foo, 55);
		val = p->Get<int>(foo);
		std::cout << "after: " << val << std::endl << std::endl;
	}
	std::cout << "Member 'mData2' test" << std::endl;
	if (auto p = typeInfo.GetProperty("mData2"))
	{
		int val = p->Get<int>(foo);
		std::cout << "before: " << val << std::endl;

		p->Set<int>(foo, -33);
		val = p->Get<int>(foo);
		std::cout << "after: " << val << std::endl << std::endl;
	}
	std::cout << "Non-exist member test" << std::endl;
	if (auto p = typeInfo.GetProperty("mNone"))
	{
		std::cout << "Member mNone exists." << std::endl;
	}
	else
	{
		std::cout << "Member mNone not exists." << std::endl;
	}
}