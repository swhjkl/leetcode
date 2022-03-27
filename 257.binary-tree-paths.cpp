/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
 *
 * https://leetcode.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (58.15%)
 * Likes:    3832
 * Dislikes: 175
 * Total Accepted:    492K
 * Total Submissions: 846K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * Given the root of a binary tree, return all root-to-leaf paths in any
 * order.
 * 
 * A leaf is a node with no children.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,2,3,null,5]
 * Output: ["1->2->5","1->3"]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1]
 * Output: ["1"]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 100].
 * -100 <= Node.val <= 100
 * 
 * 
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (!root) {
            return result;
        }
        binaryTreePaths(root, "", result);
        return result;
    }

private:
    void binaryTreePaths(TreeNode* curr, string word, vector<string> &result) {
        word += to_string(curr->val);
        if (!curr->left && !curr->right) {
            result.push_back(word);
            return;
        }
        word += "->";
        if (curr->left) {
            binaryTreePaths(curr->left, word, result);
        }
        if (curr->right) {
            binaryTreePaths(curr->right, word, result);
        }
    }
};
// @lc code=end

