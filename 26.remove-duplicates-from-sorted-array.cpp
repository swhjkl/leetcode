/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int i = 1, j = 1;
        while (j < nums.size()) {
            if (nums[j] == nums[i - 1]) {
                j++;
            } else {
                nums[i++] = nums[j++];
            }
        }
        return i;
    }
};
// @lc code=end

