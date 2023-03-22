#include <iostream>
using namespace std;
#define MAX_SIZE 101


// circular array method

class Queue {
private:
	int front, rear;
	int A[MAX_SIZE];
public: 
	Queue()
	{
		front = rear = -1;
	}
	bool isEmpty()
	{
		return front == -1 && rear == -1;
	}
	bool isFull()
	{
		return (rear+1)%MAX_SIZE == front;
	}
	void Enqueue(int x)
	{
		if ((rear + 1) % MAX_SIZE == front) return;	// when there is no unused cell in the circular array 
		else if (isEmpty()) front = rear = 0;
		else rear = (rear + 1) % MAX_SIZE;
		A[rear] = x;
	}

	void Dequeue()
	{
		if (isEmpty()) return;
		else if (front == rear) front = rear = -1;
		else front = (front + 1) % MAX_SIZE;
	}

	int Front()
	{
		return A[front];
	}
	void print() {
		int count = (rear + MAX_SIZE - front) % MAX_SIZE + 1;
		cout << "Queue: ";
		for (int i = 0; i < count; i++)
		{
			int index = (front + i) % MAX_SIZE;
			cout << A[index] << " ";

		}
		cout << "\n\n";
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