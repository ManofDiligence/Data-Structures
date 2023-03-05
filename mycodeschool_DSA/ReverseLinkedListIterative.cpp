#include <iostream>
using namespace std;
struct Node {
	int data;
	Node* next;
 };

Node* head;

void Reverse()
{
	Node* current = head, *prev=NULL, *next;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
}

void Insert(int d)
{

	Node* temp1 = new Node();
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
}

void print()
{
	Node* temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << "\n";
}

int main()
{
	Insert(4);
	Insert(5);
	Insert(8);
	Insert(0);
	print();
	Reverse();
	print();
	return 0;
}