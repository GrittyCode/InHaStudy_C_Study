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
		while (!stk.empty() && stk.top().p >= idx) //자신의 우선순위보다 같거나 높을 경우에는 계산을 해준다.
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
		if (que.front() != "+" && que.front() != "-" && que.front() != "*" && que.front() != "/") //연산자가 아닐 경우에만
		{
			numstk.push(std::stod(que.front()));
			que.pop();
		}
		else //연산자의 경우
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
	//문자열을 받아주고 이를 연산자, 숫자를 구분지어준다.
	//연산자의 경우 우선순위를 지정해줘야한다.
	//() < +,- < *,/가 있는데 ( 의 경우 그냥 스택에 더해주고 )를 만난경우 왼쪽 괄호를 만날때까지 계산을 진행해준다.
	//또한, 스택의 가장 위쪽에 있는 연산자의가 우선순위가 더 높은 경우 바로 큐에 대입해준다. 우선순위가 더 낮거나 같아질때까지 또한, 스택이 빌때까지 반복한다.
	//이후에, 자신의 연산을 스택에 넣어준다.

	//먼저, 큐에 후위 표기법으로 바꿔준다.

	cout << "중위표기법 : " << input << "\n";

	bool isNumber = false;
	string tmp;

	for (int i = 0; i < input.size(); ++i)
	{
		if (((input[i] == '-' && !isNumber))) //실수와 음수를 위한 구분 (연산자 다음으로 오는 -는 음수를 체크해주는 것)
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
			que.push(tmp); //숫자는 그냥 더해준다.
			isNumber = true;
			tmp.clear();
		}
		else
		{
			if (input[i] != '(' && input[i] != ')') isNumber = false; //연산자
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

	cout << "========== 후위표기법 변환중 ==========\n";

	cout << "후위표기법 : ";
	queue<string> tmpque = que;

	int size = tmpque.size();
	for (int i = 0; i < size; ++i)
	{
		cout << tmpque.front() << " ";
		tmpque.pop();

	}
	cout << "\n";

	//중위표기법을 후위표기법으로 바꿨다.
	//후위표기법을 계산하자.
	calc();

	cout << "값 : " << numstk.top();
	return 0;
}
