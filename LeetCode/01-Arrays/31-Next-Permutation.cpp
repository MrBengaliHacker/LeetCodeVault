/**
 * 31. Next Permutation
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/next-permutation/
 *
 * Problem:
 * Given an array of integers nums, find the next permutation of nums.
 *
 * The next permutation is the next lexicographically greater arrangement of the elements.
 *
 * If no greater permutation exists, rearrange the array into the lowest possible order.
 *
 * The modification must be done in-place using constant extra memory.
 *
 * Example 1:
 * Input:  nums = [1,2,3]
 * Output: [1,3,2]
 *
 * Example 2:
 * Input:  nums = [3,2,1]
 * Output: [1,2,3]
 *
 * Example 3:
 * Input:  nums = [1,1,5]
 * Output: [1,5,1]
 *
 *
 * Technique:
 * Array Manipulation — Pivot + Successor + Reversal
 *
 * Key Idea:
 * We need the smallest possible permutation that is greater than the
 * current permutation.
 *
 * To achieve this:
 *
 * 1. Find the rightmost position where the array can be increased.
 * 2. Find the smallest number greater than the pivot.
 * 3. Swap them.
 * 4. Reverse the suffix to make it as small as possible.
 *
 * We scan from the right because we want to change the rightmost possible
 * position, keeping as much of the original prefix unchanged as possible.
 *
 * Approach:
 * Start from the second-last element and move from right to left.
 *
 * Find the first index i such that:
 *
 * nums[i] < nums[i + 1]
 *
 * This is the pivot.
 *
 * The elements after i are in descending order, meaning that the suffix
 * is already the largest possible arrangement of those elements.
 *
 * If no pivot exists, the entire array is already in descending order.
 * Reverse the entire array to obtain the smallest permutation.
 *
 * Otherwise, search from the right for the first element greater than
 * nums[i]. This is the smallest number greater than the pivot.
 *
 * Swap the pivot and successor.
 *
 * Finally, reverse everything after the pivot to make the suffix as small
 * as possible.
 *
 * Example:
 * nums = [2,4,7,6,5,3]
 *
 * Find the pivot:
 *
 * 5 >= 3
 * 6 >= 5
 * 7 >= 6
 * 4 < 7
 *
 * Therefore:
 * pivot = 4
 *
 * Find the successor:
 *
 * 3 <= 4 → skip
 * 5 > 4  → successor found
 *
 * Swap 4 and 5:
 *
 * [2,4,7,6,5,3]
 * [2,5,7,6,4,3]
 *
 * Reverse the suffix after the pivot:
 *
 * [7,6,4,3] → [3,4,6,7]
 *
 * Final result:
 * [2,5,3,4,6,7]
 *
 * Complexity:
 * Time: O(n)
 * Space: O(1) extra space
 */

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int i = n - 2;

        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        if (i < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }

        int j = n - 1;

        while (nums[j] <= nums[i]) {
            j--;
        }

        swap(nums[i], nums[j]);

        reverse(nums.begin() + i + 1, nums.end());
    }
};