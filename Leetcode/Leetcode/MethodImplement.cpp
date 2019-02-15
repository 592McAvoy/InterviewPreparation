#include "problem.h"

int strStr(string haystack, string needle) {
	int l1 = haystack.size();
	int l2 = needle.size();
	if (!l2)return 0;
	if (!l1)return-1;
	for (int i = 0; i < l1 - l2 + 1; i++) {
		if (haystack[i] == needle[0]) {
			int j = i;
			bool match;
			for (char ch : needle) {
				if (j == l1 || ch != haystack[j]) {
					match = false;
					break;
				}
			}
			if (match)return i;
		}
	}
	return -1;
}

int divide0(int dividend, int divisor) {
	if (divisor == 1)return dividend;
	bool neg = false;
	if (dividend == INT_MIN && (divisor == 2 || divisor == -2)) {
		return 1073741824 * (divisor > 0 ? -1 : 1);
	}
	if (dividend == INT_MAX && divisor == INT_MIN) {
		return 0;
	}
	if (dividend < 0) {
		dividend = (dividend == INT_MIN) ? 1 - dividend : -dividend;
		neg = !neg;
	}
	if (divisor < 0) {
		divisor = (divisor == INT_MIN) ? 1 - divisor : -divisor;
		neg = !neg;
	}
	int div = 0;
	int left = dividend - divisor;
	while (left >= 0) {
		div++;
		left -= divisor;
	}
	if (!neg)return div;
	return 0 - div;
}

int divide(int dividend, int divisor) {
	if (dividend == INT_MIN && divisor == -1) {
		return INT_MAX;
	}
	long dvd = labs(dividend), dvs = labs(divisor), ans = 0;
	int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
	while (dvd >= dvs) {
		long temp = dvs, m = 1;
		while (dvd >= (temp << 1)) {
			temp <<= 1;
			m <<= 1;
		}
		dvd -= temp;
		ans += m;
	}
	return sign * ans;
}
