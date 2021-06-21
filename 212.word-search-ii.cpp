/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 */

// @lc code=start
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie t;
        for (auto &w : words) {
            t.insert(w);
        }
        vector<string> ret;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, t.root, "", ret);
            }
        }
        return ret;
    }

private:
    class Trie {
    public:
        /** Initialize your data structure here. */
        Trie() {
            root = new Node(0);
        }
        
        /** Inserts a word into the trie. */
        void insert(string word) {
            Node *parent = root;
            Node *prev = NULL;
            for (auto &c : word) {
                int index = c - 'a';
                if (!parent->child[index]) {
                    parent->child[index] = new Node(c);
                }
                parent = parent->child[index];
            }
            parent->word = true;
        }

        struct Node {
            char val;
            bool word;
            Node *child[26];

            Node(char v): val(v), word{false} {
                memset(child, 0, sizeof(Node*) * 26);
            }
        };

        Node *root;
    };

    void dfs(vector<vector<char>> &board, int i, int j, Trie::Node *curr, string path, vector<string> &ret) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || !board[i][j]) {
            return;
        }
        char c = board[i][j];
        curr = curr->child[c - 'a'];
        if (!curr) {
            return;
        }
        path.push_back(c);
        if (curr->word) {
            curr->word = false;
            ret.push_back(path);
        }
        board[i][j] = 0;
        dfs(board, i - 1, j, curr, path, ret);
        dfs(board, i + 1, j, curr, path, ret);
        dfs(board, i, j - 1, curr, path, ret);
        dfs(board, i, j + 1, curr, path, ret);
        board[i][j] = c;
    }

};
// @lc code=end