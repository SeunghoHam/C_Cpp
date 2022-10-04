#include<cstdio>
#include<cstring>
// 오버로드 정의:
// 같은 이름의 함수명이지만, 파라미터 반환값 등을 다르게 설정하여 다양하게 정의할 수 있다.
class Vector
{
public:
	float x;
	float y;
public:
	Vector()
	{
		x = 0.0f;
		y = 0.0f;
	}
	Vector(float _x, float _y)
	{
		this->x = _x;
		this->y = _y;
	}
	void printInfo()

	{
		printf("%.2f, %.2f", x, y);
}
};

Vector operator+(Vector& _v1, Vector& _v2) // 오퍼레이터를 활용하여 기본 사칙연산을 다른 구조에도 사용할 수 있다.
{
	// & 레퍼런스 형태로 가져와야 퍼포먼스가 좋다. 값복사가 일어나지않음
	return Vector(_v1.x + _v2.x, _v1.y + _v2.y);
}


class Vector3
{
public:
	float x;
	float y;
	float z;
	Vector3()
	{
		x = 0;
		y = 0;
		z = 0;
	}
	Vector3(float _x, float _y, float _z)
	{
		this->x = _x;
		this->y = _y;
		this->z = _z;
	}
	void printInfo()
	{
		printf("%.2f, %.2f, %.2f", x, y, z);
	}
};

Vector3 operator*(Vector3& v1, float scalar) // scalar : 물리/수학적으로 어떤 양적인 수치
{
	return Vector3(v1.x * scalar, v1.y * scalar, v1.z * scalar);
}


int main()
{
	Vector v1 = Vector(1,2);
	Vector v2 = Vector(100, 200);

	Vector v3 = v1 + v2;

	//v3.printInfo();
	Vector3	v = Vector3(10, 20, 30);

	Vector3 result = v * 10;
	result.printInfo();
}