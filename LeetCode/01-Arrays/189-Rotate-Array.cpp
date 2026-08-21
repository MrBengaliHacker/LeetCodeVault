/**
 * 189. Rotate Array
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/rotate-array/
 *
 * Problem:
 * Given an integer array nums, rotate the array to the right by k steps,
 * where k is non-negative.
 *
 * Example 1:
 * Input:  nums = [1,2,3,4,5,6,7], k = 3
 * Output: [5,6,7,1,2,3,4]
 *
 * Explanation:
 * Rotate 1 step to the right:
 * [7,1,2,3,4,5,6]
 *
 * Rotate 2 steps to the right:
 * [6,7,1,2,3,4,5]
 *
 * Rotate 3 steps to the right:
 * [5,6,7,1,2,3,4]
 *
 * Example 2:
 * Input:  nums = [-1,-100,3,99], k = 2
 * Output: [3,99,-1,-100]
 *
 * Explanation:
 * Rotate 1 step to the right:
 * [99,-1,-100,3]
 *
 * Rotate 2 steps to the right:
 * [3,99,-1,-100]
 *
 *
 * Technique:
 * Array Manipulation — Reversal Algorithm (In-Place)
 *
 * Key Idea:
 * To rotate the array to the right by k positions, divide the array into
 * two parts:
 *
 * [first part] [last k elements]
 *
 * We can achieve the rotation using three reversals:
 *
 * 1. Reverse the entire array.
 * 2. Reverse the first k elements.
 * 3. Reverse the remaining elements.
 *
 * This rearranges the elements into the required rotated order without
 * using an extra array.
 *
 * Approach:
 * First, calculate:
 *
 * k = k % n
 *
 * because rotating an array n times brings it back to its original state.
 *
 * Then perform three reversals:
 *
 * 1. Reverse the entire array.
 * 2. Reverse the first k elements.
 * 3. Reverse the elements from index k to the end.
 *
 * Example:
 * nums = [1,2,3,4,5,6,7], k = 3
 *
 * Step 1: Reverse the entire array.
 *
 * [7,6,5,4,3,2,1]
 *
 * Step 2: Reverse the first k = 3 elements.
 *
 * [5,6,7 | 4,3,2,1]
 *
 * Step 3: Reverse the remaining elements from index k.
 *
 * [5,6,7 | 1,2,3,4]
 *
 * Final result:
 * [5,6,7,1,2,3,4]
 *
 * Complexity:
 * Time: O(n)
 * Space: O(1) extra space
 */

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        k = k % n;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};