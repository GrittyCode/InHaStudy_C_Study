#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using std::cout;
#include "StringBad.h"

void callme1(StringBad&);
void callme2(StringBad);

int main()
{
    //StringBad 구문
    /*
    using std::endl;
    cout << "내부 블록을 시작한다.\n";

    StringBad headline1("Celery Stalks at MidNight");
    StringBad headline2("Lettuce Prey");
    StringBad sports("Spinach Leaves Bowl for Dollars");

    cout << "headline1: " << headline1 << endl;
    cout << "headline2: " << headline2 << endl;
    cout << "headline3: " << sports << endl;

    callme1(headline1);
    // callme1(headline1);
    // callme2(headline2);

    //복사생성자를 따로 기수를 해줘서 이러한 오류를 없애줘야한다.
    //Default 복사생성자는 값을 옮기면서 메모리까지도 복사한다. 이를 없애주자.
    /*
     
    StringBad sailor = sports;
    cout << "sailor : " << sailor << endl;

    StringBad knot;
    //디폴트 생성자는 들어간다.
    knot = headline1;
    //대입 연산으로 넣어준 경우, knot이 headline1의 메모리 주소로 옮겨진다. 소멸자도 이를 해제시키므로 오류가 뜬다.
    //대입 연산도 따로 기수.
    
    생성자와 복사생성자, 대입연산자들을 제대로 기수하여 이러한 오류들을 없애주자.
    
    */
    


    return 0;
}


void callme1(StringBad& rsb)
{
    cout << "참조로 전달된 StringBad:\n";
    cout << "   \"" << rsb << "\"\n";
    //참조로 불러오기때문에 생성자, 소멸자 둘 다 부르지 않는다.
}

void callme2(StringBad sb)
{
    cout << "값으로로 전달된 StringBad:\n";
    cout << "   \"" << sb << "\"\n";
    //생성자는 생기지 않지만 값 복사한 메모리의 주소에 소멸자를 불러줘서 오류가 난다. (복사생성자를 따로 기수한 내용이 없기때문에 컴파일러가 알아서 해준다)
    //소멸자는 이 지역이 끝난 경우에는 자동으로 부르기때문에 소멸자는 불러진다.
}