#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>


class StringBad
{
private:
	char* str; //문자열을 지시하는 포인터
	int len; //문자열의 길이
	static int num_strings; //객체의 수
public:
	StringBad(const StringBad& s);
	StringBad(const char* s);
	StringBad();
	~StringBad();
	StringBad& operator=(const StringBad& st);
	friend std::ostream& operator<<(std::ostream& os, const StringBad& st);
};

