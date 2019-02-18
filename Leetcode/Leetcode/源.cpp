#include<string>
#include<iostream>
#include<vector>
#include "problem.h"

using namespace std;

int main() {
	vector<int> vec = {1,3,4,56,70};
	int idx = binarySearch(vec, 0, 4, 70);
	cout << idx<<endl;
	cin.get();
}