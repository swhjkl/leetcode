/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 */

// @lc code=start
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        restoreIpAddresses(s, 0, "", 0, result);
        return result;
    }

private:
    void restoreIpAddresses(const string &s, size_t index, string ip, int level,
        vector<string> &result) {
        if (level == 4) {
            if (index == s.size()) {
                result.push_back(ip);
            }
            return;
        }
        if (index == s.size()) {
            return;
        }
        if (!ip.empty()) {
            ip.push_back('.');
        }
        ip.push_back(s[index]);
        restoreIpAddresses(s, index + 1, ip, level + 1, result);
        if (s[index] == '0' || index + 1 == s.size()) {
            return;
        }
        ip.push_back(s[index + 1]);
        restoreIpAddresses(s, index + 2, ip, level + 1, result);
        if (index + 2 == s.size()) {
            return;
        }
        auto num = std::stoi(s.substr(index, 3));
        if (num > 255) {
            return;
        }
        ip.push_back(s[index + 2]);
        restoreIpAddresses(s, index + 3, ip, level + 1, result);
    }
};
// @lc code=end

