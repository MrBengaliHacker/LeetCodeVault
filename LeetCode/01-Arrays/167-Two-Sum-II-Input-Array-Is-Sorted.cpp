/**
 * 167. Two Sum II - Input Array Is Sorted
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
 *
 * Problem:
 * Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, 
 * find two numbers such that they add up to a specific target number.
 *
 * Return the indices of the two numbers, where the indices are 1-indexed.
 *
 * Example 1:
 * Input:  numbers = [2,7,11,15], target = 9
 * Output: [1,2]
 *
 * Explanation:
 * 2 + 7 = 9, so we return [1,2].
 *
 * Example 2:
 * Input:  numbers = [2,3,4], target = 6
 * Output: [1,3]
 *
 * Explanation:
 * 2 + 4 = 6, so we return [1,3].
 *
 * Example 3:
 * Input:  numbers = [-1,0], target = -1
 * Output: [1,2]
 *
 * Explanation:
 * -1 + 0 = -1, so we return [1,2].
 *
 *
 * Technique:
 * Two Pointers — Opposite Ends
 *
 * Key Idea:
 * Since the array is sorted, use two pointers:
 *
 * 1. start — begins at the first element.
 * 2. end   — begins at the last element.
 *
 * Compare the sum of numbers[start] and numbers[end] with the target.
 *
 * - If the sum is equal to target, we found the answer.
 * - If the sum is greater than target, move end left to reduce the sum.
 * - If the sum is less than target, move start right to increase the sum.
 *
 * Approach:
 * Start with start at index 0 and end at the last index.
 *
 * While start is less than end:
 *
 * 1. Calculate the current sum.
 * 2. If the sum equals target, return the 1-indexed positions.
 * 3. If the sum is greater than target, decrease end.
 * 4. If the sum is less than target, increase start.
 *
 * Because the array is sorted, each pointer movement eliminates
 * impossible pairs without checking them individually.
 *
 * Example:
 * numbers = [2,7,11,15], target = 9
 *
 * start = 0, end = 3
 * 2 + 15 = 17 > 9 → move end
 *
 * start = 0, end = 2
 * 2 + 11 = 13 > 9 → move end
 *
 * start = 0, end = 1
 * 2 + 7 = 9 → found
 *
 * Return [1,2]
 *
 * Complexity:
 * Time: O(n)
 * Space: O(1)
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0;
        int end = numbers.size() - 1;

        while (start < end) {
            int sum = numbers[start] + numbers[end];

            if (sum == target) {
                return {start + 1, end + 1};
            }
            else if (sum > target) {
                end--;
            }
            else {
                start++;
            }
        }

        return {};
    }
};