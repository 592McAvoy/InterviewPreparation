#include "roundB.h"

long long NoNine::naiveCnt(long long F, long long L) {
	long long cnt = 0;
	for (long long i = F; i <= L; i++) {
		bool nonine = true;
		if (i % 9 == 0) {//9µÄ±¶Êý
			continue;
		}

		long long tmp = i;
		do {
			if (tmp % 10 == 9) {
				nonine = false;
				break;
			}
			tmp /= 10;
		} while (tmp != 0);

		if (nonine)cnt++;
	}
	return cnt;
}
void NoNine::run() {
	string infile = "../Data/B1-NoNine/A-small-practice.in";
	string outfile = "../Data/B1-NoNine/A-small-practice.out";

	ifstream in(infile);
	ofstream out(outfile);

	int T;
	in >> T;
	for (int i = 0; i < T; i++) {
		cout << "case #" << i + 1 << ": ";
		out << "Case #" << i + 1 << ": ";
		long long F, L;
		in >> F >> L;
		out << naiveCnt(F, L) << endl;
		cout << naiveCnt(F, L) << endl;
	}
}