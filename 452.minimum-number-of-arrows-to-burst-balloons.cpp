/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

// @lc code=start
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int shots = 0;
        int64_t prev = INT64_MIN;
        sort(points.begin(), points.end(),
            [](const vector<int> &a, const vector<int> &b) {
                return a[1] < b[1];
            });
        for (auto &p : points) {
            if (prev < p[0]) {
                prev = p[1];
                shots++;
            }
        }
        return shots;
    }
};
// @lc code=end

