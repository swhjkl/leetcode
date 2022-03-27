/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        for (int i = 0; i < s.size(); i++) {
            extendPalindrome(s, i, i);
            extendPalindrome(s, i, i + 1);
        }
        return count;
    }

    void extendPalindrome(const string &s, int start, int end) {
        while (start >= 0 && end < s.size() && s[start--] == s[end++]) {
            count++;
        }
    }

private:
    int count{0};
};
// @lc code=end

