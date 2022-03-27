/*
 * @lc app=leetcode id=525 lang=cpp
 *
 * [525] Contiguous Array
 */

// @lc code=start
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> indexes;
        indexes[0] = -1;
        int count = 0;
        int max_len = 0;
        for (int i = 0; i < nums.size(); i++) {
            count += nums[i] ? 1 : -1;
            auto itr = indexes.find(count);
            if (itr == indexes.end()) {
                indexes[count] = i;
            } else {
                max_len = max(max_len, i - itr->second);
            }
        }
        return max_len;
    }
};
// @lc code=end

