#include <iostream>
#include <string>
#include<cmath>
#include<stack>
#include<queue>

using namespace std;


struct oper
{
	oper(int p, string c_oper) { this->p = p; this->c_oper = c_oper; }
	int p;
	string c_oper;
};

stack<oper> stk;
queue<string> que;
stack<double> numstk;

void CheckOperator(string op)
{
	if (op == "(")
	{
		stk.push(oper(0, op));
	}
	else if (op == ")")
	{
		while (!stk.empty() && stk.top().c_oper != "(")
		{
			que.push(stk.top().c_oper);
			stk.pop();
		}
		stk.pop();
	}
	else if (op == "+" || op == "-" || op == "*" || op == "/")
	{
		int idx = 0;
		if (op == "+" || op == "-")
		{
			idx = 1;
		}
		else //+,/
		{
			idx = 2;
		}
		while (!stk.empty() && stk.top().p >= idx) //�ڽ��� �켱�������� ���ų� ���� ��쿡�� ����� ���ش�.
		{
			que.push(stk.top().c_oper);
			stk.pop();
		}
		stk.push(oper(idx, op));
	}
}


void calc()
{
	while (!que.empty())
	{
		if (que.front() != "+" && que.front() != "-" && que.front() != "*" && que.front() != "/") //�����ڰ� �ƴ� ��쿡��
		{
			numstk.push(std::stod(que.front()));
			que.pop();
		}
		else //�������� ���
		{
			double b = numstk.top();
			numstk.pop();
			double a = numstk.top();
			numstk.pop();
			double result;
			if (que.front() == "+")
			{
				result = a + b;
			}
			else if (que.front() == "-")
			{
				result = a - b;
			}
			else if (que.front() == "*")
			{
				result = a * b;
			}
			else if (que.front() == "/")
			{
				result = a / b;
			}
			numstk.push(result);
			que.pop();
		}
	}


}

int main()
{
	string input = "-2*(-1-1)-3.9+6/((3+3)/6.0)";
	//���ڿ��� �޾��ְ� �̸� ������, ���ڸ� ���������ش�.
	//�������� ��� �켱������ ����������Ѵ�.
	//() < +,- < *,/�� �ִµ� ( �� ��� �׳� ���ÿ� �����ְ� )�� ������� ���� ��ȣ�� ���������� ����� �������ش�.
	//����, ������ ���� ���ʿ� �ִ� �������ǰ� �켱������ �� ���� ��� �ٷ� ť�� �������ش�. �켱������ �� ���ų� ������������ ����, ������ �������� �ݺ��Ѵ�.
	//���Ŀ�, �ڽ��� ������ ���ÿ� �־��ش�.

	//����, ť�� ���� ǥ������� �ٲ��ش�.

	cout << "����ǥ��� : " << input << "\n";

	bool isNumber = false;
	string tmp;

	for (int i = 0; i < input.size(); ++i)
	{
		if (((input[i] == '-' && !isNumber))) //�Ǽ��� ������ ���� ���� (������ �������� ���� -�� ������ üũ���ִ� ��)
		{
			tmp += input[i];
			isNumber = false;
		}
		else if (input[i] >= '0' && input[i] <= '9')
		{
			while ((input[i] >= '0' && input[i] <= '9') || input[i] == '.')
			{
				tmp += input[i];
				i++;
			}
			i--;
			que.push(tmp); //���ڴ� �׳� �����ش�.
			isNumber = true;
			tmp.clear();
		}
		else
		{
			if (input[i] != '(' && input[i] != ')') isNumber = false; //������
			string tmp;
			tmp = input[i];
			CheckOperator(tmp);

		}
	}

	while (!stk.empty())
	{
		que.push(stk.top().c_oper);
		stk.pop();
	}

	cout << "========== ����ǥ��� ��ȯ�� ==========\n";

	cout << "����ǥ��� : ";
	queue<string> tmpque = que;

	int size = tmpque.size();
	for (int i = 0; i < size; ++i)
	{
		cout << tmpque.front() << " ";
		tmpque.pop();

	}
	cout << "\n";

	//����ǥ����� ����ǥ������� �ٲ��.
	//����ǥ����� �������.
	calc();

	cout << "�� : " << numstk.top();
	return 0;
}
