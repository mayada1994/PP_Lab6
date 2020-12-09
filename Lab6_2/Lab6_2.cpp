#include <iostream>
using namespace std;

void createArray(long arr[], long size)
{
	for (long i = 0; i < size; i++)
	{
		arr[i] = i + 1;
	}
}

void printArray(long arr[], long size)
{
	cout << "[";
	for (long i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "]" << endl;
}

long sumPair(long arr[], int leftIndex, int rightIndex) {
	long partialSum = arr[leftIndex] + arr[rightIndex];
	cout << "Sum of elements with indices " << leftIndex << " and " << rightIndex << ": " << partialSum << endl;
	return partialSum;
}

void waveSum(long arr[], int size)
{
	int currentElement = size - 1;
	int currentSize = size;
	while (currentSize > 1)
	{
		for (int i = 0; i < currentSize / 2; i++)
		{
			arr[i] = sumPair(arr, i, currentElement);
			cout << "Array after change: ";
			printArray(arr, currentSize);
			cout << endl;
			currentElement--;
		}
		currentSize = currentSize / 2 + currentSize % 2;
	}
}

int main()
{
	const int size = 11;
	long arr[size];
	createArray(arr, size);
	printArray(arr, size);
	waveSum(arr, size);
	cout << "Total sum of elements: " << arr[0] << endl;
}