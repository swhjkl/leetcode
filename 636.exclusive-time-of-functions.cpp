/*
 * @lc app=leetcode id=636 lang=cpp
 *
 * [636] Exclusive Time of Functions
 */

// @lc code=start
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> time(n, 0);
        int prev_timestamp = 0;
        stack<LogItem*> items;
        for (auto &log : logs) {
            auto item = new LogItem(log);
            if (item->start) {
                items.push(item);
            } else {
                int elapsed = item->timestamp - items.top()->timestamp + 1;
                time[item->func_id] += elapsed;
                items.pop();
                if (!items.empty()) {
                    time[items.top()->func_id] -= elapsed;
                }
            }
        }
        return time;
    }

private:
    struct LogItem {
        int func_id;
        bool start;
        int timestamp;
        LogItem(const string &log) {
            auto pos = log.find(":");
            func_id = stoi(log.substr(0, pos));
            int begin = pos + 1;
            pos = log.find(":", begin);
            start = log.substr(begin, pos - begin) == "start";
            timestamp = stoi(log.substr(pos + 1));
        }
    };
};
// @lc code=end

