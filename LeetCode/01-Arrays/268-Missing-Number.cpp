/**
 * 268. Missing Number
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/missing-number/
 *
 * Problem:
 * Given an array nums containing n distinct numbers in the range [0, n],
 * return the only number in the range that is missing from the array.
 *
 * Example 1:
 * Input:  nums = [3,0,1]
 * Output: 2
 *
 * Explanation:
 * The numbers should be in the range [0,3].
 * The number 2 does not appear in nums, so 2 is the missing number.
 *
 * Example 2:
 * Input:  nums = [0,1]
 * Output: 2
 *
 * Explanation:
 * The numbers should be in the range [0,2].
 * The number 2 is missing from nums.
 *
 * Example 3:
 * Input:  nums = [9,6,4,2,3,5,7,0,1]
 * Output: 8
 * 
 * Explanation:
 * The numbers should be in the range [0,9].
 * The number 8 does not appear in nums, so 8 is the missing number.
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
 * Therefore, if we XOR all numbers from 0 to n together with all numbers
 * in nums, every number that appears in both groups cancels out.
 * The only number left is the missing number.
 *
 * Approach:
 * Start with n because the complete range contains numbers from 0 to n.
 * Then traverse the array and XOR each nums[i] with i.
 *
 * Since every number except the missing number appears twice in the XOR
 * operation, the duplicate values cancel each other out and the missing
 * number remains.
 *
 * Example:
 * nums = [3,0,1], n = 3
 *
 * Initial:
 * result = 3
 *
 * i = 0:
 * result = 3 ^ nums[0] ^ 0
 *        = 3 ^ 3 ^ 0
 *        = 0
 *
 * i = 1:
 * result = 0 ^ nums[1] ^ 1
 *        = 0 ^ 0 ^ 1
 *        = 1
 *
 * i = 2:
 * result = 1 ^ nums[2] ^ 2
 *        = 1 ^ 1 ^ 2
 *        = 2
 *
 * Final result = 2 → the missing number is 2.
 *
 * Complexity:
 * Time: O(n)
 * Space: O(1)
 */

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int missingNumber = n;

        for (int i = 0; i < n; i++) {
            missingNumber ^= nums[i] ^ i;
        }

        return missingNumber;
    }
};