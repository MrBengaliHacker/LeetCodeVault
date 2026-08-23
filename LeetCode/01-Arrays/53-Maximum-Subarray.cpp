/**
 * 53. Maximum Subarray
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/maximum-subarray/
 *
 * Problem:
 * Given an integer array nums, find the subarray with the largest sum
 * and return its sum.
 *
 * Example 1:
 * Input:  nums = [-2,1,-3,4,-1,2,1,-5,4]
 * Output: 6
 *
 * Explanation:
 * The subarray [4,-1,2,1] has the largest sum:
 * 4 + (-1) + 2 + 1 = 6
 *
 * Example 2:
 * Input:  nums = [1]
 * Output: 1
 *
 * Explanation:
 * The subarray [1] has the largest sum 1.
 *
 * Example 3:
 * Input:  nums = [5,4,-1,7,8]
 * Output: 23
 *
 * Explanation:
 * The subarray [5,4,-1,7,8] has the largest sum:
 * 5 + 4 + (-1) + 7 + 8 = 23
 *
 *
 * Technique:
 * Kadane's Algorithm
 *
 * Key Idea:
 * For every element, decide whether it is better to:
 *
 * 1. Start a new subarray from the current element.
 * 2. Extend the existing subarray by adding the current element.
 *
 * If the current subarray sum becomes negative, it cannot help any future
 * subarray produce a larger sum, so we reset it to 0.
 *
 * Approach:
 * Maintain two variables:
 *
 * 1. currentSum - the maximum sum of a subarray ending at the current
 *    position.
 * 2. maxSum - the maximum subarray sum found so far.
 *
 * For each element:
 *
 * - Add the element to currentSum.
 * - Update maxSum using currentSum.
 * - If currentSum becomes negative, reset it to 0.
 *
 * Example:
 * nums = [-2,1,-3,4,-1,2,1,-5,4]
 *
 * Start:
 * currentSum = 0
 * maxSum = INT_MIN
 *
 * -2:
 * currentSum = -2
 * maxSum = -2
 * currentSum < 0 → reset to 0
 *
 * 1:
 * currentSum = 1
 * maxSum = 1
 *
 * -3:
 * currentSum = -2
 * maxSum = 1
 * currentSum < 0 → reset to 0
 *
 * 4:
 * currentSum = 4
 * maxSum = 4
 *
 * -1:
 * currentSum = 3
 * maxSum = 4
 *
 * 2:
 * currentSum = 5
 * maxSum = 5
 *
 * 1:
 * currentSum = 6
 * maxSum = 6
 *
 * -5:
 * currentSum = 1
 * maxSum = 6
 *
 * 4:
 * currentSum = 5
 * maxSum = 6
 *
 * Final result = 6
 *
 * Complexity:
 * Time: O(n)
 * Space: O(1)
 */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = 0;
        int maxSum = INT_MIN;

        for (int x : nums) {
            currentSum += x;
            maxSum = max(currentSum, maxSum);

            if (currentSum < 0) {
                currentSum = 0;
            }
        }

        return maxSum;
    }
};