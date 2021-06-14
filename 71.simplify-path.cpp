/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        string ret = "";
        for (string::size_type begin = 0; begin < path.size();) {
            auto end = path.find('/', begin);
            if (end == string::npos) {
                end = path.size();
            }
            if (begin != end) {
                auto section = path.substr(begin, end - begin);
                if (section == "..") {
                    while (ret.size() > 0) {
                        auto c = ret.back();
                        ret.pop_back();
                        if (c == '/') {
                            break;
                        }
                    }
                } else if (section != ".") {
                    ret.append("/");
                    ret.append(section);
                }
            }
            begin = end + 1;
        }
        if (ret.empty()) {
            ret = "/";
        }
        return ret;
    }
};
// @lc code=end

