/*
 * @lc app=leetcode id=653 lang=cpp
 *
 * [653] Two Sum IV - Input is a BST
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) {
            return false;
        }
        Iterator l(root, true);
        Iterator r(root, false);
        for (int i = l.next(), j = r.next(); i < j;) {
            int sum = i + j;
            if (k == sum) {
                return true;
            } else if (k < sum) {
                j = r.next();
            }else {
                i = l.next();
            }
        }
        return false;
    }

    class Iterator {
        stack<TreeNode*> nodes;
        TreeNode* node;
        bool forward;
    public:
        Iterator(TreeNode* root, bool forward): node(root), forward(forward) {}
        int next() { 
            while (node || !nodes.empty()) {
                if (node) {
                    nodes.push(node);
                    node = forward ? node->left : node->right;
                } else {
                    node = nodes.top();
                    nodes.pop();
                    int val = node->val;
                    node = forward ? node->right : node->left;
                    return val;
                }
            }
            return -1;
        }
    };
};
// @lc code=end

