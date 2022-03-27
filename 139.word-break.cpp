/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[s.size()] = true;
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i + 1; j <= s.size(); j++) {
                if (dp[j] && dict.find(s.substr(i, j - i)) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};
// @lc code=end

