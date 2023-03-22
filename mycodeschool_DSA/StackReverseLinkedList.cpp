#include <iostream>
#include <stack>
using namespace std;

struct Node
{
	int data;
	Node* next;
};
Node* head;
stack<struct Node*> S;
void Reverse()
{
	if (head == NULL) return;
	Node* temp = head;
	while (temp != NULL)
	{
		S.push(temp);
		temp = temp->next;
	}
	temp = S.top();
	head = temp;
	S.pop();
	while (!S.empty())
	{
		
		temp->next = S.top();
		S.pop();
		temp = temp->next;
	}
	temp->next = NULL;
}
void Insert(int x)
{
	Node* temp = new Node();
	temp->data = x;
	temp->next = NULL;
	if (head == NULL)
	{
		head = temp;
		return;
	}
	Node* temp1=head;
	while (temp1->next != NULL) temp1 = temp1->next;
	temp1->next = temp;
	
}
void Print()
{
	Node* p = head;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << "\n";
}
int main()
{
	head = NULL;
	Insert(5);
	Insert(9);
	Insert(-2);
	Print();
	Reverse();
	Print();
}