#pragma once
#include <vector>
using namespace std;

void printArray(int* array, int len); 
int* copyArr(int* arr, int len);

class Sort{
public:
	virtual int* sort(int* arr, int len) = 0;
};

/*【选择排序】
 *选择出数组中的最小元素
 *将它与数组的第一个元素交换位置
 *再从剩下的元素中选择出最小的元素
 *它与数组的第二个元素交换位置
 *不断进行这样的操作，直到将整个数组排序
 */
class SelectSort : public Sort {
public:
	int* sort(int *arr, int len);
};

/*【冒泡排序】
 *从左到右不断交换相邻逆序的元素，在一轮的循环之后，可以让未排序的最大元素上浮到右侧
 *在一轮循环中，如果没有发生交换，就说明数组已经是有序的，此时可以直接退出
 */
class BubbleSort : public Sort {
public:
	int* sort(int *arr, int len);
};

/*【插入排序】
 *每次都将当前元素插入到左侧已经排序的数组中
 *使得插入之后左侧数组依然有序
 */
class InsertSort : public Sort {
public:
	int* sort(int *arr, int len);
};

/*【希尔排序】
 *使用插入排序对间隔 h 的序列进行排序
 *通过不断减小 h
 *最后令 h=1就可以使得整个数组是有序的*/
class ShellSort : public Sort {
public:
	int* sort(int *arr, int len);
};

/*【归并排序】
 * 将数组分成两部分
 * 分别进行排序
 * 然后归并起来
 */
class MergeSort : public Sort {
public:
	int* sort(int *arr, int len);
private:
	void Sort(int* arr, int low, int high);
	void Merge(int* arr, int low, int mid, int high);
};

/*【快速排序】
 *快速排序通过一个切分元素将数组分为两个子数组
 *左子数组小于等于切分元素
 *右子数组大于等于切分元素
 *将这两个子数组排序也就将整个数组排序了*/
class QuickSort : public Sort {
public:
	int* sort(int *arr, int len);
private:
	void quickSort(int* arr, int low, int high);
};

/*【堆排序】
 *堆中某个节点的值总是大于等于其子节点的值
 *并且堆是一颗完全二叉树
 */
class HeapSort : public Sort {
public:
	int* sort(int *arr, int len);
private:
	void sink(int* arr, int idx, int len);
	void swim(int* arr, int idx, int len);
	void makeheap(int* arr, int len);
	void heapSort(int* arr, int len);
};