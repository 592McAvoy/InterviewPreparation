#include"problem.h"

string longestPalindrome0(string s) {//naive
	int len = s.size();
	int max = 0;
	string str;
	for (int i = 0; i < len; i++) {
		for (int j = len - 1; j >= i; j--) {
			if (s.at(i) == s.at(j)) {
				int p = i;
				int q = j;
				while (p < q) {
					if (s.at(p) == s.at(q)) {
						p++; q--;
					}
					else break;
				}
				if (p >= q) {
					if (j - i + 1 > max) {
						max = j - i + 1;
						str = s.substr(i, max);
					}
				}
			}
		}
	}
	return str;
}

string longestPalindrome(string s) {//DP
	int n = s.size();
	int **arr = new int*[n];
	int max = 0;
	string str;

	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
		arr[i][i] = 1;
		if (max == 0) {
			max = 1;
			str = s.substr(i, max);
		}
		if (i != n - 1) {
			if (s.at(i) == s.at(i + 1)) {
				arr[i][i + 1] = 1;
				max = 2;
				str = s.substr(i, max);
			}
			else
				arr[i][i + 1] = 0;
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j > i + 1; j--) {
			if ((arr[i + 1][j - 1] == 1) && (s.at(i) == s.at(j))) {
				arr[i][j] = 1;
				if (j - i + 1 > max) {
					max = j - i + 1;
					str = s.substr(i, max);
				}
			}
		}
	}
	return str;

}

string longestPalindrome3(string s) {//ÖÐÐÄÀ©É¢
	return s;
}

