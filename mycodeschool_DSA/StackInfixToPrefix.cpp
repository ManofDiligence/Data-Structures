#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool checkOperator(char c)
{
	if (c == '+' || c == '-' || c == '*'||c=='/'||c=='^') return 1;
	else return 0;
}

bool checkOperand(char c)
{
	int n = c - 48;
	if (n >= 0 && n <= 9) return 1;
	else return 0;
}

bool isClosingParentheses(char c)
{
	if (c == ']' || c == '}' || c == ')') return 1;
	else return 0;
}

bool isOpeningParentheses(char c)
{
	if (c == '[' || c == '{' || c == '(') return 1;
	else return 0;
}
int getPrec(char c)
{
	int n=0;
	switch (c)
	{
		case '+':
		case '-':
			n = 1;
			break;
		case '/':
		case '*':
			n = 2;
			break;
		case '^':
			n = 3; break;
	}
	return n;
}
bool hasHigherPrec(char topOfStack, char c)
{
	int n = getPrec(topOfStack);
	int n2 = getPrec(c);
	if (n == n2) return 1;
	return n > n2 ? 1 : 0;
}
string InfixToPostfix(string c)
{
	string Res="";
	stack<char> S;
	for (int i = 0; i < c.length(); i++)
	{
		if (checkOperator(c[i]))
		{
			while (!S.empty() && !isOpeningParentheses(S.top()) && hasHigherPrec(S.top(), c[i]))
			{
				Res = Res+ S.top();
				S.pop();
			}
			S.push(c[i]);
		}
		else if (checkOperand(c[i]))
		{
			Res = Res+ c[i];// concat
		}
		else if (isOpeningParentheses(c[i]))
			S.push(c[i]);
		else if (isClosingParentheses(c[i]))
		{
			while (!S.empty() && !isOpeningParentheses(S.top()))
			{
				Res = Res+ S.top();
				S.pop();
			}
			if(!S.empty()) S.pop();
		}
	}
	while (!S.empty())
	{
		Res += S.top();
		S.pop();
	}
	return Res;
}

int main()
{
	string infix = "2^(3^2)";
	string prefix = InfixToPostfix(infix);
	cout << "Original infix is: " << infix;
	cout << "\nAfter performing Infix to Prefix: " << prefix;
	return 0;
}