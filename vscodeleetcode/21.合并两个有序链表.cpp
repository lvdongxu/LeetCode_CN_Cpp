/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
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
};
// @lc code=end

