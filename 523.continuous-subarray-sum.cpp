/*
 * @lc app=leetcode id=523 lang=cpp
 *
 * [523] Continuous Subarray Sum
 */

// @lc code=start
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        unordered_set<int> s;
        int prev = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int mod = sum % k;
            if (s.find(mod) != s.end()) {
                return true;
            }
            s.insert(prev);
            prev = mod;
        }
        return false;
    }
};
// @lc code=end

