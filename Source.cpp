#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
using namespace std;

void randArray(int *arr, int len) {
	srand(time(NULL));
	for (int i = 0; i < len; i++)
		arr[i] = rand() % 100;
}

int main() {
	int len = 20;
	int* arr = new int[len];
	randArray(arr, len);

	cout << "Initial:\t";
	printArray(arr, len);

	int* arr1 = SelectSort().sort(copyArr(arr, len), len);
	cout << "SelectSort:\t";
	printArray(arr1, len);

	int* arr2 = BubbleSort().sort(copyArr(arr, len), len);
	cout << "BubbleSort:\t";
	printArray(arr2, len);

	int* arr3 = InsertSort().sort(copyArr(arr, len), len);
	cout << "InsertSort:\t";
	printArray(arr3, len);

	int* arr4 = ShellSort().sort(copyArr(arr, len), len);
	cout << "ShellSort:\t";
	printArray(arr4, len);

	int* arr5 = MergeSort().sort(copyArr(arr, len), len);
	cout << "MergeSort:\t";
	printArray(arr5, len);

	int* arr6 = QuickSort().sort(copyArr(arr, len), len);
	cout << "QuickSort:\t";
	printArray(arr6, len);

	int* arr7 = HeapSort().sort(copyArr(arr, len), len);
	cout << "HeapSort:\t";
	printArray(arr7, len);

	cin.get();
}

