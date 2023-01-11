#include <iostream>
using namespace std;

void heapinsert(int *arr, int index)
{
	while (arr[index] > arr[(index - 1) / 2])
	{
		swap(arr[index], arr[(index - 1) / 2]);
		index = (index - 1) / 2;
	}
}

void heapify(int *arr, int index, int heapsize)
{
	int left = index * 2 + 1;
	while (left < heapsize)
	{
		int largest = (left + 1 < heapsize) && arr[left + 1] > arr[left] ? left + 1 : left;
		largest = arr[largest] > arr[index] ? largest : index;
		if (index == largest)
			break;
		swap(arr[index], arr[largest]);
		index = largest;
		left = index * 2 + 1;
	}
}

void heapsort(int *arr, int length)
{
	for (int i = 1; i < length; i++)
		heapinsert(arr, i);
	int heapsize = length;
	swap(arr[--heapsize], arr[0]);
	while (heapsize > 0)
	{
		heapify(arr, 0, heapsize);
		swap(arr[0], arr[--heapsize]);
	}
}

int main()
{
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	heapsort(arr, n);
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}