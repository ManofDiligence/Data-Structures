#include <iostream>
using namespace std;

void BubbleSort(int* A, int n)
{
	for (int i = 1; i < n - 1; i++)
	{
		int flag = 0;
		for (int j = 0; j < n-i; j++)
		{
			if (A[j] > A[j + 1])
			{
				int temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
				flag = 1;
			}
		}
		if (!flag) break;
	}
}

int main()
{
	int A[] = { 2,7,4,1,3,6,5 };
	int n = sizeof(A) / sizeof(int);
	BubbleSort(A, n);
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
}