#include"problem.h"

void nextPermutation(vector<int>& nums) {
	int size = nums.size();
	if (size < 2) return;
	if (size == 2) {
		if (nums[0] < nums[1])swap(nums, 0, 1);
		return;
	}
	for (int step = 1; step <= size - 1; step++) {
		for (int i = size - 1; i >= step; i--) {
			int j = i - step;
			if (nums[i] > nums[j]) {
				int min = nums[i];
				int idx = i;
				for (int k = j + 2; k < size; k++) {
					int tmp = nums[k];
					if (tmp > nums[j] && tmp < min) {
						min = tmp;
						idx = k;
					}
				}
				swap(nums, idx, j);
				sort(nums, j + 1, size - 1);
				return;
			}
		}
	}

	sort(nums, 0, size - 1);
}