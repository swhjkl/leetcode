/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        maxPathSum(root, &ans);
        return ans;
    }

private:
    int maxPathSum(TreeNode *root, int *ans) {
        if (!root) {
            return 0;
        }
        int larger = maxPathSum(root->left, ans);
        int less = maxPathSum(root->right, ans);
        if (larger < less) {
            int tmp = larger;
            larger = less;
            less = tmp;
        }
        int pathMax = larger > 0 ? root->val + larger : root->val;
        int treeMax = less > 0 ? pathMax + less : pathMax;
        if (treeMax > *ans) {
            *ans = treeMax;
        }
        return pathMax;
    }
};
// @lc code=end

