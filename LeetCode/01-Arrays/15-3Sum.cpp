/**
 * 15. 3Sum
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/3sum/
 *
 * Problem:
 * Given an integer array nums, return all the triplets
 * [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k,
 * and nums[i] + nums[j] + nums[k] == 0.
 *
 * Notice that the solution set must not contain duplicate triplets.
 *
 * Example 1:
 * Input:  nums = [-1,0,1,2,-1,-4]
 * Output: [[-1,-1,2],[-1,0,1]]
 *
 * Explanation:
 * nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
 * nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
 * nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
 *
 * The distinct triplets are [-1,0,1] and [-1,-1,2].
 *
 * Notice that the order of the output and the order of the triplets
 * does not matter.
 *
 * Example 2:
 * Input:  nums = [0,1,1]
 * Output: []
 *
 * Explanation:
 * The only possible triplet does not sum up to 0.
 *
 * Example 3:
 * Input:  nums = [0,0,0]
 * Output: [[0,0,0]]
 *
 * Explanation:
 * The only possible triplet sums up to 0.
 *
 * Technique:
 * Sorting + Two Pointers
 *
 * Key Idea:
 * Sort the array first.
 *
 * For each element nums[i], use two pointers:
 *
 * - left  = i + 1
 * - right = n - 1
 *
 * Calculate:
 *
 *     nums[i] + nums[left] + nums[right]
 *
 * - If sum < 0 → move left forward.
 * - If sum > 0 → move right backward.
 * - If sum == 0 → store the triplet and move both pointers.
 *
 * Skip duplicate values to avoid duplicate triplets.
 *
 * Approach:
 * 1. Sort the array.
 * 2. Iterate through the array using i.
 * 3. Skip duplicate values for i.
 * 4. Set left = i + 1 and right = n - 1.
 * 5. Move the two pointers based on the current sum.
 * 6. When the sum is 0, store the triplet.
 * 7. Skip duplicate values after finding a valid triplet.
 *
 * Complexity:
 * Time: O(n²)
 * Space: O(1) extra space, excluding the output.
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];

                if (currentSum < 0) {
                    left++;
                }
                else if (currentSum > 0) {
                    right--;
                }
                else {
                    result.push_back({nums[i], nums[left], nums[right]});

                    left++;
                    right--;

                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }

                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                }
            }
        }

        return result;
    }
};