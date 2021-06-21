/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        len = nums.size();
        ret = new vector<vector<int>>;
        for (auto &i : nums) {
            count[i]++;
        }
        vector<int> a;
        backtrack(a);
        return *ret;
    }

private:
    void backtrack(vector<int> &last){
        if (len == last.size()) {
            ret->push_back(last);
            return;
        }
        for (auto &p : count) {
            if (p.second > 0) {
                p.second--;
                last.push_back(p.first);
                backtrack(last);
                last.pop_back();
                p.second++;
            }
        }
    }

    vector<vector<int>> *ret;
    unordered_map<int, int> count;
    int len;
};
// @lc code=end