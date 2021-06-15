/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        return findMin(nums, 0, nums.size() - 1);
    }

private:
    int findMin(vector<int>& nums, int begin, int end) {
        if (begin + 1 >= end) {
            return min(nums[begin], nums[end]);
        }
        int mid = (begin + end) / 2;
        if (nums[begin] > nums[mid]) {
            return findMin(nums, begin, mid);
        } else if (nums[end] < nums[mid]) {
            return findMin(nums, mid, end);
        } else {
            return nums[begin];
        }
    }
};
// @lc code=end

