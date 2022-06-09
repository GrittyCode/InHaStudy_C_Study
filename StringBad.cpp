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

StringBad::StringBad(const StringBad& s)
{
	len = s.len;
	str = new char[len + 1];
	strcpy(str,s.str);
	num_strings++;
	cout << num_strings << ": " << str << " - 복사 객체생성" << endl;
}

StringBad& StringBad::operator=(const StringBad& st)
{
	if (this == &st) //자기 자신에 대입된다면
		return *this;
	delete [] str; //옛 문자열 해제
	len = st.len;
	str = new char[len + 1];
	strcpy(str, st.str);
	return *this; //호출한 객체에 대한 참조를 리턴한다.

}

std::ostream& operator<<(std::ostream& os, const StringBad& st)
{
	os << st.str;
	return os;
}
