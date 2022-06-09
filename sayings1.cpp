#include<iostream>
#include "String1.h"

const int ArSize = 10;
const int MaxLen = 81;

using std::cout;
using std::cin;
using std::endl;

void callme(String1);
void callme1(String1&);
int main()
{

	String1 name;
	cout << "안녕하십니까? 성함이 어떻게 되십니까?\n>> ";
	cin >> name;

	cout << name << " 씨! 간단한 영어속담 " << ArSize << "개만 입력해 주십시오(끝내려면 Enter) : \n";
	String1 sayings[ArSize];
	char temp[MaxLen];
	int i;
	for (i = 0; i < ArSize; ++i)
	{
		cout << i + 1 << ": ";
		cin.get(temp, MaxLen);
		while (cin && cin.get() != '\n')
			continue;
		if (!cin || temp[0] == '\0')
			break;
		else
			sayings[i] = temp;
	}

	int total = i;
	if (total > 0)
	{
		cout << "(다음과 같은 속담들을 입력하셨습니다.)\n";
		for (i = 0; i < total; ++i)
			cout << sayings[i][0] << ": " << sayings[i] << endl;

		int shortest = 0;
		int first = 0;
		for (i = 1; i < total; ++i)
		{
			if (sayings[i].length() < sayings[shortest].length())
				shortest = i;
			if (sayings[i] < sayings[first])
				first = i;
		}

		cout << "가장 짧은 속담 : \n" << sayings[shortest] << endl;
		cout << "사전순으로 가장 앞에 나오는 속담 : \n" << sayings[first] << endl;
		cout << "이 프로그램은 " << String1::HowMany() << " 개의 String 객체를 사용하였습니다. 이상!\n";
	}
	else
	{
		cout << "입력 금지! 이상.\n";
	}

	cout << "값 callme 이전의 객체 개수 : " << name.HowMany() << "\n";
	callme(sayings[0]);
	cout << "값 callme 이후의 객체 개수 : " << name.HowMany() << "\n";


	cout << "참조 callme 이전의 객체 개수 : " << name.HowMany() << "\n";
	callme1(sayings[0]);
	cout << "참조 callme 이후의 객체 개수 : " << name.HowMany() << "\n";

}

void callme(String1 str)
{
	cout << "값 복사한 내용 : " << str << endl;
	cout << "개수는 몇개로 된건가? : " << str.HowMany();
}

void callme1(String1& str)
{
	cout << "참조 복사한 내용 : " << str << endl;
	cout << "개수는 몇개로 된건가? : " << str.HowMany();

}
