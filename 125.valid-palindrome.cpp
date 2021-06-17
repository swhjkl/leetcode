/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        int begin = 0, end = s.size() - 1;
        while (begin < end) {
            while (begin < end && !isalnum(s[begin])) {
                begin++;
            }
            while (begin < end && !isalnum(s[end])) {
                end--;
            }
            if (begin == end) {
                return true;
            }
            if (tolower(s[begin]) != tolower(s[end])) {
                return false;
            }
            begin++;
            end--;
        }
        return true;
    }
};
// @lc code=end

