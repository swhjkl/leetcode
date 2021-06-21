/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        if (!root) {
            return s;
        }
        inorder(root, s);
        s.push_back(';');
        postorder(root, s);
        cout << s << endl;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return NULL;
        }
        vector<pair<long, int>> inorder;
        vector<pair<long, int>> postorder;
        auto *v = &inorder;
        int begin = 0;
        long first = 0;
        for (int i = 0; i < data.size(); i++) {
            if (data[i] == ';') {
                begin = i + 1;
                v = &postorder;
            } else if (data[i] == ',') {
                v->push_back({first, stoi(data.substr(begin, i - begin))});
                begin = i + 1;
            } else if (data[i] == ':') {
                first = stol(data.substr(begin, i - begin));
                begin = i + 1;
            }
        }

        return buildTree(inorder, 0, inorder.size() - 1,
            postorder, 0, postorder.size() - 1);
    }

private:
    void inorder(TreeNode *root, string &s) {
        if (!root) {
            return;
        }
        inorder(root->left, s);
        s.append(to_string(uint64_t(root))).append(":").append(to_string(root->val)).append(",");
        inorder(root->right, s);
    }

    void postorder(TreeNode *root, string &s) {
        if (!root) {
            return;
        }
        postorder(root->left, s);
        postorder(root->right, s);
        s.append(to_string(uint64_t(root))).append(":").append(to_string(root->val)).append(",");
    }

    TreeNode *buildTree(vector<pair<long, int>> &inorder, int ibegin, int iend,
        vector<pair<long, int>> &postorder, int pbegin, int pend) {
            TreeNode *root = new TreeNode(postorder[pend].second);
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

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

