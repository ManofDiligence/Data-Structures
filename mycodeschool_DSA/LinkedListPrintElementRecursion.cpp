#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};
Node* head;
void Print(Node* p1)
{
	// base case (Exit condition)
 	if (p1 != NULL)
	{
		cout << p1->data << " "; // print the value part of the node 
		Print(p1->next); // pass to next node to be print (recursive call)
	}
	else return;
}

void Insert(int d)
{
	Node* temp1 = new Node();
	temp1->data = d;
	temp1->next = NULL;
	if (head == NULL)
	{
		head = temp1;
		return;
	}
	else {
		Node* temp2 = head;
		while (temp2->next != NULL)
		{
			temp2 = temp2->next;
		}
		temp2->next = temp1;
	}
}

void ReversePrint(Node* p2)
{
	if (p2 == NULL) return;
	else {
		ReversePrint(p2->next);
		cout << p2->data << " ";
	}
}

int main()
{
	head = NULL;
	Insert(3);
	Insert(6);
	Insert(9);
	Print(head);
	cout << "\n";
	ReversePrint(head);
}