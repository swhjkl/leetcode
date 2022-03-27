/*
 * @lc app=leetcode id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
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
    struct Node {
        TreeNode *node;
        bool is_left;
    };
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        stack<Node> nodes;
        nodes.push({root, false});
        while (!nodes.empty()) {
            auto node = nodes.top();
            nodes.pop();
            if (!node.node->left && !node.node->right) {
                if (node.is_left) {
                    sum += node.node->val;
                }
            } else {
                if (node.node->right) {
                    nodes.push({node.node->right, false});
                }
                if (node.node->left) {
                    nodes.push({node.node->left, true});
                }
            }
        }
        return sum;
    }
};
// @lc code=end

