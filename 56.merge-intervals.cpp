/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ret;
        for (auto &interval : intervals)  {
            if (ret.empty() || ret.back()[1] < interval[0]) {
                ret.push_back(interval);
            } else if (ret.back()[1] < interval[1]) {
                ret.back()[1] = interval[1];
            }
        }
        return ret;
    }
};
// @lc code=end

