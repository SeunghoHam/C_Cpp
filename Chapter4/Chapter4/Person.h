
// #pragma once; �̰� ����ص� ������, linux �� mac ȯ�濡���� ������� �ʴ´�. ǥ���� if and define �� ����ϴ� �� ifndef
#ifndef __PERSON_H__ // �������� ��ū�� define ���� �ʾҴٸ�� ���� ( ��ó�� if �� )
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
#define __PERSON_H__ // ���� ���ǵǾ� �ֱ⿡ ���ǵ��� �ʴ´�.

#endif // !__PERSON_H__
