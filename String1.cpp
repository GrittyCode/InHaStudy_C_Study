#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include "String1.h"

using std::cin;
using std::cout;


//static 클래스 멤버를 초기화한다

int String1::num_strings = 0;

String1::String1(const char* s)
{
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_strings++;
}

String1::String1()
{
    len = 4;
    str = new char[1];
    str[0] = '\0';
    num_strings++;
}

String1::String1(const String1& st)
{
    num_strings++;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
}

String1::~String1()
{
    --num_strings;
    delete[] str;
}

void String1::stringlow()
{
    for (int i = 0; i < len; ++i)
    {
        if (str[i] <= 'Z' && str[i] >= 'A')
        {
            str[i] += 32;
        }
    }
}

void String1::stringup()
{
    for (int i = 0; i < len; ++i)
    {
        if (str[i] <= 'z' && str[i] >= 'a')
        {
            str[i] -= 32;
        }
    }
}

int String1::has(char c)
{
    int cnt = 0;
    for (int i = 0; i < len; ++i)
    {
        if (str[i] == c) cnt++;
    }

    return cnt;
}

const char* String1::getStr()
{
    return str;
}

String1& String1::operator=(const String1& st)
{
    if (this == &st)
        return *this;
    delete[] str; //기존 문자열 삭제
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    return *this;
}

void String1::setlen(int length)
{
    len = length;
}

String1& String1::operator=(const char* s)
{
    delete[] str;
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    return *this;
}

void String1::setStr(const char* c)
{
    delete[] str;
    str = new char[len + 1];
    std::strcpy(str, c);
}



String1 String1::operator+(const String1& st1)
{
    String1 tmp;
    tmp.len = (len+st1.len);
    
    delete[] tmp.str;
    tmp.str = nullptr;

    tmp.str = new char[tmp.len + 1];
    std::strcpy(tmp.str, str);
    std::strcat(tmp.str,st1.str);
    return tmp;
}

String1 String1::operator+(const char* st1)
{
    String1 tmp;
    tmp.len = (len + std::strlen(st1));

    delete[] tmp.str;
    tmp.str = nullptr;

    tmp.str = new char[tmp.len + 1];
    std::strcpy(tmp.str, str);
    std::strcat(tmp.str, st1);
    return String1(tmp.str);
}

char& String1::operator[](int i)
{
    return str[i];
}

const char& String1::operator[](int i) const
{
    return str[i];
}

int String1::HowMany()
{
    return num_strings;
}

bool operator<(const String1& st1, const String1& st2)
{
    return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String1& st1, const String1& st2)
{
    return st2 < st1;
}

bool operator==(const String1& st1, const String1& st2)
{
    return (std::strcmp(st1.str, st2.str) == 0);
}


ostream& operator<<(ostream& os, const String1& st)
{
    os << st.str;
    return os;
}

istream& operator>>(istream& is, String1& st)
{
    char temp[String1::CINLIM];
    is.get(temp, String1::CINLIM);
    if (is)
        st = temp;
    while (is && is.get() != '\n')
        continue;
    return is;
}

const char* operator+(const char* c,String1 &st)
{
    st.setlen(st.length() + std::strlen(c));
    char temp[128];
    std::strcpy(temp, c);
    std::strcat(temp, st.getStr());
    return temp;
}
