#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>


class StringBad
{
private:
	char* str; //���ڿ��� �����ϴ� ������
	int len; //���ڿ��� ����
	static int num_strings; //��ü�� ��
public:
	StringBad(const char* s);
	StringBad();
	~StringBad();
	friend std::ostream& operator<<(std::ostream& os, const StringBad& st);
};

