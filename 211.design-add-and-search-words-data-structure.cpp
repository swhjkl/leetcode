/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
 *
 * https://leetcode.com/problems/design-add-and-search-words-data-structure/description/
 *
 * algorithms
 * Medium (43.99%)
 * Likes:    4673
 * Dislikes: 195
 * Total Accepted:    386.7K
 * Total Submissions: 879K
 * Testcase Example:  '["WordDictionary","addWord","addWord","addWord","search","search","search","search"]\n' +
  '[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]'
 *
 * Design a data structure that supports adding new words and finding if a
 * string matches any previously added string.
 * 
 * Implement the WordDictionary class:
 * 
 * 
 * WordDictionary() Initializes the object.
 * void addWord(word) Adds word to the data structure, it can be matched
 * later.
 * bool search(word) Returns true if there is any string in the data structure
 * that matches word or false otherwise. word may contain dots '.' where dots
 * can be matched with any letter.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input
 * 
 * ["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
 * [[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
 * Output
 * [null,null,null,null,false,true,true,true]
 * 
 * Explanation
 * WordDictionary wordDictionary = new WordDictionary();
 * wordDictionary.addWord("bad");
 * wordDictionary.addWord("dad");
 * wordDictionary.addWord("mad");
 * wordDictionary.search("pad"); // return False
 * wordDictionary.search("bad"); // return True
 * wordDictionary.search(".ad"); // return True
 * wordDictionary.search("b.."); // return True
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= word.length <= 25
 * word in addWord consists of lowercase English letters.
 * word in search consist of '.' or lowercase English letters.
 * There will be at most 3 dots in word for search queries.
 * At most 10^4 calls will be made to addWord and search.
 * 
 * 
 */

// @lc code=start
class WordDictionary {
public:
    WordDictionary() {
      root = new TrieNode();
    }
    
    void addWord(string word) {
      auto curr = root;
      for (auto c : word) {
        if (curr->children[c - 'a'] == nullptr) {
          curr->children[c - 'a'] = new TrieNode(c);
        }
        curr = curr->children[c - 'a'];
      }
      curr->is_word = true;
    }
    
    bool search(string word) {
      return search(root, word, 0);
    }


private:
    struct TrieNode {
      char val;
      bool is_word{false};
      TrieNode* children[26];
      TrieNode(char c = 0): val(c) { memset(children, 0, 26 * sizeof(TrieNode*)); }
    } *root;

    bool search(TrieNode *curr, const string &word, int index) {
      if (!curr) {
        return false;
      }
      if (index == word.length()) {
        return curr->is_word;
      }
      char c = word[index];
      if (c != '.') {
        return search(curr->children[c - 'a'], word, index + 1);
      } else {
        for (auto &child : curr->children) {
          if (search(child, word, index + 1)) {
            return true;
          }
        }
        return false;
      }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end