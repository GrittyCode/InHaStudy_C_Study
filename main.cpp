#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "StringBad.h"

using namespace std;

void callme1(StringBad&);
void callme2(StringBad);

int main()
{
    StringBad headline1("Celery Stalks at MidNight");
    StringBad headline2("Lettuce Prey");
    StringBad sports("Spinach Leaves Bowl for Dollars");

    cout << "headline1: " << headline1 << endl;
    cout << "headline2: " << headline2 << endl;
    cout << "headline3: " << sports << endl;

    callme1(headline1);

    callme2(headline2);
    return 0;
}


void callme1(StringBad& c)
{
    cout << "참조 StringBad " << c << endl;
    //참조로 불러오기때문에 생성자, 소멸자 둘 다 부르지 않는다.
}

void callme2(StringBad c)
{
    cout << "값 StringBad " << c << endl;
    //생성자는 생기지 않지만 값 복사한 메모리의 주소에 소멸자를 불러줘서 오류가 난다. (복사생성자를 따로 기수한 내용이 없기때문에 컴파일러가 알아서 해준다)
    //소멸자는 이 지역이 끝난 경우에는 자동으로 부르기때문에 소멸자는 불러진다.
}