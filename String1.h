#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using std::ostream;
using std::istream;
class String1
{
private:
	char* str; //문자열 지시 포인터
	int len; //문자열 길이
	static int num_strings; //객체의 수
	static const int CINLIM = 80; //cin 입력 합ㄴ계
public:
	String1(const char* s);
	String1();
	String1(const String1& st); //복사생성자
	~String1(); //소멸자
	int length() const { return len; }
	//오버로딩 연산자 메서드
	String1& operator=(const String1& st);
	String1& operator=(const char* s);
	char& operator[](int i);
	const char& operator[](int i) const;
	//static 함수
	static int HowMany();
	//오버로딩 연산자 프렌드
	friend bool operator<(const String1& st1, const String1& st2);
	friend bool operator>(const String1& st1, const String1& st2);
	friend bool operator==(const String1& st1, const String1& st2);
	friend ostream& operator<<(ostream &os, const String1& st);
	friend istream& operator>>(istream &is, String1& st);
};

