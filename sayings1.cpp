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
	cout << "�ȳ��Ͻʴϱ�? ������ ��� �ǽʴϱ�?\n>> ";
	cin >> name;

	cout << name << " ��! ������ ����Ӵ� " << ArSize << "���� �Է��� �ֽʽÿ�(�������� Enter) : \n";
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
		cout << "(������ ���� �Ӵ���� �Է��ϼ̽��ϴ�.)\n";
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

		cout << "���� ª�� �Ӵ� : \n" << sayings[shortest] << endl;
		cout << "���������� ���� �տ� ������ �Ӵ� : \n" << sayings[first] << endl;
		cout << "�� ���α׷��� " << String1::HowMany() << " ���� String ��ü�� ����Ͽ����ϴ�. �̻�!\n";
	}
	else
	{
		cout << "�Է� ����! �̻�.\n";
	}

	cout << "�� callme ������ ��ü ���� : " << name.HowMany() << "\n";
	callme(sayings[0]);
	cout << "�� callme ������ ��ü ���� : " << name.HowMany() << "\n";


	cout << "���� callme ������ ��ü ���� : " << name.HowMany() << "\n";
	callme1(sayings[0]);
	cout << "���� callme ������ ��ü ���� : " << name.HowMany() << "\n";

}

void callme(String1 str)
{
	cout << "�� ������ ���� : " << str << endl;
	cout << "������ ��� �Ȱǰ�? : " << str.HowMany();
}

void callme1(String1& str)
{
	cout << "���� ������ ���� : " << str << endl;
	cout << "������ ��� �Ȱǰ�? : " << str.HowMany();

}
