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

long sumPartOfArray(long arr[], int leftIndex, int rightIndex) {
	long partialSum = 0;
	for (int i = leftIndex; i <= rightIndex; i++)  {
		partialSum += arr[i];
	}
	cout << "Sum of current chunk with left index " << leftIndex << " and right index " << rightIndex << ": " << partialSum << endl;
	return partialSum;
}

long calculateSum(long arr[], long size, int numberOfParts)
{
	long sum = 0;
	int leftIndex = 0;
	int delta = size / numberOfParts;
	if(size % numberOfParts == 0) {
		delta -=1;
	}
	for (int i = 0; i < numberOfParts - 1; i++) {
		sum += sumPartOfArray(arr, leftIndex, leftIndex + delta);
		leftIndex += (delta + 1);
	}
	sum += sumPartOfArray(arr, leftIndex, size - 1);
	return sum;
}

int main()
{
	int numberOfParts = 4;
	const int size = 10;
	long arr[size];
	createArray(arr, size);
	printArray(arr, size);
	cout << "Total sum of elements: " << calculateSum(arr, size, numberOfParts) << endl;
}