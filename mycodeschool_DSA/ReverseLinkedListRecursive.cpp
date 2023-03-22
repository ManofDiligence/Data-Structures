#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* head;

void Reverse(Node* p1)
{
	if (p1->next == NULL)
	{
		head = p1;
		return;
	}
	Reverse(p1->next);
	Node* p2;
	p2 = p1->next;
	p2->next = p1;
	p1->next = NULL;
}