#include "StringBad.h"
#include<cstring>

using namespace std;

int StringBad::num_strings = 0;

StringBad::StringBad(const char* s)
{
	len = strlen(s);
	str = new char[len + 1]; //NULL까지 포함
	strcpy(str,s);
	num_strings++; //객체 카운트 + 1
	cout << num_strings << ": " << str << " - 객체생성" << endl;
}

StringBad::StringBad()
{
	len = 4;
	str = new char[4]; //NULL까지 포함
	strcpy(str, "C++");
	num_strings++; //객체 카운트 + 1
	cout << num_strings << ": " << str << " - 객체생성" << endl;
}

StringBad::~StringBad()
{
	cout << " 객체파괴" << endl;
	--num_strings;
	cout << " 남은 객체 수 : " << num_strings << endl;
	delete[] str;
}

std::ostream& operator<<(std::ostream& os, const StringBad& st)
{
	os << st.str;
	return os;
}
