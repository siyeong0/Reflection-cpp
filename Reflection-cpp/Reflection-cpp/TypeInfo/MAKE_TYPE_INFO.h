#pragma once
// TpyeInfo�� �����ϴ� ��ũ��
// Ŭ���� ���ǿ� "MAKE_TYPE_INFO( CLASSNAME )" �߰�
// TypeInfo�� �߰��� Ŭ������ virtual function table�� ������; �ν��Ͻ����� 8byte( sizeof(void*) ) �߰�
#define MAKE_TYPE_INFO(CLASS)	\
public:	\
	using Super = typename SuperClassTypeDeduction<CLASS>::Type;	\
	using ThisType = CLASS;	\
public:	\
	virtual const TypeInfo& GetTypeInfo() const { return mTypeInfo; }	\
\
	static TypeInfo& StaticTypeInfo()	\
	{	\
		static TypeInfo typeInfo{ TypeInfoInitializer<ThisType>(#CLASS) };	\
		return typeInfo;	\
	}	\
private:	\
	inline static TypeInfo& mTypeInfo = StaticTypeInfo();	\
// ptr->GetTyoeInfo()�� Ÿ�� ������ ���� �� ����