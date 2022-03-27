/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (70.88%)
 * Likes:    9436
 * Dislikes: 150
 * Total Accepted:    1M
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,2,3]'
 *
 * Given an integer array nums of unique elements, return all possible subsets
 * (the power set).
 * 
 * The solution set must not contain duplicate subsets. Return the solution in
 * any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [0]
 * Output: [[],[0]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 * All the numbers of nums are unique.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result{{}};
        for (int i = 0; i < nums.size(); ++i) {
            for (int start = 0, end = result.size(); start < end; ++start) {
                auto add_curr = result[start];
                add_curr.push_back(nums[i]);
                result.push_back(add_curr);
            }
        }
        return result;
    }
};
// @lc code=end

