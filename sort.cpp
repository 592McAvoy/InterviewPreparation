#include "sort.h"
#include <iostream>


void Swap(int* arr, int i, int j) {
	//cout << i << " " << j << endl;
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void printArray(int* array, int len) {
	int cnt = 0;
	while (cnt<len) {
		cout << array[cnt] << " ";
		cnt++;
	}
	cout << endl;
}
int* copyArr(int* arr, int len) {
	int* result = new int[len];
	for (int i = 0; i < len; i++) {
		result[i] = arr[i];
	}
	return result;
}


int* 
SelectSort::sort(int *arr, int len){	
	for (int i = 0; i < len; i++) {
		int min = arr[i];
		for (int j = i + 1; j < len; j++) {
			if (arr[j] < min) {
				min = arr[j];
				Swap(arr, i, j);
			}
		}
	}
	return arr;
}

int*
BubbleSort::sort(int *arr, int len) {
	bool done = false;
	while (!done) {
		done = true;
		for (int i = 0; i < len - 1; i++) {
			int j = i + 1;
			if (arr[i] > arr[j]) {
				done = false;
				Swap(arr, i, j);
			}
		}
	}
	return arr;
}

int*
InsertSort::sort(int *arr, int len) {
	for (int i = 0; i < len-1; i++) {
		for (int j = i + 1; j > 0; j--) {
			if (arr[j] < arr[j - 1]) {
				Swap(arr, j, j - 1);
			}
			else
				break;
		}
	}

	return arr;
}


int*
ShellSort::sort(int *arr, int len) {
	int h = 1;

	while (h < len / 3) {
		h = 3 * h + 1; // 1, 4, 13, 40, ...
	}

	while (h >= 1) {
		for (int i = 0; i < h; i++) {
			for (int j = i + h; j < len; j += h) {
				while (j >= h && arr[j] < arr[j - h]) {
					Swap(arr, j, j - h);
					j -= h;
				}
			}
			h /= 3;
		}
	}
	return arr;
}

int*
MergeSort::sort(int *arr, int len) {
	Sort(arr, 0, len - 1);
	return arr;
}

void
MergeSort::Sort(int* arr, int low, int high) {
	if (low >= high) {		
		return;
	}
	int mid = low + (high - low) / 2;
	Sort(arr, low, mid);
	Sort(arr, mid + 1, high);
	Merge(arr, low, mid, high);
}

void
MergeSort::Merge(int* arr, int low, int mid, int high){
	int len1 = mid - low + 1;
	int len2 = high - mid;
	
	int* t1 = new int[len1];
	int* t2 = new int[len2];
	for (int i = 0; i < len1; i++) {
		t1[i] = arr[i+low];
	}
	for (int i = 0; i < len2; i++) {
		t2[i] = arr[i+mid+1];
	}

	int p1 = 0;
	int p2 = 0;
	while (p1 < len1 && p2 < len2) {
		if (t1[p1] > t2[p2]) {
			arr[low + p1 + p2] = t2[p2];
			p2 += 1;
		}
		else {
			arr[low + p1 + p2] = t1[p1];
			p1 += 1;
		}
	}
	for (int i = p1; i < len1; i++) {
		arr[low + p1 + p2] = t1[p1];
		p1++;
	}
	for (int i = p2; i < len2; i++) {
		arr[low + p1 + p2] = t2[p2];
		p2++;
	}
	delete t1;
	delete t2;	
}


int*
QuickSort::sort(int *arr, int len) {
	quickSort(arr, 0, len - 1);
	return arr;
}

void 
QuickSort::quickSort(int* arr, int low, int high) {
	if (low >= high)return;
	int mid = low + (high - low) / 2;
	int val = arr[low];
	int i = low;
	int j = high;
	while (i < j) {
		while (arr[i] <= val&&i != high)i++;
		while (arr[j] >= val&&j != low)j--;
		if (i < j)
			Swap(arr, i, j);
	}
	Swap(arr, low,j);
	quickSort(arr, low, j-1);
	quickSort(arr, j + 1, high);
}

int*
HeapSort::sort(int *arr, int len) {
	makeheap(arr, len);
	heapSort(arr, len);
	return arr;
}
void
HeapSort::sink(int* arr, int idx, int len) {
	while (2 * idx+1 < len) {
		int c = 2 * idx+1;
		if (c < len-1 && arr[c] < arr[c + 1]) {
			c += 1;
		}
		if (arr[idx] < arr[c]) {
			Swap(arr, idx, c);
			idx = c;
		}
		else break;
	}
}
void
HeapSort::swim(int* arr, int idx, int len) {
	while (idx >=1) {
		int f = (idx - 1) / 2;
		if (arr[idx] > arr[f]) {
			Swap(arr, idx, f);
			idx = f;
		}
		else break;
	}
}
void
HeapSort::makeheap(int* arr, int len) {
	for (int i = 0; i < len; i++) {
		swim(arr, i, len);
	}
}
void
HeapSort::heapSort(int* arr, int len) {
	for (int i = len - 1; i >= 0; i--) {
		//cout << "iter " << len-i << ":\t";
		//printArray(arr, len);
		Swap(arr, 0, i);
		sink(arr, 0, i);
		
	}
}