/**
 * 1470. Shuffle the Array
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/shuffle-the-array/
 *
 * Problem:
 * Given an array nums containing 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].
 * Return it in the form [x1,y1,x2,y2,...,xn,yn].
 *
 * Example 1:
 * Input:  nums = [2,5,1,3,4,7], n = 3
 * Output: [2,3,5,4,1,7]
 *
 * Example 2:
 * Input:  nums = [1,2,3,4,4,3,2,1], n = 4
 * Output: [1,4,2,3,3,2,4,1]
 *
 * Example 3:
 * Input:  nums = [1,1,2,2], n = 2
 * Output: [1,2,1,2]
 *
 * Approach:
 * Traverse the first n elements and place each pair nums[i] and nums[i+n]
 * at consecutive positions in the result array.
 *
 * Complexity:
 * Time: O(n)
 * Space: O(n)
 */

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2 * n);

        for (int i = 0; i < n; i++) {
            ans[2 * i] = nums[i];
            ans[2 * i + 1] = nums[i + n];
        }

        return ans;
    }
};