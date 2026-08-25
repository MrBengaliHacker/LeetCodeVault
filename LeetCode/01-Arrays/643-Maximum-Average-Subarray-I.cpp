/**
 * 643. Maximum Average Subarray I
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/maximum-average-subarray-i/
 *
 * Problem:
 * Given an integer array nums consisting of n elements, and an integer k,
 * find a contiguous subarray whose length is equal to k that has the
 * maximum average value and return this value.
 *
 * Any answer with a calculation error less than 10^-5 will be accepted.
 *
 * Example 1:
 * Input:  nums = [1,12,-5,-6,50,3], k = 4
 * Output: 12.75000
 *
 * Explanation:
 * The subarray [12,-5,-6,50] has the maximum sum:
 *
 * 12 + (-5) + (-6) + 50 = 51
 * Maximum average = 51 / 4 = 12.75
 *
 * Example 2:
 * Input:  nums = [5], k = 1
 * Output: 5.00000
 *
 * Explanation:
 * The only subarray is [5], whose average is 5.
 *
 *
 * Technique:
 * Sliding Window — Fixed Size
 *
 * Key Idea:
 * Since every subarray must contain exactly k elements, maintain a
 * window of size k and calculate its sum.
 *
 * Instead of calculating the sum of every window from scratch, update
 * the current window by:
 *
 * - Adding the new element entering the window.
 * - Removing the old element leaving the window.
 *
 * This allows the sum of each new window to be updated in constant time,
 * instead of recalculating the entire window.
 *
 * Approach:
 * 1. Calculate the sum of the first k elements.
 * 2. Store it as the maximum window sum.
 * 3. Slide the window through the array.
 * 4. Add the new element:
 *
 *    windowSum += nums[i]
 *
 * 5. Remove the element that leaves the window:
 *
 *    windowSum -= nums[i - k]
 *
 * 6. Update the maximum window sum.
 * 7. Divide the maximum sum by k to get the maximum average.
 *
 * Example:
 * nums = [1,12,-5,-6,50,3], k = 4
 *
 * First window:
 *
 * [1,12,-5,-6]
 *
 * windowSum = 1 + 12 - 5 - 6 = 2
 * maxSum = 2
 *
 * Slide the window:
 *
 * [12,-5,-6,50]
 *
 * Add 50 and remove 1:
 *
 * windowSum = 2 + 50 - 1
 *            = 51
 *
 * maxSum = 51
 *
 * Slide again:
 *
 * [-5,-6,50,3]
 *
 * Add 3 and remove 12:
 *
 * windowSum = 51 + 3 - 12
 *            = 42
 *
 * maxSum remains 51.
 *
 * Final:
 * maximum average = 51 / 4 = 12.75
 *
 * Complexity:
 * Time: O(n)
 * Space: O(1)
 */

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int windowSum = 0;

        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }

        int maxSum = windowSum;

        for (int i = k; i < nums.size(); i++) {
            windowSum += nums[i];
            windowSum -= nums[i - k];

            maxSum = max(maxSum, windowSum);
        }

        return static_cast<double>(maxSum) / k;
    }
};