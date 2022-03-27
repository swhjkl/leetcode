/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 *
 * https://leetcode.com/problems/count-and-say/description/
 *
 * algorithms
 * Medium (48.38%)
 * Likes:    1292
 * Dislikes: 3336
 * Total Accepted:    605.8K
 * Total Submissions: 1.3M
 * Testcase Example:  '1'
 *
 * The count-and-say sequence is a sequence of digit strings defined by the
 * recursive formula:
 * 
 * 
 * countAndSay(1) = "1"
 * countAndSay(n) is the way you would "say" the digit string from
 * countAndSay(n-1), which is then converted into a different digit string.
 * 
 * 
 * To determine how you "say" a digit string, split it into the minimal number
 * of groups so that each group is a contiguous section all of the same
 * character. Then for each group, say the number of characters, then say the
 * character. To convert the saying into a digit string, replace the counts
 * with a number and concatenate every saying.
 * 
 * For example, the saying and conversion for digit string "3322251":
 * 
 * Given a positive integer n, return the n^th term of the count-and-say
 * sequence.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 1
 * Output: "1"
 * Explanation: This is the base case.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 4
 * Output: "1211"
 * Explanation:
 * countAndSay(1) = "1"
 * countAndSay(2) = say "1" = one 1 = "11"
 * countAndSay(3) = say "11" = two 1's = "21"
 * countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 30
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        string prev_str = countAndSay(n - 1);
        int count = 1;
        char prev_char = prev_str[0];
        string curr_str;
        for (size_t i = 1; i < prev_str.size(); i++) {
            if (prev_str[i] == prev_char) {
                count++;
            } else {
                curr_str.push_back(count + '0');
                curr_str.push_back(prev_char);
                prev_char = prev_str[i];
                count = 1;
            }
        }
        curr_str.push_back(count + '0');
        curr_str.push_back(prev_char);
        return curr_str;
    }
};
// @lc code=end

