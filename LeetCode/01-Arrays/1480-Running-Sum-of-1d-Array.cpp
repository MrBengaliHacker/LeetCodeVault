/**
 * 1480. Running Sum of 1d Array
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/running-sum-of-1d-array/
 *
 * Problem:
 * Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).
 * Return the running sum of nums.
 *
 * Example 1:
 * Input:  nums = [1,2,3,4]
 * Output: [1,3,6,10]
 *
 * Example 2:
 * Input:  nums = [1,1,1,1,1]
 * Output: [1,2,3,4,5]
 *
 * Example 3:
 * Input:  nums = [3,1,2,10,1]
 * Output: [3,4,6,16,17]
 *
 * Approach:
 * Traverse the array, maintain a running sum, and store each sum in the result vector.
 *
 * Complexity:
 * Time: O(n)
 * Space: O(n)
 */

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> result;
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            result.push_back(sum);
        }

        return result;
    }
};