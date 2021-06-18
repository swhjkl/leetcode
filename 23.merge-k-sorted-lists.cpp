/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int end = lists.size() - 1;
        while (end > 0) {
            int begin = 0;
            while (begin < end) {
                mergeTwoList(lists, begin++, end--);
            }
        }
        return lists.empty() ? NULL : lists[0];
    }

private:
    void mergeTwoList(vector<ListNode*>& lists, int l, int r) {
        if (l == r) {
            return;
        }
        ListNode *dummy_head = new ListNode;
        ListNode *prev = dummy_head;
        ListNode *l1 = lists[l];
        ListNode *l2 = lists[r];
        while (l1 && l2) {
            ListNode *tmp;
            if (l1->val <= l2->val) {
                prev->next = l1;
                l1 = l1->next;
            } else {
                prev->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;
        }
        if (l1) {
            prev->next = l1;
        } else if(l2) {
            prev->next = l2;
        }
        lists[l] = dummy_head->next;
    }
};
// @lc code=end

