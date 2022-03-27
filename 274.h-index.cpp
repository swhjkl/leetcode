/*
 * @lc app=leetcode id=274 lang=cpp
 *
 * [274] H-Index
 */

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {
        vector<int> hs(citations.size() + 1, 0);
        for (auto n : citations) {
            if (n > citations.size()) {
                hs[citations.size()]++;
            } else {
                hs[n]++;
            }
        }
        int count = 0;
        for (int i = hs.size() - 1; i >= 0; i--) {
            count += hs[i];
            if (count >= i) {
                return i;
            }
        }
        return 0;
    }
};
// @lc code=end

