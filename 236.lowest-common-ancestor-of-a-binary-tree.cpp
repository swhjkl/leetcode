/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *target = NULL;
        find(root, &p, &q, &target);
        return target;
    }

private:
    int find(TreeNode *curr, TreeNode **p, TreeNode **q, TreeNode **target) {
        if (!curr) {
            return 0;
        }
        int count = !!(*p) + !!(*q);
        int ret = 0;
        if (curr == *p) {
            *p = NULL;
            ret = 1;
        } else if (curr == *q) {
            ret = 1;
            *q = NULL;
        }
        if (ret == count) {
            return ret;
        }
        ret += find(curr->left, p, q, target);
        if (ret == count) {
            if (count == 2 && !*target) {
                *target = curr;
            }
            return ret;
        }
        ret += find(curr->right, p, q, target);
        if (ret == count && count == 2 && !*target) {
            *target = curr;
        }
        return ret;
    }
};
// @lc code=end

