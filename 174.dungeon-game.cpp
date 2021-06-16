/*
 * @lc app=leetcode id=174 lang=cpp
 *
 * [174] Dungeon Game
 */

// @lc code=start
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> health;
        for (int i = 0; i < m + 1; i++) {
            health.push_back(vector<int>(n));
        }
        int tmp = 1 - dungeon[m - 1][n - 1];
        health[m - 1][n - 1] = tmp <= 0 ? 1 : tmp;
        for (int j = n - 2; j >= 0; j--) {
            tmp = health[m - 1][j + 1] - dungeon[m - 1][j];
            health[m - 1][j] = tmp <= 0 ? 1 : tmp;
        }
        for (int i = m - 2; i >= 0; i--) {
            tmp = health[i + 1][n - 1] - dungeon[i][n - 1];
            health[i][n - 1] = tmp <= 0 ? 1 : tmp;
        }
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                tmp = min(health[i + 1][j], health[i][j + 1]) - dungeon[i][j];
                health[i][j] = tmp <= 0 ? 1 : tmp;
            }
        }
        return health[0][0];
    }
};
// @lc code=end

