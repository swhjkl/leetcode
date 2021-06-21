/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        set<int> sub{nums[0]};
        for (int i = 1; i < nums.size(); i++) {
            if (*sub.rbegin() < nums[i]) {
                sub.emplace_hint(sub.end(), nums[i]);
            } else {
                sub.emplace_hint(sub.erase(sub.lower_bound(nums[i])), nums[i]);
            }
        }
        return sub.size();
    }
};
// @lc code=end

