#pragma once
// TpyeInfo를 생성하는 매크로
// 클래스 정의에 "MAKE_TYPE_INFO( CLASSNAME )" 추가
// TypeInfo가 추가된 클래스는 virtual function table이 생성됨; 인스턴스마다 8byte( sizeof(void*) ) 추가
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
// ptr->GetTyoeInfo()로 타입 정보를 얻어올 수 있음