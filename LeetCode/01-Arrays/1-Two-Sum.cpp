/**
 * 1. Two Sum
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/two-sum/
 *
 * Problem:
 * Given an array of integers nums and an integer target, return the
 * indices of the two numbers such that they add up to target.
 *
 * You may assume that each input has exactly one solution, and you may not
 * use the same element twice.
 * 
 * Example 1:
 * Input:  nums = [2,7,11,15], target = 9
 * Output: [0,1]
 *
 * Example 2:
 * Input:  nums = [3,2,4], target = 6
 * Output: [1,2]
 *
 * Example 3:
 * Input:  nums = [3,3], target = 6
 * Output: [0,1]
 *
 * Approach:
 * Use an unordered_map to store each number and its index while traversing the array.
 * For each number, calculate the complement needed to reach the target.
 * If the complement has already been seen, return its stored index along with the current index.
 * Otherwise, store the current number and its index in the map before moving to the next element.
 *
 * Complexity:
 * Time: O(n) average
 * Space: O(n)
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            if (seen.find(complement) != seen.end()) {
                return {seen[complement], i};
            }
            seen[nums[i]] = i;
        }

        return {};
    }
};