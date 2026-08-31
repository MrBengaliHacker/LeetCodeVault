/**
 * 41. First Missing Positive
 *
 * Difficulty: Hard
 *
 * Link:
 * https://leetcode.com/problems/first-missing-positive/
 *
 * Problem:
 * Given an unsorted integer array nums, return the smallest positive
 * integer that is not present in nums.
 *
 * You must implement an algorithm that runs in O(n) time and uses
 * O(1) auxiliary space.
 *
 * Example 1:
 * Input:  nums = [1,2,0]
 * Output: 3
 *
 * Explanation:
 * The numbers 1 and 2 are present, so the smallest missing
 * positive integer is 3.
 *
 * Example 2:
 * Input:  nums = [3,4,-1,1]
 * Output: 2
 *
 * Explanation:
 * 1 is present, but 2 is missing.
 *
 * Example 3:
 * Input:  nums = [7,8,9,11,12]
 * Output: 1
 *
 * Explanation:
 * The smallest positive integer 1 is missing.
 *
 * Technique:
 * In-Place Index Mapping / Cyclic Placement
 *
 * Key Idea:
 * For an array of size n, the answer must be between 1 and n + 1.
 *
 * Put each valid number into its correct index:
 *
 *     1 → index 0
 *     2 → index 1
 *     3 → index 2
 *     x → index x - 1
 *
 * Ignore numbers smaller than 1 or greater than n.
 *
 * After arranging, the first index i where nums[i] != i + 1
 * gives the smallest missing positive number.
 *
 * Approach:
 * 1. Traverse the array.
 * 2. Place each valid number at index nums[i] - 1.
 * 3. Ignore invalid numbers and duplicates.
 * 4. Traverse the array again.
 * 5. If nums[i] != i + 1, return i + 1.
 * 6. If every position is correct, return n + 1.
 *
 * Dry Run:
 * nums = [3,4,-1,1]
 *
 * After placing numbers:
 * [1,-1,3,4]
 *
 * Check positions:
 *
 * index 0 → expected 1 → correct
 * index 1 → expected 2 → missing
 *
 * Answer = 2
 *
 * Complexity:
 * Time: O(n)
 * Space: O(1)
 */

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            while (nums[i] >= 1 &&
                   nums[i] <= n &&
                   nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        return n + 1;
    }
};