/*
 * @lc app=leetcode id=513 lang=cpp
 *
 * [513] Find Bottom Left Tree Value
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
    int findBottomLeftValue(TreeNode* root) {
        int ret = root->val;
        find(root, &ret);
        return ret;
    }

private:
    int find(TreeNode *root, int *val) {
        if (!root) {
            return 0;
        }

        int left_val = root->val;
        int left_height = find(root->left, &left_val);
        int right_val = root->val;
        int right_height = find(root->right, &right_val);
        if (left_height >= right_height) {
            *val = left_val;
            return left_height + 1;
        } else {
            *val = right_val;
            return right_height + 1;
        }
    }
};
// @lc code=end

