/**
 * 169. Majority Element
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/majority-element/
 *
 * Problem:
 * Given an array nums of size n, return the majority element.
 *
 * The majority element is the element that appears more than n / 2 times.
 * You may assume that the majority element always exists in the array.
 *
 * Example 1:
 * Input:  nums = [3,2,3]
 * Output: 3
 *
 * Example 2:
 * Input:  nums = [2,2,1,1,1,2,2]
 * Output: 2
 *
 *
 * Technique:
 * Boyer-Moore Voting Algorithm
 *
 * Key Idea:
 * Treat the majority element as a candidate with a vote count.
 *
 * - If the current value is the same as the candidate, increase the count.
 * - If the current value is different, decrease the count.
 * - When the count becomes 0, choose the current value as the new candidate.
 *
 * Because the majority element appears more than n / 2 times, it cannot
 * be completely cancelled by all the other elements.
 *
 * Approach:
 * Maintain two variables:
 *
 * 1. ans  - the current candidate for the majority element.
 * 2. freq - the current vote balance of the candidate.
 *
 * Traverse the array using a range-based for loop.
 *
 * If freq becomes 0, choose the current value x as the new candidate.
 *
 * Then:
 *
 * - If x is the same as ans, increase freq.
 * - Otherwise, decrease freq.
 *
 * At the end, ans is the majority element.
 *
 * Example:
 * nums = [2,2,1,1,1,2,2]
 *
 * Initially:
 * ans = 0, freq = 0
 *
 * x = 2:
 * freq = 0 → ans = 2
 * 2 == 2 → freq = 1
 *
 * x = 2:
 * 2 == 2 → freq = 2
 *
 * x = 1:
 * 2 != 1 → freq = 1
 *
 * x = 1:
 * 2 != 1 → freq = 0
 *
 * x = 1:
 * freq = 0 → ans = 1
 * 1 == 1 → freq = 1
 *
 * x = 2:
 * 1 != 2 → freq = 0
 *
 * x = 2:
 * freq = 0 → ans = 2
 * 2 == 2 → freq = 1
 *
 * Final result = 2
 *
 * Complexity:
 * Time: O(n)
 * Space: O(1)
 */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq = 0, ans = 0;

        for (int x : nums) {
            if (freq == 0) ans = x;

            if (ans == x) freq++;
            else freq--;
        }

        return ans;
    }
};