/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (52.83%)
 * Likes:    4655
 * Dislikes: 146
 * Total Accepted:    479K
 * Total Submissions: 906.5K
 * Testcase Example:  '[1,2,2]'
 *
 * Given an integer array nums that may contain duplicates, return all possible
 * subsets (the power set).
 * 
 * The solution set must not contain duplicate subsets. Return the solution in
 * any order.
 * 
 * 
 * Example 1:
 * Input: nums = [1,2,2]
 * Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
 * Example 2:
 * Input: nums = [0]
 * Output: [[],[0]]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result{{}};
        int start;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                start = 0;
            }
            for (int end = result.size(); start < end; start++) {
                auto instance = result[start];
                instance.push_back(nums[i]);
                result.push_back(instance);
            }
        }
        return result;
    }

    /*
    void subsetsWithDup(vector<int> &nums, vector<int> pass, int index, vector<vector<int>> &result) {
        if (index == nums.size()) {
            result.push_back(pass);
            return;
        }
        int next_index = index + 1;
        for (int i = index + 1; i < nums.size(); ++i) {
            if (nums[i] == nums[index]) {
                next_index = i + 1;
                continue;
            }
        }
        subsetsWithoutDup(nums, pass, next_index, result);
        for (int i = 0; i < next_index - index; i++) {
            pass.push_back(nums[index]);
            subsetsWithoutDup(nums, pass, next_index, result);
        }
    }
    */
};
// @lc code=end

