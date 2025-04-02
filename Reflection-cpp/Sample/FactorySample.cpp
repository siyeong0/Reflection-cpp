#include "Sample.h"

#include <iostream>

#include "../Reflection-cpp/Reflection.h"

class GameObject
{
public:
	virtual void print() const = 0;
	virtual ~GameObject() = default;
};

class Player : public GameObject
{
public:
	virtual void print() const override { std::cout << "I am Player\n"; }
};

class Monster : public GameObject
{
public:
	virtual void print() const override { std::cout << "I am Monster\n"; }
};

BUILD_FACTORY(GameObject)

FACTORY_REGISTER(GameObject, Player);
FACTORY_REGISTER(GameObject, Monster);

void FactorySample()
{
	auto instanceA = GameObjectFactory::Create("Player");
	auto instanceB = GameObjectFactory::Create("Monster");
	auto instanceC = GameObjectFactory::Create("None");

	if (instanceA) instanceA->print();
	if (instanceB) instanceB->print();
	if (!instanceC) std::cout << "Class None not found\n" << std::endl;
}