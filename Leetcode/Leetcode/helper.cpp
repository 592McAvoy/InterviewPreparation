#include "problem.h"

void swap(vector<int>& nums, int a, int b) {
	int t = nums[a];
	nums[a] = nums[b];
	nums[b] = t;
}
void sort(vector<int>& nums, int low, int high) {
	if (low >= high) return;
	int val = nums[low];
	int i = low + 1;
	int j = high;
	while (true) {
		while (i <= high && nums[i] <= val)i++;
		while (j >= low + 1 && nums[j] >= val)j--;
		if (i >= j)break;
		swap(nums, i, j);
	}
	swap(nums, low, j);
	sort(nums, low, j - 1);
	sort(nums, j + 1, high);
}