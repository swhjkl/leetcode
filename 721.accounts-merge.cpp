/*
 * @lc app=leetcode id=721 lang=cpp
 *
 * [721] Accounts Merge
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        for (auto act : accounts) {
            for (int i = 2; i < act.size(); i++) {
                adjacent[act[1]].push_back(act[i]);
                adjacent[act[i]].push_back(act[1]);
            }
        }

        vector<vector<string>> result;
        for (auto act : accounts) {
            if (visited.find(act[1]) != visited.end()) {
                continue;
            }
            result.push_back({act[0]});
            dfs(act[1], result.back());
            sort(result.back().begin() + 1, result.back().end());
        }
        return result;
    }
private:
    void dfs(const string &start, vector<string> &result) {
        if (visited.find(start) != visited.end()) {
            return;
        }
        visited.insert(start);
        result.push_back(start);
        for (auto &adj : adjacent[start]) {
            dfs(adj, result);
        }
    }

    unordered_set<string> visited;
    unordered_map<string, vector<string>> adjacent;
};
// @lc code=end

