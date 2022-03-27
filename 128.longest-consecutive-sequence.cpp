/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;
        for (auto n : nums) {
            if (s.find(n - 1) == s.end()) {
                int len = 1;
                while (s.find(++n) != s.end()) {
                    len++;
                }
                if (len > longest) {
                    longest = len;
                }
            }
        }
        return longest;
    }
};
// @lc code=end

