/**
 * 724. Find Pivot Index
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/find-pivot-index/
 *
 * Problem:
 * Given an array of integers nums, calculate the pivot index of the array.
 *
 * The pivot index is the index where the sum of the numbers strictly to
 * the left of the index is equal to the sum of the numbers strictly to
 * the index's right.
 *
 * If the index is on the left edge of the array, the left sum is 0.
 * If the index is on the right edge of the array, the right sum is 0.
 *
 * Return the leftmost pivot index. If no such index exists, return -1.
 *
 * Example 1:
 * Input:  nums = [1,7,3,6,5,6]
 * Output: 3
 *
 * Explanation:
 * Left sum = 1 + 7 + 3 = 11
 * Right sum = 5 + 6 = 11
 *
 * Therefore, index 3 is the pivot index.
 *
 * Example 2:
 * Input:  nums = [1,2,3]
 * Output: -1
 *
 * Explanation:
 * There is no index where the left sum is equal to the right sum.
 *
 * Example 3:
 * Input:  nums = [2,1,-1]
 * Output: 0
 *
 * Explanation:
 * Left sum = 0
 * Right sum = 1 + (-1) = 0
 *
 * Therefore, index 0 is the pivot index.
 *
 *
 * Technique:
 * Prefix Sum — Total Sum + Running Left Sum
 *
 * Key Idea:
 * First calculate the total sum of the array.
 *
 * For every index i:
 *
 *     rightSum = totalSum - leftSum - nums[i]
 *
 * The expression totalSum - leftSum - nums[i] represents the sum of all
 * elements to the right of index i.
 *
 * If:
 *
 *     leftSum == rightSum
 *
 * then i is the pivot index.
 *
 * After checking the current index, add nums[i] to leftSum before moving
 * to the next index.
 *
 * This avoids calculating the left and right sums separately for every
 * index.
 *
 * Approach:
 * 1. Calculate the total sum of the array.
 * 2. Start leftSum with 0.
 * 3. Traverse the array.
 * 4. Calculate the right sum using:
 *
 *    rightSum = totalSum - leftSum - nums[i]
 *
 * 5. If leftSum equals rightSum, return the current index.
 * 6. Add nums[i] to leftSum.
 * 7. If no pivot exists, return -1.
 *
 * Example:
 * nums = [1,7,3,6,5,6]
 *
 * totalSum = 28
 *
 * i = 0:
 * leftSum = 0
 * rightSum = 28 - 0 - 1 = 27
 *
 * i = 1:
 * leftSum = 1
 * rightSum = 28 - 1 - 7 = 20
 *
 * i = 2:
 * leftSum = 8
 * rightSum = 28 - 8 - 3 = 17
 *
 * i = 3:
 * leftSum = 11
 * rightSum = 28 - 11 - 6 = 11
 *
 * leftSum == rightSum
 *
 * Therefore, pivot index = 3.
 *
 * Complexity:
 * Time: O(n)
 * Space: O(1)
 */

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (leftSum == totalSum - leftSum - nums[i]) {
                return i;
            }

            leftSum += nums[i];
        }

        return -1;
    }
};