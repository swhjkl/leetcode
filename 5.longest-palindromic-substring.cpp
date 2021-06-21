/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int longest = 0;
        int begin = 0;
        int end = -1;
        for (int i = 0; i < s.size(); i++) {
            int len1 = expand(s, i, i);
            int len2 = expand(s, i, i + 1);
            int len = max(len1, len2);
            if (len > longest) {
                begin = i - (len - 1) / 2;
                end = i + len / 2;
                longest = len;
            }
        }
        return s.substr(begin, end - begin + 1);
    }

private:
    int expand(const string &s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }
};
// @lc code=end

