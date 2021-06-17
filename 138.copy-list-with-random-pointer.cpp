/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *itr = head;
        while (itr) {
            Node *tmp = itr->next;
            itr->next = new Node(itr->val);
            itr->next->next = tmp;
            itr = tmp;
        }

        itr = head;
        while (itr) {
            if (itr->random) {
                itr->next->random = itr->random->next;
            }
            itr = itr->next->next;
        }

        Node *dummy_head = new Node(0);
        Node *new_prev = dummy_head;
        itr = head;
        while (itr) {
            new_prev->next = itr->next;
            new_prev = itr->next;
            itr->next = itr->next->next;
            itr = itr->next;
        }
        return dummy_head->next;
    }
};
// @lc code=end

