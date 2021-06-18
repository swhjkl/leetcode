/*
 * @lc app=leetcode id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) {
            return root;
        }
        Node *level = root;
        while (level) {
            Node *node = level;
            Node *prev = NULL;
            while (node) {
                if (node->left) {
                    if (prev) {
                        prev->next = node->left;
                    }
                    prev = node->left;
                }
                if (node->right) {
                    if (prev) {
                        prev->next = node->right;
                    }
                    prev = node->right;
                }
                node = node->next;
            }
            while (level && !level->left && !level->right) {
                level = level->next;
            }
            if (level) {
                if (level->left) {
                    level = level->left;
                } else {
                    level = level->right;
                }
            }
        }
        return root;
    }
};
// @lc code=end

