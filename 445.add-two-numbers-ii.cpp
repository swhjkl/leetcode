/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int size1 = 0;
        int size2 = 0;
        ListNode *tmp = l1;
        while (tmp) {
            size1++;
            tmp = tmp->next;
        }
        tmp = l2;
        while (tmp) {
            size2++;
            tmp = tmp->next;
        }
        while (size1 < size2) {
            tmp = new ListNode(0, l1);
            size1++;
            l1 = tmp;
        }
        while (size1 > size2) {
            tmp = new ListNode(0, l2);
            size2++;
            l2 = tmp;
        }
        ListNode *head = nullptr;
        while (l1) {
            tmp = new ListNode(l1->val + l2->val, head);
            head = tmp;
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode *dummy_head = new ListNode(0, nullptr);
        int carry = 0;
        while (head) {
            head->val += carry;
            carry = 0;
            if (head->val >= 10) {
                carry = 1;
                head->val %= 10;
            }
            tmp = head->next;
            head->next = dummy_head->next;
            dummy_head->next = head;
            head = tmp;
        }
        if (carry) {
            dummy_head->val = 1;
            return dummy_head;
        } else {
            return dummy_head->next;
        }
    }
};
// @lc code=end

