/**
 * 1929. Concatenation of Array
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/concatenation-of-array/
 *
 * Problem:
 * Given an integer array nums of length n, return its concatenation with itself (length 2n).
 * 
 * Example 1:
 * Input:  nums = [1,2,1]
 * Output: [1,2,1,1,2,1]
 *
 * Example 2:
 * Input:  nums = [1,3,2,1]
 * Output: [1,3,2,1,1,3,2,1]
 *
 * Approach:
 * Directly assign each nums[i] to both ans[i] and ans[i+n] in a single pass.
 *
 * Complexity:
 * Time: O(n)
 * Space: O(n)
 */

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2 * n);

        for (int i = 0; i < n; i++) {
            ans[i] = ans[i + n] = nums[i];
        }

        return ans;
    }
};


/*
 * Alternative Approach 1 (modulo-based):
 *
 * vector<int> getConcatenation(vector<int>& nums) {
 *     int n = nums.size();
 *     vector<int> ans(2 * n);
 *
 *     for (int i = 0; i < 2 * n; i++) {
 *         ans[i] = nums[i % n];
 *     }
 *
 *     return ans;
 * }
 */


/*
 * Alternative Approach 2 (insert-based):
 *
 * vector<int> getConcatenation(vector<int>& nums) {
 *     vector<int> ans(nums);
 * 
 *     ans.insert(ans.end(), nums.begin(), nums.end());
 * 
 *     return ans;
 * }
 */