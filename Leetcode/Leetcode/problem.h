#pragma once
#include<string>
#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<map>
#include<stack>

using namespace std;

/***********************       helper       ******************************/
#define MAX(a,b)((a)>(b)?(a):(b))
void swap(vector<int>& nums, int a, int b);
void sort(vector<int>& nums, int low, int high);
int binarySearch(vector<int>& nums, int low, int high, int target);

/***********************       Palindrome       ******************************/
string longestPalindrome(string s);

/***********************       N-sum       ******************************/
vector<int> twoSum(vector<int>& nums, int target);
vector<vector<int>> threeSum(vector<int>& nums);
int threeSumClosest(vector<int>& nums, int target);
vector<vector<int>> fourSum(vector<int>& nums, int target);

/***********************       ListNode       ******************************/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* merge2Lists(ListNode* l1, ListNode* l2);
ListNode* mergeKLists(vector<ListNode*>& lists);
ListNode* swapPairs(ListNode* head);
ListNode* reverseKGroup(ListNode* head, int k);

/***********************       Method implement      ******************************/
int strStr(string haystack, string needle);
int divide(int dividend, int divisor);

/***********************       Parentheses      ******************************/
int longestValidParentheses(string s);

/***********************       other      ******************************/
void nextPermutation(vector<int>& nums);

