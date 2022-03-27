/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (53.24%)
 * Likes:    9305
 * Dislikes: 648
 * Total Accepted:    1.1M
 * Total Submissions: 2.1M
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent. Return the answer in
 * any order.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: digits = "23"
 * Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: digits = ""
 * Output: []
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: digits = "2"
 * Output: ["a","b","c"]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= digits.length <= 4
 * digits[i] is a digit in the range ['2', '9'].
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        static const vector<string> dict{ "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        vector<string> ret{""};
        for (auto i : digits) {
            auto size = ret.size();
            string chars = dict[i - '2'];
            for (size_t j = 1; j < chars.size(); j++) {
                for (size_t k = 0; k < size; k++) {
                    ret.push_back(ret[k] + string(1, chars[j]));
                }
            }
            for (size_t k = 0; k < size; k++) {
                ret[k].push_back(chars[0]);
            }
        }
        return ret;
    }
};
// @lc code=end

