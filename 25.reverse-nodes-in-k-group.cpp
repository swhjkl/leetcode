/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy_head = new ListNode;
        ListNode *prev_tail = dummy_head;
        while (head) {
            ListNode *tail = head;
            for (int i = 1; i < k && tail != NULL; i++) {
                tail = tail->next;
            }
            if (!tail) {
                break;
            }
            ListNode *next_head = tail->next;
            tail->next = NULL;
            prev_tail->next = tail;
            prev_tail = head;
            ListNode *prev = NULL;
            while (head) {
                ListNode *tmp = head->next;
                head->next = prev;
                prev = head;
                head = tmp;
            }
            head = next_head;
        }
        return dummy_head->next;
    }
};
// @lc code=end

