/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        auto total = nums1.size() + nums2.size();
        auto mid = total / 2;
        bool is_odd = total % 2;
        int prev = 0, curr = 0;
        auto itr1 = nums1.begin();
        auto itr2 = nums2.begin();
        for (size_t i = 0; i < total; i++) {
            prev = curr;
            if (itr1 == nums1.end()) {
                curr = *(itr2++);
            } else if (itr2 == nums2.end()) {
                curr = *(itr1++);
            } else if (*itr1 <= *itr2) {
                curr = *(itr1++);
            } else {
                curr = *(itr2++);
            }
            if (i == mid) {
                return is_odd ? curr : (prev + curr) / (double)2;
            }
        }
        return -1;
    }
};
// @lc code=end

