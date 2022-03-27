/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (46.15%)
 * Likes:    8267
 * Dislikes: 509
 * Total Accepted:    905.7K
 * Total Submissions: 2M
 * Testcase Example:  '[1,2,2,1]'
 *
 * Given the head of a singly linked list, return true if it is a
 * palindrome.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [1,2,2,1]
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [1,2]
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the list is in the range [1, 10^5].
 * 0 <= Node.val <= 9
 * 
 * 
 * 
 * Follow up: Could you do it in O(n) time and O(1) space?
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
    bool isPalindrome(ListNode* head) {
      auto fast = head;
      auto slow = head;
      while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
      }

      ListNode *prev = nullptr;
      ListNode *next = nullptr;
      while (slow) {
        next = slow->next;
        slow->next = prev;
        prev = slow;
        slow = next;
      }
      while (prev && head) {
        if (prev->val != head->val) {
          return false;
        }
        prev = prev->next;
        head = head->next;
      }
      return true;
    }
};
// @lc code=end

