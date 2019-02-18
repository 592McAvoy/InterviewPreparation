#include"problem.h"

int longestValidParentheses0(string s) {
	int n = s.size();
	int** M = new int*[n];
	int len = 0;
	for (int i = 0; i < n; i++) {
		M[i] = new int[n];
		M[i][i] = 0;
		if (i < n - 1) {
			if (s[i] == '(' && s[i + 1] == ')') {
				M[i][i + 1] = 1;
				len = 2;
			}
		}
	}
	for (int i = n - 3; i >= 0; i--) {
		for (int j = i + 2; j < n; j++) {
			int t = j - i + 1;
			if (t % 2 == 1)
				M[i][j] = 0;
			else {
				if (s[i] == '(' && s[j] == ')') {
					M[i][j] = M[i + 1][j - 1];
					if (M[i][j])
						len = t > len ? t : len;
				}
				else
					M[i][j] = 0;
			}				
		}
	}
	for (int i = n - 4; i >= 0; i--) {
		for (int j = i + 3; j < n; j++) {
			if (M[i][j])continue;
			for (int k = i + 1; k < j - 1; k++) {
				if (M[i][k] && M[k + 1][j]) {
					M[i][j] = 1;
					int t = j - i + 1;
					len = t > len ? t : len;
				}
			}

		}
	}
		
	return len;	
}
int longestValidParentheses1(string s) {
	int len = s.size();
	if (len < 2)return 0;
	int* dp = new int[len];
	dp[0] = 0;
	dp[1] = s[0] == '('&&s[1] == ')' ? 2 : 0;
	int max = dp[1];
	for (int i = 2; i < len; i++) {
		if (s[i - 1] == '('&&s[i] == ')') {
			dp[i] = dp[i - 2] + 2;
			max = dp[i] > max ? dp[i] : max;
		}
		else if (s[i - 1] == ')'&&s[i] == ')') {
			int idx = i - dp[i - 1] - 1;
			if (idx >= 0 && s[idx] == '(') {
				if (idx == 0)
					dp[i] = dp[i - 1] + 2;
				else
					dp[i] = dp[i - 1] + dp[idx - 1] + 2;
				max = dp[i] > max ? dp[i] : max;
			}
			else
				dp[i] = 0;
		}
		else
			dp[i] = 0;
	}
	return max;
}
int longestValidParentheses2(string s) {
	int len = s.size();
	if (len < 2)return 0;
	stack<int> S;
	S.push(-1);
	int max = 0;
	for (int i = 0; i < len; i++) {
		if (s[i] == '(')
			S.push(i);
		else {
			S.pop();
			if (!S.empty()) {
				int valid = i - S.top();
				max = valid > max ? valid : max;
			}
			else
				S.push(i);
		}

	}
	return max;
}
int longestValidParentheses(string s) {
	int len = s.size();
	if (len < 2)return 0;
	int left = 0;
	int right = 0;
	int max = 0;
	for (int i = 0; i < len; i++) {
		if (s[i] == '(')left++;
		else {
			if (left == 0)continue;
			else {
				right++;
				if (left == right)max = left > max ? left : max;
				else if (right > left) {
					right = 0;
					left = 0;
				}
			}
		}
	}
	left = 0;
	right = 0;
	for (int i = len - 1; i >= 0; i--) {
		if (s[i] == ')')right++;
		else {
			if (right == 0)continue;
			else {
				left++;
				if (left == right)max = left > max ? left : max;
				else if (right < left) {
					right = 0;
					left = 0;
				}
			}
		}
	}
	return max;
}