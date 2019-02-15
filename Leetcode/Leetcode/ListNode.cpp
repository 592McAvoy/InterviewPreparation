#include"problem.h"

ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
	ListNode* dami = new ListNode(0);
	ListNode* cur = dami;
	while (l1 && l2) {
		int v1 = l1->val;
		int v2 = l2->val;
		if (v1 < v2) {
			cur->next = new ListNode(v1);
			l1 = l1->next;
		}
		else {
			cur->next = new ListNode(v2);
			l2 = l2->next;
		}
		cur = cur->next;
	}
	if (l1) cur->next = l1;
	else cur->next = l2;
	return dami->next;
}
ListNode* mergeLists(vector<ListNode*>& lists, int low, int high) {
	if (low == high) return lists[low];
	if (low + 1 == high) return merge2Lists(lists[low], lists[high]);
	int mid = low + (high - low) / 2;
	ListNode* l1 = mergeLists(lists, low, mid);
	ListNode* l2 = mergeLists(lists, mid + 1, high);
	return merge2Lists(l1, l2);
}
ListNode* mergeKLists0(vector<ListNode*>& lists) {
	int k = lists.size();
	if (k == 0)return NULL;
	return mergeLists(lists, 0, k - 1);
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
	int k = lists.size();
	if (k == 0)return NULL;
	vector<int> vec;
	for (ListNode* l : lists) {
		while (l) {
			vec.push_back(l->val);
			l = l->next;
		}
	}
	sort(vec, 0, vec.size() - 1);
	ListNode* dami = new ListNode(0);
	ListNode* p = dami;
	for (int n : vec) {
		p->next = new ListNode(n);
		p = p->next;
	}
	return dami;
}

void swap(ListNode* l1, ListNode* l2) {
	int t = l1->val;
	l1->val = l2->val;
	l2->val = t;
}
ListNode* swapPairs(ListNode* head) {
	if (!head)return head;
	ListNode* cur = head;
	ListNode* next = cur->next;
	while (cur && next) {
		swap(cur, next);
		cur = next->next;
		if (cur)next = cur->next;
	}
	return head;
}

ListNode* reverseKGroup(ListNode* head, int k) {
	if (!head)return head;
	stack<int> S;
	ListNode* p = head;
	while (p) {
		ListNode* tmp = p;
		for (int i = 0; i < k; i++) {
			if (!tmp) return head;
			S.push(tmp->val);
			tmp = tmp->next;			
		}
		tmp = p;
		for (int i = 0; i < k; i++) {
			tmp->val = S.top();
			S.pop();
			tmp = tmp->next;
		}
		p = tmp;
	}
	return head;
}

