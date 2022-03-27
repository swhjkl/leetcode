/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 *
 * https://leetcode.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (36.33%)
 * Likes:    3480
 * Dislikes: 3066
 * Total Accepted:    979.9K
 * Total Submissions: 2.7M
 * Testcase Example:  '4'
 *
 * Given a non-negative integer x, compute and return the square root of x.
 * 
 * Since the return type is an integer, the decimal digits are truncated, and
 * only the integer part of the result is returned.
 * 
 * Note: You are not allowed to use any built-in exponent function or operator,
 * such as pow(x, 0.5) or x ** 0.5.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: x = 4
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: x = 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since the decimal part
 * is truncated, 2 is returned.
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= x <= 2^31 - 1
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        long min = 1;
        long max = x;
        long ans = min;
        do {
            long mid =  min + (max - min) / 2;
            long product = mid * mid;
            if (product == x) {
                return mid;
            } else if (product > x) {
                max = mid - 1; 
            } else {
                ans = min;
                min = mid + 1;
            }
        } while (min <= max);
        return max;
    }
};
// @lc code=end

