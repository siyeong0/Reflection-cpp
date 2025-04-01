#pragma once
#include <string>
#include <vector>
#include <map>
#include "SuperClassDeduction.hpp"

// forward declaration
template <typename T> struct TypeInfoInitializer;

class Property;

class TypeInfo;

template <typename T>
static TypeInfo& getStaticTypeInfo();

class TypeInfo
{
public:
	template <typename T>
	explicit TypeInfo(const TypeInfoInitializer<T>& initializer)
		: mTypeHash(typeid(T).hash_code())
		, mName(initializer.Name)
		, mFullName(typeid(T).name())
		, mSuper(initializer.Super)
	{

	}

	template <typename T>
	static TypeInfo& GetStaticTypeInfo()
	{
		if constexpr (std::is_fundamental_v<T>)
		{
			static TypeInfo typeInfo(TypeInfoInitializer<T>{typeid(T).name()});
			return typeInfo;
		}
		else
		{
			return T::StaticTypeInfo();
		}
	}

	bool IsSame(const TypeInfo& other) const
	{
		if (this == &other)	// ���� ������ ������ �ּҰ� ���ƾ���
		{
			return true;
		}
		return mTypeHash == other.mTypeHash; //  DLL�� �и��� ���(�ٸ� �޸� ������ �Ҵ�) �ؽ��� �� TODO: ��ũ�� ���Ƿ� dll�� ������ ��� �ؽ��� ��� X
	}

	bool IsChildOf(const TypeInfo& other) const
	{
		if (IsSame(other))
		{
			return true;
		}

		for (const TypeInfo* super = mSuper; super != nullptr; super = super->mSuper)
		{
			if (super->IsSame(other))
			{
				return true;
			}
		}

		return false;
	}

	template <typename T>
	bool IsSame() const
	{
		return IsSame(T::StaticTypeInfo());
	}

	template <typename T>
	bool IsChildOf() const
	{
		return IsChildOf(T::StaticTypeInfo());
	}

	size_t GetHash() const { return mTypeHash; }
	const char* GetName() const { return mName; }
	const std::string& GetFullName() const { return mFullName; }

	// property
	void AddProperty(const char* name, const Property* prop)
	{
		mPropertyMap.insert({ name, prop });
	}

	const Property* GetProperty(const char* name) const
	{
		auto prop = mPropertyMap.find(name);
		if (prop != mPropertyMap.end())
		{
			return mPropertyMap.at(name);
		}
		else
		{
			return nullptr;
		}
	}

private:
	size_t mTypeHash;
	const char* mName;
	std::string mFullName;
	const TypeInfo* mSuper;

	std::map<std::string, const Property*> mPropertyMap;
};