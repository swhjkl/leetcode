/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (!root) {
            return ret;
        }
        queue<TreeNode*> q;
        stack<TreeNode*> s;
        q.push(root);
        q.push(nullptr);
        bool forward = true;
        vector<int> level;
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            if (curr) {
                level.push_back(curr->val);
                if (forward) {
                    if (curr->left) {
                        s.push(curr->left);
                    }
                    if (curr->right) {
                        s.push(curr->right);
                    }
                } else {
                    if (curr->right) {
                        s.push(curr->right);
                    }
                    if (curr->left) {
                        s.push(curr->left);
                    }
                }
            } else {
                ret.push_back(level);
                level.clear();
                while (!s.empty()) {
                    q.push(s.top());
                    s.pop();
                }
                if (!q.empty()){
                    q.push(NULL);
                }
                forward = !forward;
            }
        }
        return ret;
    }
};
// @lc code=end

