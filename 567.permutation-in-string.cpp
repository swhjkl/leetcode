/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }
        vector<int> c1(26), c2(26);
        for (int i = 0; i < s1.size(); i++) {
            c1[s1[i] - 'a']++;
            c2[s2[i] - 'a']++;
        }
        int match = 0;
        for (int i = 0; i < 26; i++) {
            match += (c1[i] == c2[i]);
        }
        if (match == 26) {
            return true;
        }

        for (int i = 0; i < s2.size() - s1.size(); i++) {
            int r = s2[i + s1.size()] - 'a';
            int l = s2[i] - 'a';
            if (r == l) {
                continue;
            }
            if (c2[l] == c1[l]) {
                match--;
            } else if (c2[l] == c1[l] + 1) {
                match++;
            }
            c2[l]--;
            if (c2[r] == c1[r]) {
                match--;
            } else if (c2[r] == c1[r] - 1) {
                match++;
            }
            c2[r]++;
            if (match == 26) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

