/*
 * @lc app=leetcode id=398 lang=cpp
 *
 * [398] Random Pick Index
 */

// @lc code=start
class Solution {
public:
    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            indice[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        auto v = indice[target];
        return v[rand() % v.size()];
    }
private:
    map<int, vector<int>> indice;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
// @lc code=end

