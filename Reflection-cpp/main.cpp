#include <iostream>
#include <chrono>
#include <typeinfo>

#include "Reflection-cpp/Reflection.h"

//class A
//{
//public:
//	virtual ~A() = default;
//
//	MAKE_TYPE_INFO(A)
//};
//
//class B : public A
//{
//	MAKE_TYPE_INFO(B)
//};
//
//class C : public B
//{
//	MAKE_TYPE_INFO(C)
//};
//class D : public C
//{
//	MAKE_TYPE_INFO(D)
//};
//class E : public A
//{
//	MAKE_TYPE_INFO(E)
//};
//
//int main(void)
//{
//	constexpr size_t TEST_N = 10000000;
//
//	void** test = new void*[TEST_N];
//	for (int i = 0; i < TEST_N; ++i)
//	{
//		if (i % 3 == 0)
//		{
//			test[i] = new D;
//		}
//		else
//		{
//			test[i] = new E;
//		}
//	}
//
//	// rtti dynamic cast
//	auto start = std::chrono::system_clock::now();
//
//	int count1 = 0;
//	for (int i = 0; i < TEST_N; ++i)
//	{
//		if (B* b = dynamic_cast<B*>(reinterpret_cast<A*>(test[i])))
//		{
//			++count1;
//		}
//	}
//
//	auto end = std::chrono::system_clock::now();
//
//	auto d1 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
//	std::cout << "count : " << count1 << std::endl;
//	std::cout << d1.count() << std::endl << std::endl;
//
//	// my reflection
//	start = std::chrono::system_clock::now();
//
//	int count2 = 0;
//	for (int i = 0; i < TEST_N; ++i)
//	{
//		if (B* b = DynamicCast<B*>(reinterpret_cast<A*>(test[i])))
//		{
//			++count2;
//			auto typeInfo = b->GetTypeInfo();
//		}
//	}
//
//	end = std::chrono::system_clock::now();
//
//	auto d2 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
//	std::cout << "count : " << count2 << std::endl;
//	std::cout << d2.count() << std::endl << std::endl;
//	return 0;
//}

//class GameObject 
//{
//public:
//	virtual void print() const = 0;
//	virtual ~GameObject() = default;
//};
//
//class Player : public GameObject
//{
//public:
//	void print() const override { std::cout << "I am Player\n"; }
//};
//
//class Monster : public GameObject
//{
//public:
//	void print() const override { std::cout << "I am Monster\n"; }
//};
//
//#include "Reflection-cpp\Factory\Factory.h"
//
//FACTORY(GameObject)
//
//FACTORY_REGISTER(GameObject, Player);
//FACTORY_REGISTER(GameObject, Monster);
//
//template <typename T, typename U>
//class PropertyHandler
//{
//	using MemberPtr = U T::*;
//};
//
//int main(void)
//{
//	auto instanceA = GameObjectFactory::Create("Player");
//	auto instanceB = GameObjectFactory::Create("Monster");
//	auto instanceC = GameObjectFactory::Create("None");
//
//	if (instanceA) instanceA->print();
//	if (instanceB) instanceB->print();
//	if (!instanceC) std::cout << "Class None not found\n";
//}

#include "Reflection-cpp\Reflection.h"

class A
{
	MAKE_TYPE_INFO(A);

	MEMBER(Data);
public:
	int mData;
};

class B : public A
{
	MAKE_TYPE_INFO(B);

	MEMBER(Value);
public:
	float mValue;
};

int main(void)
{
	B b;
	A* a = &b;

	b.mValue = 0.4;

	const auto& typeInfo = a->GetTypeInfo();
	if (auto p = typeInfo.GetProperty("Value"))
	{
		float val = p->Get<float>(a);
		std::cout << "before: " << val << std::endl;

		p->Set<float>(a, 125);
		val = p->Get<float>(a);
		std::cout << "after: " << val << std::endl;
	}


}