/**
 * 704. Binary Search
 *
 * Difficulty: Easy
 *
 * Link:
 * https://leetcode.com/problems/binary-search/
 *
 * Problem:
 * Given a sorted array of integers nums and an integer target,
 * return the index of target if it exists. Otherwise, return -1.
 *
 * Example 1:
 * Input:  nums = [-1,0,3,5,9,12], target = 9
 * Output: 4
 *
 * Explanation:
 * 9 exists in nums and its index is 4.
 *
 * Example 2:
 * Input:  nums = [-1,0,3,5,9,12], target = 2
 * Output: -1
 *
 * Explanation:
 * 2 does not exist in nums.
 *
 * Technique:
 * Binary Search
 *
 * Key Idea:
 * Since the array is sorted, eliminate half of the search space
 * after every comparison.
 *
 * If nums[mid] < target:
 *     Search the right half.
 *
 * If nums[mid] > target:
 *     Search the left half.
 *
 * If nums[mid] == target:
 *     Target found.
 *
 * Approach:
 * 1. Set low = 0 and high = n - 1.
 * 2. Find the middle index.
 * 3. Compare nums[mid] with target.
 * 4. Eliminate the half that cannot contain the target.
 * 5. Continue while low <= high.
 * 6. Return -1 if the target is not found.
 *
 * Dry Run:
 * nums = [-1,0,3,5,9,12], target = 9
 *
 * low = 0, high = 5
 * mid = 2 → nums[2] = 3
 * 3 < 9 → search right half
 *
 * low = 3, high = 5
 * mid = 4 → nums[4] = 9
 * 9 == 9 → found
 *
 * Final answer = 4
 *
 * Complexity:
 * Time: O(log n)
 * Space: O(1)
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return -1;
    }
};