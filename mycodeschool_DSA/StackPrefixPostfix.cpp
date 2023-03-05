#include <iostream>
#include <stack>
using namespace std;
bool checkOperator(char c)
{
	if (c == '+' || c == '-' || c == '*') return 1;
	else return 0;
}

bool checkOperand(char c)
{
	int n = c - 48;
	if (n >= 0 && n <= 9) return 1;
	else return 0;
}

int perform(char c, int n1, int n2)
{
	if (c == '+') return n1 + n2;
	else if (c == '*') return n1 * n2;
	else if (c == '-') return abs(n1 - n2);
}
int EvaluatePostfix(char* c)
{
	stack<int> S;
	for (int i = 0; i < strlen(c); i++)
	{
		if (checkOperand(c[i])) { int n = c[i] - 48; S.push(n); }
		else if (checkOperator(c[i]))
		{
			int n, n1;
			n = S.top();
			S.pop();
			n1 = S.top();
			S.pop();
			S.push(perform(c[i], n, n1));
		}
	}
	return S.top();
}

int main()
{
	char c[] = "23*54*+9-";
	int n = EvaluatePostfix(c);

	cout << "The Postfix is " << c;
	cout << "\nThe Evaluation is " << n;

	return 0;
}