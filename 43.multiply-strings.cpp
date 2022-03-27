/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 *
 * https://leetcode.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (37.49%)
 * Likes:    4161
 * Dislikes: 1636
 * Total Accepted:    491.3K
 * Total Submissions: 1.3M
 * Testcase Example:  '"2"\n"3"'
 *
 * Given two non-negative integers num1 and num2 represented as strings, return
 * the product of num1 and num2, also represented as a string.
 * 
 * Note: You must not use any built-in BigInteger library or convert the inputs
 * to integer directly.
 * 
 * 
 * Example 1:
 * Input: num1 = "2", num2 = "3"
 * Output: "6"
 * Example 2:
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= num1.length, num2.length <= 200
 * num1 and num2 consist of digits only.
 * Both num1 and num2 do not contain any leading zero, except the number 0
 * itself.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) {
      string sum(num1.size() + num2.size(), '0');
      for (int i = num1.size() - 1; i >= 0; i--) {
        int carry = 0;
        for (int j = num2.size() - 1; j >= 0; j--) {
          carry += (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0');
          sum[i + j + 1] = carry % 10 + '0';
          carry /= 10;
        }
        sum[i] += carry;
      }

      auto pos = sum.find_first_not_of("0");
      return pos == string::npos ? "0" : sum.substr(pos);
    }
};
// @lc code=end

