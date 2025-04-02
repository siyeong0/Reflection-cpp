#pragma once

// TpyeInfo를 생성하는 매크로
// 클래스 정의에 "MAKE_TYPE_INFO( CLASSNAME )" 추가
// TypeInfo가 추가된 클래스는 virtual function table이 생성됨; 인스턴스마다 8byte( sizeof(void*) ) 추가
#define MAKE_TYPE_INFO(CLASS)	\
public:	\
	using Super = typename SuperClassTypeDeduction<CLASS>::Type;	\
	using ThisType = CLASS;	\
public:	\
	virtual const TypeInfo& GetTypeInfo() const { return TypeInfo::GetTypeInfo<ThisType>(); }	\
private:	\
// ptr->GetTypeInfo()로 타입 정보를 얻어올 수 있음


#define MEMBER(TYPE, NAME)	\
	TYPE NAME;	\
inline static struct _registProperty##NAME	\
{	\
	_registProperty##NAME()	\
	{	\
		static PropertyRegister	\
			<ThisType, decltype(NAME), decltype(&ThisType::NAME), &ThisType::NAME>	\
			propertyRegister##NAME(#NAME, TypeInfo::GetTypeInfo<ThisType>());	\
	}	\
} regist##NAME;	
