/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
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
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *parent = root;
        for (auto &c : word) {
            int index = c - 'a';
            if (!parent->child[index]) {
                return false;
            }
            parent = parent->child[index];
        }
        return parent->word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *parent = root;
        for (auto &c : prefix) {
            int index = c - 'a';
            if (!parent->child[index]) {
                return false;
            }
            parent = parent->child[index];
        }
        return parent;
    }

private:
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

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

