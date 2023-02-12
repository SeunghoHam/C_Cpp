#ifndef __HEADER_H__
#define __HEADER_H__

#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<map>
#include<string>



// �޴� �Է��ϱ�
int GetInt(const char* prompt);

// ���� �Է��ϱ�
std::string GetString(const char* prompt);

class Dictionary 
{
private:
	std::map<std::string, std::string> words;
public:
	// �ܾ� ����
	// std::string�� �Ķ���ͷ� �ްԵǸ� �� ���簡 �Ͼ.
	//  map �� Assign �� �� �� �ѹ� �����簡 �߻���.
	// ������ �״�� �������⶧���� �����簡 �Ͼ������
	//void InsertWorld(std::string word, std::string meaning)
	void InsertWorld(const std::string& word, const std::string& meaning);
	// �ܾ �ִ��� ������ Ȯ��
	bool Exist(const std::string& word);
	// ���� ������.
	std::string GetMean(std::string word);
};


#endif // !__HEAER_H__

