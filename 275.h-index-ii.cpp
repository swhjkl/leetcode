/*
 * @lc app=leetcode id=275 lang=cpp
 *
 * [275] H-Index II
 */

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int low = 0;
        int high = n - 1;
        int ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (citations[mid] >= n - mid) {
                ans = n - mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
// @lc code=end

