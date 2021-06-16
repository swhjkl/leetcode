/*
 * @lc app=leetcode id=237 lang=cpp
 *
 * [237] Delete Node in a Linked List
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
    void deleteNode(ListNode* node) {
        ListNode *prev = node;
        while (node->next) {
            node->val = node->next->val;
            prev = node;
            node = node->next;
        }
        delete node;
        prev->next = NULL;
    }
};
// @lc code=end

