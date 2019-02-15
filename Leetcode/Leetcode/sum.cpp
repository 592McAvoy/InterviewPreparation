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

vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> indices;
	map<int, int> record;
	int len = nums.size();
	for (int i = 0; i < len; i++) {
		int left = target - nums[i];
		if (record.count(left) > 0) {
			indices.push_back(record[left]);
			indices.push_back(i);
			break;
		}
		record[nums[i]] = i;
	}
	return indices;
}
vector<vector<int>> threeSum(vector<int>& nums) {
	int size = nums.size();
	sort(nums, 0, size - 1);
	vector<vector<int>> ret;
	set<int> s;
	for (int i = 0; i < size; i++) {
		int num = nums[i];
		if (s.count(num) > 0) continue;
		s.insert(num);
		int p = i + 1;
		int q = size - 1;
		while (p < q) {
			int low = nums[p];
			int high = nums[q];
			int sum = low + high;
			if (sum == -num) {
				vector<int> v = { num,low,high };
				ret.push_back(v);
				while (q >= i + 1 && nums[q] == high)q--;
				while (p <= size - 1 && nums[p] == low)p++;
			}
			else if (sum > -num) {
				while (q >= i + 1 && nums[q] == high)q--;
			}
			else {
				while (p <= size - 1 && nums[p] == low)p++;
			}
		}
	}
	return ret;
}

int threeSumClosest0(vector<int>& nums, int target) {
	int size = nums.size();
	if (!size) return 0;

	int min = INT_MAX;
	int sum = 0;
	for (int i = 0; i < size; i++) {
		int a = nums[i];
		for (int j = i + 1; j < size; j++) {
			int b = nums[j];
			for (int k = j + 1; k < size; k++) {
				int c = nums[k];
				int s = a + b + c;
				int diff = abs(target - s);
				if (diff < min) {
					min = diff;
					sum = s;
				}
			}
		}
	}
	return sum;
}

int threeSumClosest(vector<int>& nums, int target) {
	int size = nums.size();
	if (!size) return 0;

	sort(nums, 0, size - 1);

	int sum = nums[0];
	int min = INT_MAX;
	
	for (int i = 0; i < size; i++) {
		int num = nums[i];
		
		int p = i + 1;
		int q = size - 1;
		while (p < q) {
			int low = nums[p];
			int high = nums[q];
			int s = low + high;
			int diff = s - target;

			if (diff == 0)return s;
			else if (diff > 0)q--;
			else p++;

			if (abs(diff) < min) {
				min = abs(diff);
				sum = s;
			}
		}
	}

	return sum;	
}

vector<vector<int>> fourSum(vector<int>& nums, int target) {
	int size = nums.size();
	vector<vector<int>> ret;
	if (size < 4) return ret;

	sort(nums, 0, size - 1);

	set<int> s;
	for (int i = 0; i < size; i++) {
		int a = nums[i];
		if (s.count(a) > 0)continue;
		s.insert(a);
		int j = i + 1;
		while (j < size) {
			int b = nums[j];
			int p = j + 1;
			int q = size - 1;
			while (p < q) {
				int low = nums[p];
				int high = nums[q];
				int sum = a + b + low + high;
				if (sum == target) {
					vector<int> v = { a,b,low,high };
					ret.push_back(v);
					while (p < size && low == nums[p])p++;
					while (q > j && high == nums[q])q--;
				}
				else if (sum > target) {
					while (q > j && high == nums[q])q--;
				}
				else {
					while (p < size && low == nums[p])p++;
				}
			}
			while (j < size && b == nums[j])j++;
		}
	}
	return ret;
}
