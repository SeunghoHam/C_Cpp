// �Լ� ���� ������ ���Ͽ�

// ���α׷��� ���� ����

// ���α׷��� ����� �� Stack �� Heap �޸𸮰� �����Ѵ�.
// Stack ������ �����ϴ� ������ ������ ����( �Լ� �� ���ÿ� ���� ������ ������ ���´� )
// Heap ������ �����ϴ� ������ ������ ����( �����ֱⰡ ������ ������ �����ȴ� )

// if �츮�� ���α׷��� ������
/*
* 1. ����Ʈ �迭�� ������� exe ������ RAM �޸𸮿� �ö�.
* 2. OS�� ���ؼ� Instructinos �� �����ڵ尡 ��������Ե�.
* 3. Stack���� �Լ� �ݽ����� �����Ѵ�. ( ���� �޸� ) / ex) int a[10];
* 4. Heap ���� ���� �޸𸮸� �����Ѵ�. ( ����, ������ �޸� ) / ��� Heap �� ������ �� �� ����.
* 
*/

// 3_1. new Ű���带 �̿��� ������ ���� ����, Ŭ���� �ν��Ͻ����� Stack �� �׾Ƶΰ� �Լ��� ������ Stack�� ���Եȴ�.
// 4_1. Heap ������ �Լ����� new Ű���带 �̿��� ���� �Լ��� ������ ������������. delete ���� �̿��Ͽ� ���������



// sum �Լ� ����Ǵ� ����

/*
* 1. Stack �� int v1,v2 ����, ���� ������ r ���� ����
* 2. Instruction�� ���� sum�̶�� �Լ��� �����ϰ� ��
* 3. sum�̶�� �Լ��� �Ķ���� a,b ,results(�������)�� stack�� ����
* 4. sum �Լ��� �����Ų �������� ���ƿ� r �̶�°��� ����ִ´�.
* 5. stack���� sum�� ���õ� �κ��� ���ش�.
* 6. Insturction���� ���� ȣ���� printf�̹Ƿ� ���� 3�� r�� ȣ���ϱ� ���� call Stack �� ���������. �� ���Ĵ� ���� ����	 
*/

// �̷��� �Լ��� call Stack �� �������ϱ� ������ �Լ����� �Լ� ȣ�� ����� �ִ�.
// �Լ� ȣ���� �Ѵٴ� ���� ����������, �޸������� ������� ���ظ� �����ؾ� �Ѵٴ� ���̴�.
#include<cstdio>
int sum(int a, int b)
{
	int result = a + b;
	return result;
}

int main()
{
	int v1 = 1;
	int v2 = 2;

	int r = sum(v1, v2);
	printf("��� : %d", r);

	return 0;
}

/*
{
	"event_version": 32,
		"event_filename" : "popup_event.jpg",
		"event_url" : "https://smartstore.naver.com/xosoft/products/7108154599",
		"event2_version" : 11,
		"event2_filename" : "popup_event2.jpg",
		"event2_url" : "https://smartstore.naver.com/xosoft/category/9aaf64567aa449b39da8c32072f36ac1?cp=1",
		"update_version" : 7,
		"update_filename" : "popup_update.jpg",
		"update_url" : ""
}


{
	"event_version": 33,
		"event_filename" : "popup_event.jpg",
		"event_url" : "https://smartstore.naver.com/xosoft/products/7108154599",
		"event2_version" : 11,
		"event2_filename" : "popup_event2.jpg",
		"event2_url" : "https://smartstore.naver.com/xosoft/products/7695703255",
		"update_version" : 7,
		"update_filename" : "popup_update.jpg",
		"update_url" : ""
}*/