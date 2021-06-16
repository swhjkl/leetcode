/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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
    void flatten(TreeNode* root) {
        if (!root) {
            return;
        }
        flattenWithTail(root);
    }

private:
    TreeNode *flattenWithTail(TreeNode *root) {
        auto left = root->left;
        auto right = root->right;
        if (!left && !right) {
            return root;
        }
        if (left) {
            root->left = nullptr;
            root->right = left;
            root = flattenWithTail(left);
        }
        if (right) {
            root->right = right;
            root = flattenWithTail(right);
        }
        return root;
    }
};
// @lc code=end

