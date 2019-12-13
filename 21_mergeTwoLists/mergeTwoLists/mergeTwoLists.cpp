#include <iostream>
#include <stdio.h>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

//ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//	if (l1 == NULL) {
//		return l1;
//	}
//	else if (l2 == NULL) {
//		return l2;
//	}
//
//	ListNode* head = NULL;
//	if ()
//}

void main()
{
    
	ListNode* a = new ListNode(-1);
	ListNode* cur = a;
	for (int i = 0; i < 10; i++) {
		ListNode* tmp = new ListNode(i);
		cur->next = tmp;
		cur = tmp;
	}

	while (a) {
		cout << a->val << endl;
		a = a->next;
	}

	cout << "Hello World!\n";
	//return 0;
}

