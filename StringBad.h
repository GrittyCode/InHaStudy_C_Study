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
	StringBad(const StringBad& s);
	StringBad(const char* s);
	StringBad();
	~StringBad();
	StringBad& operator=(const StringBad& st);
	friend std::ostream& operator<<(std::ostream& os, const StringBad& st);
};

