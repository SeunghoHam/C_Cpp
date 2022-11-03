
// #pragma once; 이걸 사용해도 되지만, linux 나 mac 환경에서는 적용되지 않는다. 표준은 if and define 을 사용하는 것 ifndef
#ifndef __PERSON_H__ // 오른쪽의 토큰이 define 되지 않았다면.
#define __PERSON_H__


#include "Animal.h"

class Person :Animal
{
public:
	char regist_no[50];
	Person(const char* regist_no, const char* person_name);

	void printInfo();
};


#endif


#ifndef __PERSON_H__
#define __PERSON_H__ // 위에 정의되어 있기에 define을 하지 않는다.

#endif // !__PERSON_H__
