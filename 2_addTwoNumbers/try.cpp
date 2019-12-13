/*
 * @Author: Dongxu Lv 
 * @Date: 2019-11-30 10:20:15 
 * @Last Modified by: Dongxu Lv
 * @Last Modified time: 2019-11-30 10:50:27
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


int main() {
    int i;

    // 生成第一个链表
    ListNode* listNode_1 = new ListNode(2);
    ListNode* listNode_1_head = listNode_1;
    cout << "第一个链表为：" << endl;
    cout << 2 << endl;
    for (i = 0; i < 3; i++) {
        ListNode* temp_1 = new ListNode(i+1);
        cout << i+1 << endl;
        listNode_1_head->next = temp_1;
        listNode_1_head = listNode_1_head->next;
    }
    // 生成第二个链表
    ListNode* listNode_2 = new ListNode(7);
    ListNode* listNode_2_head = listNode_2;
    cout << "第二个链表为：" << endl;
    cout << 7 << endl;
    for (i = 4; i < 9; i++) {
        ListNode* temp_2 = new ListNode(i + 1);
        cout << i+1 << endl;
        listNode_2_head -> next = temp_2;
        listNode_2_head = listNode_2_head -> next;
    }
    // 基本变量与标志位定义
    bool carry = false;
    int sum = 0;
    ListNode* res = new ListNode(-1);
    ListNode* res_Window = res;

    while (listNode_1 || listNode_2) {
        sum = 0;

        if (listNode_1 != NULL) {
            sum += listNode_1 -> val;
            listNode_1 = listNode_1 -> next;
        }
        if (listNode_2 != NULL) {
            sum += listNode_2 -> val;
            listNode_2 = listNode_2 -> next;
        }
        sum += carry;
        carry = (sum > 9);
        ListNode* temp_Res = new ListNode(sum % 10);
        res_Window -> next = temp_Res;
        res_Window = res_Window -> next;

    }


    

    // ListNode* resHead_ = NULL;
    // ListNode* resHead = resHead_;
    // int addOne = 0;
    // int listNode_1_val, listNode_2_val, resHead_val;
    
    // listNode_1_val = listNode_1_head->val;
    // listNode_2_val = listNode_2_head->val;
    // resHead_val = listNode_1_val + listNode_2_val + addOne;
    // if (resHead_val >= 10) {
    //     resHead_val -= 10;
    //     addOne = 1;
    // }
    // else
    // {
    //     addOne = 0;
    // }
    // ListNode* resHead_ = new ListNode(resHead_val);
    // ListNode* resHead = resHead_->next;
    // // resHead = resHead->next;
    // listNode_1_head = listNode_1_head->next;
    // listNode_2_head = listNode_2_head->next;

    // cout << "进入循环" << endl;
    // cout << listNode_1_head->val << endl;
    // cout << listNode_2_head->val << endl;
    // // cout << resHead->val << endl;
    // while ((listNode_1_head != NULL) & (listNode_2_head != NULL))
    // {
    //     /* code */
    //     listNode_1_val = listNode_1_head->val;
    //     listNode_2_val = listNode_2_head->val;
    //     // resHead_val = resHead->val;
    //     resHead_val = listNode_1_val + listNode_2_val + addOne;
    //     if (resHead_val >= 10) {
    //         resHead_val -= 10;
    //         addOne = 1;
    //     }
    //     else
    //     {
    //         addOne = 0;
    //     }
    //     ListNode* resHead_new = new ListNode(resHead_val);
    //     resHead = resHead_new;
    //     resHead = resHead->next;
    //     listNode_1_head = listNode_1_head->next;
    //     listNode_2_head = listNode_2_head->next;
    // }
    // cout << "逃出循环" << endl;

    // if ((listNode_1_head == NULL) & (listNode_2_head != NULL)) {
    //     // listNode_2_head->val += addOne;
    //     while (listNode_2_head->val + addOne >= 10)
    //     {
    //         /* code */
    //         listNode_2_head->val -= 10;
    //         listNode_2_head = listNode_2_head->next;
    //         addOne = 1;
    //     }
        
    //     resHead = listNode_2_head;
    // }
    // else if ((listNode_1_head != NULL) & (listNode_2_head == NULL))
    // {
    //     while (listNode_1_head->val + addOne >= 10)
    //     {
    //         /* code */
    //         listNode_1_head->val -= 10;
    //         listNode_1_head = listNode_1_head->next;
    //         addOne = 1;
    //     }
    //     resHead = listNode_1_head;
    // }
    
    cout << "第三个链表：" << endl;
    ListNode* res_Print = res -> next;
    while (res_Print != NULL)
    {
        cout << res_Print -> val << endl;
        res_Print = res_Print -> next;
    }

    return 0;
}