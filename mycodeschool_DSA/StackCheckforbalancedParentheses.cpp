#include <iostream>
#include <stack>
using namespace std;

bool checkPairness(char c, char top)
{
	bool isPair = false;
	if (top == '(' && c == ')') isPair = !isPair;
	else if (top == '[' && c == ']') isPair = !isPair;
	else if (top == '{' && c == '}') isPair = !isPair;
	return isPair;
}
bool checkBalancedParenthesis(char* C)
{
	stack<char> S;
	int n = strlen(C);
	for (int i = 0; i < n; i++)
	{
		if (C[i] == '(' || C[i] == '[' || C[i] == '{') S.push(C[i]);
		if (C[i] == ')' || C[i] == ']' || C[i] == '}')
		{
			if (S.empty() || !(checkPairness(C[i], S.top()))) return 0;
			else S.pop();
		}

	}

	return S.empty();
}

int main()
{
	char C[101];
	cin >> C;
	if (checkBalancedParenthesis(C)) cout << "Balanced";
	else cout << "Not Balanced";

	return 0;

}