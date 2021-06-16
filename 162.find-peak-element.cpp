/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return findPeakElement(nums, 0, nums.size() - 1);
    }

public:
    int findPeakElement(vector<int> &nums, int begin, int end) {
        if (begin == end) {
            return begin;
        }
        int mid = (begin + end) / 2;
        if (nums[mid] > nums[mid + 1]) {
            end = mid;
        } else {
            begin = mid + 1;
        }
        return findPeakElement(nums, begin, end);
    }
};
// @lc code=end

