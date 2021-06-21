/*
 * @lc app=leetcode id=365 lang=cpp
 *
 * [365] Water and Jug Problem
 */

// @lc code=start
class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        return jug1Capacity + jug2Capacity >= targetCapacity &&
            targetCapacity % gcd(jug1Capacity, jug2Capacity) == 0;
    }

private:
    int gcd(int x, int y) {
        return x == 0 ? y : gcd(y % x, x);
    }
};
// @lc code=end

