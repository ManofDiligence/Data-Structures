// Array implementation of stack
#include <iostream>
using namespace std;
#define MAX_SIZE 101

class Stack {
private:
	int top, A[MAX_SIZE];
public:
	Stack()
	{
		top = -1;
	}
	void push(int x)
	{
		A[++top] = x;
	}

	void pop()
	{
		top--;
	}

	int Top()
	{
		return A[top];
	}

	bool isEmpty()
	{
		if (top == -1) return 1;
		else return 0;
	}
	void Print()
	{
		cout << "Stack: ";
		for (int i = top; i >= 0; i--)
		{
			cout << A[i] << " ";
		}
		cout << "\n";
	}
};

int main()
{
	Stack S;
	S.push(9);
	S.push(12);
	S.push(3);
	S.Print();
	S.pop();
	S.Print();
}