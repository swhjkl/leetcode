/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return diameter;
    }

private:
    int maxDepth(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        diameter = max(diameter, left + right);
        return max(left, right) + 1;
    }

    int diameter{0};
};
// @lc code=end

