/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */

// @lc code=start
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int max_count = 0;
        vector<int> count(26, 0);
        for (auto c : tasks) {
            count[c - 'A']++;
            if (count[c - 'A'] > max_count) max_count = count[c - 'A'];
        }
        int ans = (max_count - 1) * (n + 1);
        for (auto c : count) {
            if (c == max_count) {
                ans++;
            }
        }
        return max(ans, (int)tasks.size());
    }
};
// @lc code=end

