#pragma once
#include <vector>
using namespace std;

void printArray(int* array, int len); 
int* copyArr(int* arr, int len);

class Sort{
public:
	virtual int* sort(int* arr, int len) = 0;
};

/*��ѡ������
 *ѡ��������е���СԪ��
 *����������ĵ�һ��Ԫ�ؽ���λ��
 *�ٴ�ʣ�µ�Ԫ����ѡ�����С��Ԫ��
 *��������ĵڶ���Ԫ�ؽ���λ��
 *���Ͻ��������Ĳ�����ֱ����������������
 */
class SelectSort : public Sort {
public:
	int* sort(int *arr, int len);
};

/*��ð������
 *�����Ҳ��Ͻ������������Ԫ�أ���һ�ֵ�ѭ��֮�󣬿�����δ��������Ԫ���ϸ����Ҳ�
 *��һ��ѭ���У����û�з�����������˵�������Ѿ�������ģ���ʱ����ֱ���˳�
 */
class BubbleSort : public Sort {
public:
	int* sort(int *arr, int len);
};

/*����������
 *ÿ�ζ�����ǰԪ�ز��뵽����Ѿ������������
 *ʹ�ò���֮�����������Ȼ����
 */
class InsertSort : public Sort {
public:
	int* sort(int *arr, int len);
};

/*��ϣ������
 *ʹ�ò�������Լ�� h �����н�������
 *ͨ�����ϼ�С h
 *����� h=1�Ϳ���ʹ�����������������*/
class ShellSort : public Sort {
public:
	int* sort(int *arr, int len);
};

/*���鲢����
 * ������ֳ�������
 * �ֱ��������
 * Ȼ��鲢����
 */
class MergeSort : public Sort {
public:
	int* sort(int *arr, int len);
private:
	void Sort(int* arr, int low, int high);
	void Merge(int* arr, int low, int mid, int high);
};

/*����������
 *��������ͨ��һ���з�Ԫ�ؽ������Ϊ����������
 *��������С�ڵ����з�Ԫ��
 *����������ڵ����з�Ԫ��
 *������������������Ҳ�ͽ���������������*/
class QuickSort : public Sort {
public:
	int* sort(int *arr, int len);
private:
	void quickSort(int* arr, int low, int high);
};

/*��������
 *����ĳ���ڵ��ֵ���Ǵ��ڵ������ӽڵ��ֵ
 *���Ҷ���һ����ȫ������
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