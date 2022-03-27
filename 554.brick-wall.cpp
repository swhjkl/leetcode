/*
 * @lc app=leetcode id=554 lang=cpp
 *
 * [554] Brick Wall
 */

// @lc code=start
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> sum_count;
        int min = wall.size();
        for (auto &w : wall) {
            int sum = 0;
            for (int j = 0; j < w.size() - 1; j++) {
                sum += w[j];
                sum_count[sum]++;
                int crossed = wall.size() - sum_count[sum]; 
                if (crossed < min) {
                    min = crossed;
                }
            }
        }
        return min;
    }
};
// @lc code=end

