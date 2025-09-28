#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

unordered_map<char, int> priority = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
stack<int> numbers;
stack<char> operations;

/*
 * 根据 numbers最后两个数和operations的栈顶进行运算，将运算结果放回numbers
 */
void eval()
{
	auto number2 = numbers.top();
	numbers.pop();
	auto number1 = numbers.top();
	numbers.pop();

	auto operation = operations.top();
	operations.pop();

	int result{};
	switch (operation)
	{
	case '+':
	{
		result = number1 + number2;
		break;
	}
	case '-':
	{
		result = number1 - number2;
		break;
	}
	case '*':
	{
		result = number1 * number2;
		break;
	}
	case '/':
	{
		result = number1 / number2;
		break;
	}
	}

	numbers.push(result);
}

int main()
{
	string expression;
	cin >> expression;

	for (auto index = 0; index < expression.size(); index++)
	{
		// 读入数字
		if (isdigit(expression[index]))
		{
			int number = 0;
			int digit_index = index;
			while (digit_index < expression.size() && isdigit(expression[digit_index]))
			{
				number = number * 10 + expression[digit_index] - '0';
				digit_index++;
			}
			index = digit_index - 1;
			numbers.push(number);
			continue;
		}

		// 判断运算符
		char operation = expression[index];
		switch (operation)
		{
		case '(':
		{
			operations.push(operation);
			break;
		}
		case ')':
		{
			while (operations.top() != '(')
			{
				eval();
			}
			operations.pop();
			break;
		}
		default:
		{
			// 当前运算符有限度小于前面的运算符说明前面的运算符应该要被计算了
			while (operations.size() && priority[operation] <= priority[operations.top()])
			{
				eval();
			}
			operations.push(operation);
			break;
		}
		}
	}

	// 计算未计算的运算符
	while (operations.size())
	{
		eval();
	}

	cout << numbers.top() << endl;

	return 0;
}