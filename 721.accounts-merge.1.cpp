/*
 * @lc app=leetcode id=721 lang=cpp
 *
 * [721] Accounts Merge
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        DSU dsu(accounts.size());
        map<string, int> email_groups;
        for (int i = 0; i < accounts.size(); i++) {
            auto &act = accounts[i];
            for (int j = 1; j < act.size(); j++) {
                auto itr = email_groups.find(act[j]);
                if (itr == email_groups.end()) {
                    email_groups[act[j]] = i;
                } else {
                    dsu.merge(itr->second, i);
                }
            }
        }

        unordered_map<int, vector<string>> components;
        for (auto p : email_groups) {
            components[dsu.find(p.second)].push_back(p.first);
        }

        vector<vector<string>> result;
        for (auto &c : components) {
            result.push_back({accounts[c.first][0]});
            result.back().insert(result.back().end(), c.second.begin(), c.second.end());
            sort(result.back().begin() + 1, result.back().end());
        }
        return result;
    }

private:
    class DSU {
    public:
        DSU(int size): roots(vector<int>(size)), ranks(vector<int>(size, 1)) {
            for (int i = 0; i < size; i++) {
                roots[i] = i;
            }
        }

        int find(int i) {
            if (roots[i] == i) {
                return i;
            }
            return roots[i] = find(roots[i]);
        }

        void merge(int i, int j) {
            auto ri = find(i);
            auto rj = find(j);
            if (ri == rj) {
                return;
            }
            if (ranks[ri] >= ranks[rj]) {
                ranks[ri] += ranks[rj];
                roots[rj] = ri;
            } else {
                ranks[rj] += ranks[ri];
                roots[ri] = rj;
            }
        }

    private:
        vector<int> roots;
        vector<int> ranks;
    };
};
// @lc code=end

