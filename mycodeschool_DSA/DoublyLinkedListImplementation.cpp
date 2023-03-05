// implementation of doubly linked list
#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* prev;// address of previous node
	Node* next;// address of next node
};
Node* head;// pointer to head node
struct Node* getNewNode(int x)
{
	Node* newNode = new Node();// reserve a memory in heap, claim a address 
	newNode->next = NULL;
	newNode->data = x;
	newNode->prev = NULL;
	return newNode;

};
void InsertAtHead(int x)
{
	Node* newNode = getNewNode(x);
	if (head == NULL)
	{
		head = newNode;
		return;
	}
	head->prev = newNode;
	newNode->next = head;
	head = newNode; 
}
void InsertAtTail(int x)
{
	Node* newNode = getNewNode(x);
	if (head == NULL)
	{
		head = newNode;
		return;
	}
	Node* p=head;
	while (p->next != NULL) p = p->next; // go to the last node
	p->next = newNode;
	newNode->prev = p;
	newNode->next = NULL;
}
void ReversePrint()
{
	Node* p = head;
	if (p == NULL) return;
	while (p->next != NULL)// get the last node
	{
		p = p->next;
	}
	cout << "Reverse: ";
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->prev;
	}
	cout << "\n";
}
void Print()
{
	Node* temp = head;
	cout << "Forward: ";
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << "\n";
}
int main()
{
	 head = NULL;
	 InsertAtHead(2); Print(); ReversePrint();
	 InsertAtHead(6); Print(); ReversePrint();
	 InsertAtHead(4); Print(); ReversePrint();
	 cout << "............";
	 InsertAtTail(3);
	 InsertAtTail(6);
	 InsertAtTail(9);
	 Print();
}