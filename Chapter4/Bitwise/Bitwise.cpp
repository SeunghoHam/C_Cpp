#include<cstdio>
#include<cmath>

void foo(int param);
int main()
{
	/*
	��Ʈ������ ���� : ��Ʈ�� �������� ������ �ϴ°�.

		��Ʈ������and : &������
		��Ʈ������ or : | ������ Ȱ��
		���� ����Ʈ : << ���׿����� Ȱ�� [ �������� �� ĭ�� ��Ʈ�̵�, 0�� ���� ]
		������ ����Ʈ : >> ���׿����� Ȱ��[ ���������� �� ĭ�� ��Ʈ�̵� ]


		��Ʈ������ ������ �� �ؾ��ϴ°�?
		��ǻ�ʹ� �⺻������ ��Ʈ������ ������ ���̽��� ��Ģ������ �Ѵ�. �� �� ����
			ex) ����Ʈ ���� : "<< n":  n ��ŭ 2�� ���� ��, " >> n " : n ��ŭ 0.5�� ���� ��


		��Ʈ������� ī�װ��� �����س��� ���� ���� ����Ѵ�.
		int = 32��Ʈ. ��Ʈ �ϳ��ϳ��� �Ҵ����� �� ����. ex) Unity Layer ���� ���̾� �����ϴ°�
		*/

	int v1 = 1; // 0001
	int v2 = 3; // 0011

	//(or = �� �� �ϳ��� true ��� true��ȯ)
	int bitwise_or = v1 | v2;
	//~result(bitwise_or) = 3 (int ���� 4��Ʈ�� ���� int = 32bit)
	//�� ��Ʈ���� or ������ �Ͽ�[0, 0, 1, 1] �� ���� �ȴ�.

	int bitwise_and = v1 & v2;

	int shift_left = v2 << 1; // 0110  = 6
	int shift_right = v2 >> 1; // 0001 = 1

	printf("Bitwise_or : %d\n", bitwise_or);
	printf("Bitwise_and : %d\n", bitwise_and);
	printf("shift_left : %d\n", shift_left);
	printf("shift_right : %d\n", shift_right);

	
	// �浹 ���̾� [ ��, ��������, ��, X�Ⱦ� ]
	int mario_category = 8 + 4 + 2 + 1; // [ 1, 1, 1, 1 ] 
	int enemy_category = 0 + 4 + 2 + 1; // [ 0, 1, 1, 1 ]
	int ghost_category = 0 + 0 + 2 + 1; // [ 0, 0, 1, 1 ]
	int terrain_category = 0 + 4 + 0 + 0; // [0, 1, 1, 0 ]


	foo(1 | 2 | 4); // �̷��� �� ����?


	// ���� mario �� enemy �� �浹�� �� ( and ���� ) 
	// ��� : 1�� ���� �浹. true

	// ���� ghost�� terrain �� �浹�� ��
	// ��� : 0�� ����. �浹 fasle
	return 0;
}


// ��Ʈ������ ������ ����
// �Ķ���ͷ� ���� int �� ���� ī�װ��� �޴´ٴ� ����
void foo(int param)
{
	int category1 = 1;
	int category2 = 1 << 1;
	int category3 = 1 << 2;

	if ((category1 & param) != 0) // param�̶� ��Ʈ������and ���� �� ���� 0�� �ƴϴ� = �Ѵ� 1 �̾�� 1
	{
		printf("ī�װ� 1�� ����\n");
	}
	if ((category2 & param) != 0)
	{
		printf("ī�װ� 2�� ����\n");
	}
	if ((category3 & param) != 0)
	{
		printf("ī�װ� 3�� ����\n");
	}
}