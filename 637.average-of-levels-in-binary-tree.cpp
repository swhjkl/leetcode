/*
 * @lc app=leetcode id=637 lang=cpp
 *
 * [637] Average of Levels in Binary Tree
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        if (!root) {
            return result;
        }
        queue<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            auto count = nodes.size();
            double sum = 0;
            for (int i = 0; i < count; ++i) {
                auto n = nodes.front();
                nodes.pop();
                sum += n->val;
                if (n->left) {
                    nodes.push(n->left);
                }
                if (n->right) {
                    nodes.push(n->right);
                }
            }
            result.push_back(sum / count);
        }
        return result;
    }
};
// @lc code=end

