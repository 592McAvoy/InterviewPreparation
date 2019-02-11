#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include<vector>
#include<queue>
#include<map>
#include<math.h>

using namespace std;

#define MAX(a,b)((a)>(b)?(a):(b))

class GBus {
public:
	GBus(){}
	void run();
};

class EvenDigits {
public:
	EvenDigits() {}
	bool isEven(int);
	long long find(long long);
	void run();
};

class LuckyDip {
public:
	LuckyDip(){}
	void run();
};

class Words {
public:
	Words(){}
	void run();
	bool search(string S, string word);
	map<char, int> word2map(string word);
	bool mapEqual(map<char, int>& A, map<char, int>& B);
};