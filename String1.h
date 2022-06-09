#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using std::ostream;
using std::istream;
class String1
{
private:
	char* str; //���ڿ� ���� ������
	int len; //���ڿ� ����
	static int num_strings; //��ü�� ��
	static const int CINLIM = 80; //cin �Է� �դ���
public:
	String1(const char* s);
	String1();
	String1(const String1& st); //���������
	~String1(); //�Ҹ���
	int length() const { return len; }
	//�����ε� ������ �޼���
	String1& operator=(const String1& st);
	String1& operator=(const char* s);
	char& operator[](int i);
	const char& operator[](int i) const;
	//static �Լ�
	static int HowMany();
	//�����ε� ������ ������
	friend bool operator<(const String1& st1, const String1& st2);
	friend bool operator>(const String1& st1, const String1& st2);
	friend bool operator==(const String1& st1, const String1& st2);
	friend ostream& operator<<(ostream &os, const String1& st);
	friend istream& operator>>(istream &is, String1& st);
};

