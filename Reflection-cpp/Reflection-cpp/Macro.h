#pragma once

// TpyeInfo�� �����ϴ� ��ũ��
// Ŭ���� ���ǿ� "MAKE_TYPE_INFO( CLASSNAME )" �߰�
#define MAKE_TYPE_INFO(CLASS)	\
public:	\
	using Super = typename SuperClassTypeDeduction<CLASS>::Type;	\
	using ThisType = CLASS;	\
public:	

// virtual function table�� ������; �ν��Ͻ����� 8byte( sizeof(void*) ) �߰�
#define MAKE_DYNAMIC_TYPE_INFO(CLASS)	\
public:	\
	using Super = typename SuperClassTypeDeduction<CLASS>::Type;	\
	using ThisType = CLASS;	\
public:	\
	virtual const TypeInfo& GetTypeInfo() const { return TypeInfo::GetTypeInfo<ThisType>(); }	\
private:	
// ptr->GetTypeInfo()�� Ÿ�� ������ ���� �� ����


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
