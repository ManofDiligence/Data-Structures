#include <iostream>
using namespace std;

class Queue {
private:
	struct Node {
		int data;
		Node* next;
	};
	Node* front;
	Node* rear;
public:
	Queue() {
		front = rear = NULL;
	}
	void Enqueue(int x)
	{
		Node* temp = new Node();
		temp->data = x;
		temp->next = NULL;
		if (front == NULL && rear == NULL)// when Queue is empty
		{
			front = rear = temp;
			return;
		}
		rear->next = temp;
		rear = temp;
	}
	void Dequeue()
	{
		Node* temp = front;
		if (front == NULL) return;
		if (front == rear) front = rear = NULL;
		else front = front->next;
		delete(temp);
	}
	void print()
	{
		Node* temp = front;
		while (temp != NULL)
		{
			cout << temp->data<<' ';
			temp = temp->next;
		}
		cout << "\n";
	}
};

int main()
{
	Queue Q;
	Q.Enqueue(5);
	Q.Enqueue(6);
	Q.Enqueue(7);
	Q.print();
	Q.Dequeue();
	Q.print();
}