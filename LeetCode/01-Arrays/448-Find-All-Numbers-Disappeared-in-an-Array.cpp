/**
 * 448. Find All Numbers Disappeared in an Array
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
 *
 * Problem:
 * Given an array nums of n integers where nums[i] is in the range [1, n],
 * return an array of all the integers in the range [1, n] that do not appear in nums.
 *
 * Example 1:
 * Input:  nums = [4,3,2,7,8,2,3,1]
 * Output: [5,6]
 *
 * Explanation:
 * The numbers from 1 to 8 are:
 * [1,2,3,4,5,6,7,8]
 *
 * The numbers 1,2,3,4,7,8 appear in nums.
 * Therefore, 5 and 6 are missing.
 *
 * Example 2:
 * Input:  nums = [1,1]
 * Output: [2]
 *
 * Explanation:
 * The numbers from 1 to 2 are:
 * [1,2]
 *
 * 1 appears in nums, but 2 does not.
 *
 * 
 * Technique:
 * In-Place Marking
 *
 * Key Idea:
 * Every number x in nums corresponds to the index x - 1.
 *
 * Since the values are guaranteed to be in the range [1, n], we can use
 * the array itself as a marker.
 *
 * When we see a number x, mark index x - 1 as negative.
 * A negative value means that the corresponding number exists in the array.
 *
 * After marking:
 * - nums[i] > 0 → number i + 1 is missing.
 * - nums[i] < 0 → number i + 1 exists.
 *
 * Approach:
 * 1. Traverse the array.
 * 2. For each value x, calculate index = x - 1.
 * 3. Make nums[index] negative to mark that x exists.
 * 4. Traverse the array again.
 * 5. If nums[i] is still positive, i + 1 is missing.
 *
 * Example:
 * nums = [4,3,2,7,8,2,3,1]
 *
 * Marking the values makes the corresponding positions negative.
 *
 * After marking:
 * nums = [-4,-3,-2,-7,8,2,-3,-1]
 *
 * Now check each position:
 *
 * i = 0 → nums[0] < 0 → 1 exists
 * i = 1 → nums[1] < 0 → 2 exists
 * i = 2 → nums[2] < 0 → 3 exists
 * i = 3 → nums[3] < 0 → 4 exists
 * i = 4 → nums[4] > 0 → 5 is missing
 * i = 5 → nums[5] > 0 → 6 is missing
 * i = 6 → nums[6] < 0 → 7 exists
 * i = 7 → nums[7] < 0 → 8 exists
 *
 * Final result = [5,6]
 *
 * Complexity:
 * Time: O(n)
 * Space: O(1) extra space
 *
 * Note:
 * The returned result does not count as extra space according to the
 * problem's requirement.
 */

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int x = abs(nums[i]);
            int index = x - 1;

            nums[index] = -abs(nums[index]);
        }

        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                result.push_back(i + 1);
            }
        }

        return result;
    }
};