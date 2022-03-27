/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int fill_index = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (fill_index < 2 ||
                nums[i] != nums[fill_index - 1] ||
                nums[i] != nums[fill_index - 2]) {
                nums[fill_index++] = nums[i];
            }
        }
        return fill_index;
    }
};
// @lc code=end

