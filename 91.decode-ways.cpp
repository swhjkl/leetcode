/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        vector<int> num(s.size() + 1, -1);
        num[s.size()] = 1;
        num[s.size() - 1] = s.back() != '0';
        for (int i = s.size() - 2; i >= 0; i--) {
            if (s[i] == '0') {
                num[i] = 0;
            } else {
                num[i] = num[i + 1];
                int tmp = stoi(s.substr(i, 2));
                if (tmp >= 10 && tmp <= 26) {
                    num[i] += num[i + 2];
                }
            }
        }
        return num[0];
    }

private:
};
// @lc code=end
