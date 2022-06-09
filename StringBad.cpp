#include "StringBad.h"
#include<cstring>

using namespace std;

int StringBad::num_strings = 0;

StringBad::StringBad(const char* s)
{
	len = strlen(s);
	str = new char[len + 1]; //NULL���� ����
	strcpy(str,s);
	num_strings++; //��ü ī��Ʈ + 1
	cout << num_strings << ": " << str << " - ��ü����" << endl;
}

StringBad::StringBad()
{
	len = 4;
	str = new char[4]; //NULL���� ����
	strcpy(str, "C++");
	num_strings++; //��ü ī��Ʈ + 1
	cout << num_strings << ": " << str << " - ��ü����" << endl;
}

StringBad::~StringBad()
{
	cout << " ��ü�ı�" << endl;
	--num_strings;
	cout << " ���� ��ü �� : " << num_strings << endl;
	delete[] str;
}

std::ostream& operator<<(std::ostream& os, const StringBad& st)
{
	os << st.str;
	return os;
}
