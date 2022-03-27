/*
 * @lc app=leetcode id=670 lang=cpp
 *
 * [670] Maximum Swap
 */

// @lc code=start
class Solution {
public:
    int maximumSwap(int num) {
        auto str = to_string(num);
        int max_index = -1;
        int max_digit = -1;
        int left_index = -1;
        int right_index = -1;
        for (int i = str.size() - 1; i >= 0; i--) {
            if (str[i] > max_digit) {
                max_digit = str[i];
                max_index = i;
                continue;
            }

            if (str[i] < max_digit) {
                left_index = i;
                right_index = max_index;
            }
        }

        if (left_index == -1) {
            return num;
        }

        swap(str[left_index], str[right_index]);

        return stoi(str);
    }
};
// @lc code=end

