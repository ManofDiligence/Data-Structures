#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* head;

void Delete(int n)
{
	Node* temp1 = head;

	if (n == 1)
	{
		head = temp1->next;
		delete(temp1);
		return;
	}
	for (int i = 0; i < n - 2; i++)
		temp1 = temp1->next;// n-1 node

	Node* temp2 = temp1->next;// n node
	temp1->next = temp2->next;// n to n + 1 node
	delete(temp2);
}
void Insert(int d)
{
	Node* temp1= new Node();
	temp1->data = d;
	temp1->next = NULL;
	Node* temp2 = head;
	if (head == NULL)
	{
		head = temp1;
		return;
	}
	else {
		while (temp2->next != NULL)
		{
			temp2 = temp2->next;
		}
	}
	temp2->next = temp1;
	// insert at beginning
	/*
	temp1->data = data;
	temp1->next = head;
	head = temp1;
	*/
	
}
void print()
{
	Node* temp1 = head;
	while (temp1 != NULL)
	{
		cout << temp1->data<<" ";
		temp1 = temp1->next;
	}
	cout << "\n";
}
int main()
{
	Insert(4);
	Insert(3);
	Insert(5);
	Insert(6);
	print(); // 4 3 5 6
	Delete(2);
	print(); // 4 5 6
	Insert(7);
	print(); // 4 5 6 7
}