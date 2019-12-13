/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 基本变量与标志位定义
        bool carry = false;
        int sum = 0;
        ListNode* res = new ListNode(-1);
        ListNode* res_Window = res;

        while (l1 || l2) {
            sum = 0;

            if (l1 != NULL) {
                sum += l1 -> val;
                l1 = l1 -> next;
            }
            if (l2 != NULL) {
                sum += l2 -> val;
                l2 = l2 -> next;
            }
            sum += carry;
            carry = (sum > 9);
            ListNode* temp_Res = new ListNode(sum % 10);
            res_Window -> next = temp_Res;
            res_Window = res_Window -> next;

        }

        if (carry) {
            ListNode* final_Bit = new ListNode(1);
            res_Window -> next = final_Bit;
        }
        
        return res -> next;
    }
};
// @lc code=end

