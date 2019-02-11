#include "roundA.h"

void GBus::run() {
	string infile = "../0-GBus/A-large-practice.in";
	string outfile = "../0-GBus/A-large-practice.out";

	ifstream in(infile);
	ofstream out(outfile);

	int its;
	in >> its;
	for (int i = 0; i < its; i++) {
		int nums;
		in >> nums;
		vector<int> records;
		for (int j = 0; j < nums; j++) {
			int beg, end;
			in >> beg >> end;
			records.push_back(beg);
			records.push_back(end);
		}
		int tests;
		in >> tests;
		out << "Case #" << i + 1 << ": ";
		for (int j = 0; j < tests; j++) {
			int bus;
			in >> bus;
			int cnt = 0;
			for (int j = 0; j < nums; j++) {
				if (records[j * 2] <= bus && records[j * 2 + 1] >= bus)
					cnt++;
			}
			out << cnt << " ";
		}
		out << endl;
	}
}

bool EvenDigits::isEven(int i) {
	return i % 2 == 0;
}
long long EvenDigits::find(long long num) {
	cout << "NUM:\t" << num << endl;
	vector<int> digits;
	long long temp = num;
	while (temp != 0) {
		digits.push_back(temp % 10);
		temp = temp / 10;
	}

	int size = digits.size();
	long long up, down;
	up = num;
	down = num;
	long long t = 0;
	for (int j = size - 1; j >= 0; j--) {
		int now = digits[j];
		if (!isEven(now)) {
			down = t + (now - 1)*pow(10, j);
			up = t + (now + 1)*pow(10, j);
			j--;
			for (; j >= 0; j--) {
				down += 8 * pow(10, j);
				cout << down << endl;
			}
			break;
		}
		t += now * pow(10, j);
	}
	cout << "END------" << endl;
	if (num - down > up - num)
		return up;
	else
		return down;
}
void EvenDigits::run() {
	string infile = "../A1-EvenDigits/A-large-practice.in";
	string outfile = "../A1-EvenDigits/A-large-practice.out";

	ifstream in(infile);
	ofstream out(outfile);

	int its;
	in >> its;
	for (int i = 0; i < its; i++) {
		long long num;
		in >> num;
		out << "Case #" << i + 1  << ": ";
		long long target = find(num);
		long long t = find(target);
		while (t != target) {
			target = t;
			t = find(target);
		}
		out << abs(num - target) << endl;

	}
}

void LuckyDip::run() {
	string infile = "../A2-LuckyDip/B-large-practice.in";
	string outfile = "../A2-LuckyDip/B-large-practice.out";

	ifstream in(infile);
	ofstream out(outfile);

	int its;
	in >> its;
	for (int i = 0; i < its; i++) {
		out << "Case #" << i + 1 << ": ";
		int N, K;
		in >> N >> K;
		vector<long long>bag;
		double sum = 0;
		for (int j = 0; j < N; j++) {
			long long v;
			in >> v;
			bag.push_back(v);
			sum += v;
		}
		double avg = sum / N;
		vector<double> expect;
		expect.push_back(avg);
		for (int j = 1; j <= K; j++) {
			double s=0;
			double last = expect[j - 1];
			for (int k = 0; k < N; k++) {
				s += MAX(last, bag[k]);
			}
			expect.push_back(s / N);
		}
		out << expect[K] << endl;

	}
}//error

map<char, int> Words::word2map(string word) {
	int len = word.size();
	map<char, int> wmap;
	for (int i = 0; i < len; i++) {
		char ch = word.at(i);
		if (wmap.count(ch) == 0)
			wmap[ch] = 0;
		wmap[ch] += 1;
	}
	map<char, int>::iterator it;
	//cout << word << " : ";
	for (it = wmap.begin(); it != wmap.end(); it++) {
		//cout << it->first << " - " << it->second << " ";
	}
	//cout << endl;
	return wmap;
}
bool Words::mapEqual(map<char, int>& A, map<char, int>& B) {
	map<char, int>::iterator it;
	bool equal = true;
	for (it = A.begin(); it != A.end(); it++) {
		char key = it->first;
		int val = it->second;
		if (B[key] != val) {
			equal = false;
			break;
		}
	}
	return equal;
}
bool Words::search(string S, string word) {
	int len = word.size();
	char head = word.at(0);
	char tail = word.at(len - 1);

	long long size = S.size();
	for (long long i = 0; i <= size - len; i++) {
		if (S.at(i) == head && S.at(i + len - 1) == tail) {
			string cand = S.substr(i, len);
			
			map<char, int> wmap = word2map(word);
			map<char, int> cmap = word2map(cand);

			if (mapEqual(wmap, cmap) ){
				//cout << "get " << word << " as " << cand << endl;
					return true;
			}
		}
	}
	return false;
	
}
void Words::run() {
	string infile = "../Data/A3-ScrambleWords/C-large-practice.in";
	string outfile = "../Data/A3-ScrambleWords/C-large-practice.out";

	ifstream in(infile);
	ofstream out(outfile);

	int its;
	in >> its;
	for (int i = 0; i < its; i++) {
		cout << "it #" << i + 1 << endl;
		out << "Case #" << i + 1 << ": ";
		int L;
		in >> L;

		vector<string> dic;
		for (int j = 0; j < L; j++) {
			string word;
			in >> word;
			dic.push_back(word);
			//cout << key << ": " << dic[key] << endl;
		}
		long long N, A, B, C, D;
		char s1, s2;
		in >> s1 >> s2 >> N >> A >> B >> C >> D;
		//cout<< s1 <<" "<< s2 << " " <<N << " " << A << " " << B << " " << C << " " << D<<endl;
		string S = "";
		S += s1;
		S += s2;
		vector<long long> X;
		X.push_back(long long(s1));
		X.push_back(long long(s2));

		for (long long j = 2; j < N; j++) {
			long long x = (A * X[j - 1] + B * X[j - 2] + C) % D;
			X.push_back(x);
			S += char(97 + (x % 26));
		}
		//cout << S << endl << endl;

		int cnt = 0;

		for (int j = 0; j < L; j++) {
			string word = dic[j];
			if (search(S, word))
				cnt++;
		}
		out << cnt << endl;
	}
}