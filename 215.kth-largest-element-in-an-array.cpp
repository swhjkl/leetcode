/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int> topK;
        for (int i = 0; i < nums.size(); i++) {
            if (topK.size() < k) {
                topK.insert(nums[i]);
            } else if (*topK.begin() < nums[i]) {
                topK.erase(topK.begin());
                topK.insert(nums[i]);
            }
        }
        return *topK.begin();
    }
};
// @lc code=end

