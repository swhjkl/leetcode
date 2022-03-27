/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (63.67%)
 * Likes:    8604
 * Dislikes: 299
 * Total Accepted:    1.3M
 * Total Submissions: 2M
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings strs, group the anagrams together. You can return
 * the answer in any order.
 * 
 * An Anagram is a word or phrase formed by rearranging the letters of a
 * different word or phrase, typically using all the original letters exactly
 * once.
 * 
 * 
 * Example 1:
 * Input: strs = ["eat","tea","tan","ate","nat","bat"]
 * Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
 * Example 2:
 * Input: strs = [""]
 * Output: [[""]]
 * Example 3:
 * Input: strs = ["a"]
 * Output: [["a"]]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= strs.length <= 10^4
 * 0 <= strs[i].length <= 100
 * strs[i] consists of lowercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      map<string, vector<string>> groups;
      for (auto &s : strs) {
        string key(26, 0);
        for (auto &c : s) {
          key[c - 'a']++;
        }
        groups[key].push_back(s);
      }
      vector<vector<string>> ret;
      for (auto &p : groups) {
        ret.push_back(move(p.second));
      }
      return ret;
    }
};
// @lc code=end

