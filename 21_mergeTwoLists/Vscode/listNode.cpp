/*
 * @Author: Dongxu Lv 
 * @Date: 2019-11-29 15:07:24 
 * @Last Modified by: Dongxu Lv
 * @Last Modified time: 2019-11-29 15:22:37
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	if (l1 == NULL) {
		return l2;
	}   
	else if (l2 == NULL) {
		return l1;
	}

	ListNode* head = NULL;
	
	if (l1->val >= l2->val) {
		head = l2;
		l2 = l2->next;
	}
	else {
		head = l1;
		l1 = l1->next;
	}

	ListNode* temp = head;

	while((l1 != NULL) & (l2 != NULL)) {
		if (l1->val >= l2->val) {
			/* code */
			temp->next = l2;
			l2 = l2->next;
		}
		else {
			temp->next = l1;
			l1 = l1->next;
		}

		temp = temp->next;
	}

	if (l1 == NULL) {
		temp->next = l2;
	}
	else {
		temp->next = l1;
	}
	return head;

}


int main()
{
	
	int i;

	ListNode* head1 = new ListNode(1);
	ListNode* listNode_1 = head1;
	// ListNode* temp1 = NULL;
	// for (int i = 1; i < 2; i+=2)
	// {
	// 	ListNode* temp1 = new ListNode(i);
	// 	head1->next = temp1;
	// 	head1 = head1->next;
	// }

	ListNode* backup_listnode_1 = listNode_1;
	cout << "第一个链表为：" << endl;
	while(listNode_1 != NULL) {
		cout << listNode_1->val << endl;
		listNode_1 = listNode_1 -> next;
	}

	ListNode* head2 = new ListNode(2);
	ListNode* listNode_2 = head2;
	// for (int i = 2; i < 3; i+=2)
	// {
	// 	/* code */
	// 	ListNode* temp2 = new ListNode(i);
	// 	head2->next = temp2;
	// 	head2 = head2->next;
	// }

	ListNode* backup_listnode_2 = listNode_2;
	cout << "第二个链表为：" << endl;
	while(listNode_2 != NULL) {
		cout << listNode_2->val << endl;
		listNode_2 = listNode_2 -> next;
	}

	ListNode* res_head = mergeTwoLists(backup_listnode_1, backup_listnode_2);

	cout << "合并后的链表为：" << endl;
	while(res_head != NULL) {
		cout << res_head->val << endl;
		res_head = res_head->next;
	}

	/* code */
	return 0;
}