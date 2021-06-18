/*
 * @lc app=leetcode id=273 lang=cpp
 *
 * [273] Integer to English Words
 */

// @lc code=start
class Solution {
public:
    string numberToWords(int num) {
        if (!num) {
            return "Zero";
        }
        vector<string> suffix{"", " Thousand", " Million", " Billion"};
        int suffix_index = 0;
        string ret;
        while (num) {
            int tail = num % 1000;
            auto tmp = lessThanThousandNumberToWords(tail);
            if (!tmp.empty()) {
                tmp += suffix[suffix_index];
            }
            suffix_index++;
            if (ret.empty()) {
                ret = tmp;
            } else if (!tmp.empty()) {
                ret = tmp + " " + ret;
            }
            num /= 1000;
        }
        return ret;
    }

private:
    string lessThanThousandNumberToWords(int num) {
        vector<string> single{"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
            "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> composite{"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        int hb = num / 100;
        num %= 100;
        vector<string> parts;
        if (hb) {
            parts.push_back(single[hb] + " Hundred");
        }
        if (num >= 20) {
            parts.push_back(composite[num / 10]);
            num %= 10;
        }
        if (num) {
            parts.push_back(single[num]);
        }

        string ret;
        for (auto &part: parts) {
            ret.append(part + " ");
        }
        if (!ret.empty()) {
            ret.pop_back();
        }
        return ret;
    }
};
// @lc code=end

