/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sa = 0, sb = 0;
        ListNode *tmp = headA;
        while (tmp) {
            tmp = tmp->next;
            sa++;
        }
        tmp = headB;
        while (tmp) {
            tmp = tmp->next;
            sb++;
        }
        while (headA && sa > sb) {
            headA = headA->next;
            sa--;
        }
        while (headB && sb > sa) {
            headB = headB->next;
            sb--;
        }
        while (headA && headB) {
            if (headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};
// @lc code=end

