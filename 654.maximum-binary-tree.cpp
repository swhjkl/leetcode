/*
 * @lc app=leetcode id=654 lang=cpp
 *
 * [654] Maximum Binary Tree
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructMaximumBinaryTree(nums, 0, nums.size() - 1);
    }

private:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums, int begin, int end) {
        int index = begin;
        int max = -1;
        for (int i = begin; i <= end; i++) {
            if (max < nums[i]) {
                max = nums[i];
                index = i;
            }
        }
        TreeNode *root = new TreeNode(max);
        if (index - 1 >= begin) {
            root->left = constructMaximumBinaryTree(nums, begin, index - 1);
        }
        if (index + 1 <= end) {
            root->right = constructMaximumBinaryTree(nums, index + 1, end);
        }
        return root;
    }
};
// @lc code=end

