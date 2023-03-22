// Linked List implementation of stack
#include <iostream>
using namespace std;


class Stack {
private:
	struct Node {
		int data;
		Node* link;
	};
	Node* top;
public:
	Stack()
	{
		top = NULL; // stack is initially empty 
	}
	void push(int x)
	{
		Node* newNode = new Node();
		newNode->data = x;
		newNode->link = NULL;
		if (top == NULL)
		{
			top = newNode;
			return;
		}
		newNode->link = top;
		top = newNode;
	}
	void pop()
	{
		Node* temp = top;
		if (top == NULL)
		{
			return;
		}
		top = temp->link;
		delete(temp);
	}
	void Print()
	{
		Node* temp = top;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->link;
		}
		cout << "\n";
	}
	int Top()
	{
		Node* temp = top;
		return temp->data;
	}

	bool isEmpty()
	{
		if (top == NULL) return 1;
		else return 0;
	}
};




int main()
{
	Stack S;
	S.push(3);
	S.push(3);
	S.push(9);
	S.Print();
	S.pop();
	S.Print();
}