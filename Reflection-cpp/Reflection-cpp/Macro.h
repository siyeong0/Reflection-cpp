#pragma once

// TpyeInfo를 생성하는 매크로
// 클래스 정의에 "MAKE_TYPE_INFO( CLASSNAME )" 추가
#define MAKE_TYPE_INFO(CLASS)	\
public:	\
	using Super = typename refl::SuperClassTypeDeduction<CLASS>::Type;	\
	using ThisType = CLASS;	\
public:	

// virtual function table이 생성됨; 인스턴스마다 8byte( sizeof(void*) ) 추가
#define MAKE_DYNAMIC_TYPE_INFO(CLASS)	\
public:	\
	using Super = typename refl::SuperClassTypeDeduction<CLASS>::Type;	\
	using ThisType = CLASS;	\
public:	\
	virtual const refl::TypeInfo& GetTypeInfo() const { return refl::GetStaticTypeInfo<ThisType>(); }	\
private:	
// ptr->GetTypeInfo()로 타입 정보를 얻어올 수 있음


#define MEMBER(TYPE, NAME)	\
	TYPE NAME;	\
inline static struct _registProperty##NAME	\
{	\
	_registProperty##NAME()	\
	{	\
		static refl::PropertyRegister	\
			<ThisType, decltype(NAME), decltype(&ThisType::NAME), &ThisType::NAME>	\
			propertyRegister##NAME(#NAME, refl::GetStaticTypeInfo<ThisType>());	\
	}	\
} regist##NAME;	
