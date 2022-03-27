/*
 * @lc app=leetcode id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 */

// @lc code=start
class Solution {
public:
    bool validPalindrome(string s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            if (s[i] != s[j]) {
                bool valid = true;
                for (int p = i + 1, q = j; p < q; p++, q--) {
                    if (s[p] != s[q]) {
                        valid = false;
                    }
                }
                if (valid) {
                    return true;
                }
                valid = true;
                for (int p = i, q = j - 1; p < q; p++, q--) {
                    if (s[p] != s[q]) {
                        valid = false;
                    }
                }
                return valid;
            }
        }
        return true;
    }
};
// @lc code=end

