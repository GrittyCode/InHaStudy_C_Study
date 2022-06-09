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

StringBad::StringBad(const StringBad& s)
{
	len = s.len;
	str = new char[len + 1];
	strcpy(str,s.str);
	num_strings++;
	cout << num_strings << ": " << str << " - ���� ��ü����" << endl;
}

StringBad& StringBad::operator=(const StringBad& st)
{
	if (this == &st) //�ڱ� �ڽſ� ���Եȴٸ�
		return *this;
	delete [] str; //�� ���ڿ� ����
	len = st.len;
	str = new char[len + 1];
	strcpy(str, st.str);
	return *this; //ȣ���� ��ü�� ���� ������ �����Ѵ�.

}

std::ostream& operator<<(std::ostream& os, const StringBad& st)
{
	os << st.str;
	return os;
}
