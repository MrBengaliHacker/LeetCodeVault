/**
 * 136. Single Number
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/single-number/
 *
 * Problem:
 * Given a non-empty array of integers nums, every element appears twice
 * except for one element. Find and return the element that appears only once.
 *
 * The solution must have:
 * - Linear runtime complexity: O(n)
 * - Constant extra space: O(1)
 *
 * Example 1:
 * Input:  nums = [2,2,1]
 * Output: 1
 *
 * Example 2:
 * Input:  nums = [4,1,2,1,2]
 * Output: 4
 *
 * Example 3:
 * Input:  nums = [1]
 * Output: 1
 *
 * Technique:
 * XOR
 *
 * Key Idea:
 * XOR has two important properties:
 *
 * 1. x ^ x = 0
 * 2. x ^ 0 = x
 *
 * Since every number except one appears exactly twice, the duplicate
 * numbers cancel each other out when XOR is applied to all elements.
 * The remaining value is the single number.
 *
 * Example:
 * nums = [4,1,2,1,2]
 *
 * 0 ^ 4 ^ 1 ^ 2 ^ 1 ^ 2
 *
 * = 4 ^ (1 ^ 1) ^ (2 ^ 2)
 *
 * = 4 ^ 0 ^ 0
 *
 * = 4
 *
 * Approach:
 * Start with result = 0 and XOR every element of the array with result.
 * Duplicate values cancel each other, leaving only the number that appears
 * once.
 *
 * Complexity:
 * Time: O(n)
 * Space: O(1)
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;

        for (int num : nums) {
            result ^= num;
        }

        return result;
    }
};