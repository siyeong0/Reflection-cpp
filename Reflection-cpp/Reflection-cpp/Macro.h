#pragma once

// TpyeInfo�� �����ϴ� ��ũ��
// Ŭ���� ���ǿ� "MAKE_TYPE_INFO( CLASSNAME )" �߰�
#define MAKE_TYPE_INFO(CLASS)	\
public:	\
	using Super = typename refl::SuperClassTypeDeduction<CLASS>::Type;	\
	using ThisType = CLASS;	\
public:	

// virtual function table�� ������; �ν��Ͻ����� 8byte( sizeof(void*) ) �߰�
#define MAKE_DYNAMIC_TYPE_INFO(CLASS)	\
public:	\
	using Super = typename refl::SuperClassTypeDeduction<CLASS>::Type;	\
	using ThisType = CLASS;	\
public:	\
	virtual const refl::TypeInfo& GetTypeInfo() const { return refl::GetStaticTypeInfo<ThisType>(); }	\
private:	
// ptr->GetTypeInfo()�� Ÿ�� ������ ���� �� ����


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
