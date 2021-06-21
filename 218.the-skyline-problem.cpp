/*
 * @lc app=leetcode id=218 lang=cpp
 *
 * [218] The Skyline Problem
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        map<int, vector<int>> heights;
        for (auto &&b : buildings) {
            heights[b[0]].push_back(b[2]);
            heights[b[1]].push_back(-b[2]);
        }

        multiset<int> s;
        int prev_height = 0;
        vector<vector<int>> ret;
        for (auto &&p : heights) {
            for (auto &&h : p.second) {
                if (h > 0) {
                    s.insert(h);
                } else {
                    s.erase(s.find(-h));
                }
            }
            int height = 0;
            if (!s.empty()) {
                height = *s.rbegin();
                if (height == prev_height) {
                    continue;
                }
            }
            prev_height = height;
            ret.push_back({p.first, height});
        }
        return ret;
    }
};
// @lc code=end

