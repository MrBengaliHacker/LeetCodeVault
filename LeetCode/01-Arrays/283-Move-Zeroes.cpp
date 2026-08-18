/**
 * 283. Move Zeroes
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/move-zeroes/
 *
 * Problem:
 * Given an integer array nums, move all 0's to the end of it 
 * while maintaining the relative order of the non-zero elements.
 *
 * The operation must be performed in-place without making a copy of the array.
 *
 * Example 1:
 * Input:  nums = [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 *
 * Example 2:
 * Input:  nums = [0]
 * Output: [0]
 *
 *
 * Technique:
 * Two Pointers — Same Direction
 *
 * Key Idea:
 * Use two pointers:
 *
 * 1. right — scans every element in the array.
 * 2. left  — points to the position where the next non-zero element
 *            should be placed.
 *
 * Whenever right finds a non-zero element, swap it with the element
 * at left and move left forward.
 *
 * This moves all non-zero elements toward the beginning while preserving
 * their relative order. The zeroes naturally move toward the end.
 *
 * Approach:
 * Start both pointers at index 0.
 *
 * Traverse the array using right:
 *
 * - If nums[right] is 0, only move right forward.
 * - If nums[right] is non-zero, swap nums[left] and nums[right],
 *   then move left forward.
 *
 * Continue until right reaches the end of the array.
 *
 * Example:
 * nums = [0,1,0,3,12]
 *
 * Initially:
 * left = 0, right = 0
 *
 * right = 0:
 * nums[0] = 0 → do nothing
 *
 * right = 1:
 * nums[1] = 1 → swap nums[0] and nums[1]
 * nums = [1,0,0,3,12]
 * left = 1
 *
 * right = 2:
 * nums[2] = 0 → do nothing
 *
 * right = 3:
 * nums[3] = 3 → swap nums[1] and nums[3]
 * nums = [1,3,0,0,12]
 * left = 2
 *
 * right = 4:
 * nums[4] = 12 → swap nums[2] and nums[4]
 * nums = [1,3,12,0,0]
 * left = 3
 *
 * Final result = [1,3,12,0,0]
 *
 * Complexity:
 * Time: O(n)
 * Space: O(1)
 */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        int right = 0;

        while (right < nums.size()) {
            if (nums[right] != 0) {
                swap(nums[left], nums[right]);
                left++;
            }

            right++;
        }
    }
};