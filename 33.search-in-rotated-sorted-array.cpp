/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int begin = 0;
        int end = nums.size() - 1;
        while (begin <= end) {
            int mid = (begin + end) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (mid == begin) {
                return nums[end] == target ? end : -1;
            }
            if ((nums[mid] < nums[begin] && (target >= nums[begin] || target <= nums[mid]))
                || nums[mid] > nums[begin] && target <= nums[mid] && target >= nums[begin]) {
                end = mid;
            } else {
                begin = mid;
            }
        }
        return -1;
    }
};
// @lc code=end

