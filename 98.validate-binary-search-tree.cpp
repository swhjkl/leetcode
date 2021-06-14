/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, INT64_MAX, INT64_MIN);
    }

private:
    bool isValidBST(TreeNode* root, int64_t max, int64_t min) {
        if (!root) {
            return true;
        }
        if (root->val <= min || root->val >= max) {
            return false;
        }
        return isValidBST(root->left, root->val, min) && isValidBST(root->right, max, root->val);
    }
};
// @lc code=end

