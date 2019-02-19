#include "problem.h"

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

void findCombination(vector<int>& candidates, int target, vector<int>& combination, vector<vector<int>>& ret, int idx) {
	if (target < candidates[idx])return;
	int size = candidates.size();
	for (int i = idx; i < size; i++) {
		int num = candidates[i];
		if (target == num) {
			combination.push_back(num);
			ret.push_back(combination);
		}
		else if (target > num) {
			vector<int> tmp = combination;
			tmp.push_back(num);
			findCombination(candidates, target - num, tmp, ret, i);
		}
		else
			break;
	}
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	int size = candidates.size();
	vector<vector<int>> init;
	vector<int> combination;
	if (size == 0)return init;
	sort(candidates, 0, size - 1);
	findCombination(candidates, target, combination, init, 0);

	return init;
}

void findCombination2(vector<int>& candidates, int target, vector<int>& combination, vector<vector<int>>& ret, int idx) {
	int size = candidates.size();
	if (idx < size && target < candidates[idx])return;	
	for (int i = idx; i < size; i++) {
		int num = candidates[i];
		if (i > idx && num == candidates[i - 1])continue;
		if (target == num) {
			combination.push_back(num);
			ret.push_back(combination);
		}
		else if (target > num) {
			vector<int> tmp = combination;
			tmp.push_back(num);
			findCombination2(candidates, target - num, tmp, ret, i + 1);
		}
		else
			break;
	}
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	int size = candidates.size();
	vector<vector<int>> init;
	vector<int> combination;
	if (size == 0)return init;
	sort(candidates, 0, size - 1);
	findCombination2(candidates, target, combination, init, 0);

	return init;
}