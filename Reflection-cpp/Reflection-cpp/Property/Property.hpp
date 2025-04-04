#pragma once
#include <cassert>
#include "../TypeInfo/TypeInfo.hpp"
#include "PropertyHandler.hpp"
#include "PropertyInitializer.hpp"

namespace refl
{
	class Property
	{
	public:
		template <typename T>
		const T& Get(void* object) const
		{
			if (mHandler.GetTypeInfo().IsChildOf<IPropertyHandler<T>>())
			{
				auto concreteHandler = static_cast<const IPropertyHandler<T>*>(&mHandler);
				return concreteHandler->Get(object);
			}
			else
			{
				assert(false && "Invalid casting");
				return *reinterpret_cast<T*>(nullptr);
			}
		}

		template <typename T>
		void Set(void* object, const T& value) const
		{
			if (mHandler.GetTypeInfo().IsChildOf<IPropertyHandler<T>>())
			{
				auto concreteHandler = static_cast<const IPropertyHandler<T>*>(&mHandler);
				concreteHandler->Set(object, value);
			}
			else
			{
				assert(false && "Invalid casting");
			}
		}

		Property(TypeInfo& ownerTypeInfo, const PropertyInitializer& initializer)
			: mName(initializer.Name)
			, mTypeInfo(ownerTypeInfo)
			, mHandler(initializer.Handler)
		{
			ownerTypeInfo.AddProperty(mName, this);
		}

		const char* GetName() const { return mName; }

	private:
		const char* mName;
		const TypeInfo& mTypeInfo;
		const PropertyHandlerBase& mHandler;
	};
}
