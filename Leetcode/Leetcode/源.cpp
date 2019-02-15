#include<string>
#include<iostream>
#include<vector>
#include "problem.h"

using namespace std;

int main() {
	vector<int> vec = {1,1,1 };
	sort(vec, 0, vec.size() - 1);
	for (int n : vec) {
		cout << n << " ";
	}
	cout << endl;
	cin.get();
}