/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }

private:
    TreeNode *buildTree(vector<int> &inorder, int ibegin, int iend,
        vector<int> &postorder, int pbegin, int pend) {
            TreeNode *root = new TreeNode(postorder[pend]);
            if (ibegin == iend) {
                return root;
            }
            int iroot = 0;
            for (int i = ibegin; i <= iend; i++) {
                if (inorder[i] == postorder[pend]) {
                    iroot = i;
                    break;
                }
            }
            if (iroot != ibegin) {
                root->left = buildTree(inorder, ibegin, iroot - 1,
                    postorder, pbegin, pbegin + (iroot - 1 - ibegin));
            }
            if (iroot != iend) {
                root->right = buildTree(inorder, iroot + 1, iend,
                    postorder, (pend - 1) - (iend - (iroot + 1)), pend - 1);
            }
            return root;
        }
};
// @lc code=end

