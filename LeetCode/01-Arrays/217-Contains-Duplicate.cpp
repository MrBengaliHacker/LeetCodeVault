/**
 * 217. Contains Duplicate
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/contains-duplicate/
 *
 * Problem:
 * Given an integer array nums, return true if any value appears at least
 * twice in the array, and return false if every element is distinct.
 *
 * Example 1:
 * Input:  nums = [1,2,3,1]
 * Output: true
 *
 * Example 2:
 * Input:  nums = [1,2,3,4]
 * Output: false
 *
 * Example 3:
 * Input:  nums = [1,1,1,3,3,4,3,2,4,2]
 * Output: true
 *
 * Approach:
 * Use an unordered_set to store the elements while traversing the array.
 * If an element is already present in the set, a duplicate exists.
 * Otherwise, insert the element and continue.
 *
 * Complexity:
 * Time: O(n) average
 * Space: O(n)
 */

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for (int x : nums) {
            if (!seen.insert(x).second) {
                return true;
            }
        }

        return false;
    }
};


/*
 * Alternative Approach 1 (sorting):
 *
 * Sort the array so that duplicate values become adjacent.
 * Then compare each element with the previous element.
 *
 * Complexity:
 * Time: O(n log n)
 * Space: O(1) auxiliary
 *
 * class Solution {
 * public:
 *     bool containsDuplicate(vector<int>& nums) {
 *         sort(nums.begin(), nums.end());
 *
 *         for (int i = 1; i < nums.size(); i++) {
 *             if (nums[i] == nums[i - 1]) return true;
 *         }
 *
 *         return false;
 *     }
 * };
 */