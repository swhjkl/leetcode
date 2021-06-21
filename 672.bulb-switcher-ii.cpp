/*
 * @lc app=leetcode id=672 lang=cpp
 *
 * [672] Bulb Switcher II
 */

// @lc code=start
class Solution {
public:
    int flipLights(int n, int presses) {
        if (n > 3) {
            n = 3;
        }
        switch (presses) {
        case 0:
            return 1;
        case 1:
            return n + 1;
        case 2:
            switch(n) {
            case 1:
                return 2;
            case 2:
                return 4;
            case 3:
                return 7;
            }
        default:
            switch (n) {
            case 1:
                return 2;
            case 2:
                return 4;
            default:
                return 8;
            }
        }
    }
};
// @lc code=end

