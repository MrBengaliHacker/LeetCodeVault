/**
 * 26. Remove Duplicates from Sorted Array
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 *
 * Problem:
 * Given an integer array nums sorted in non-decreasing order, remove the
 * duplicates in-place such that each unique element appears only once.
 *
 * Return the number of unique elements k.
 *
 * The first k elements of nums should contain the unique elements in
 * sorted order.
 *
 * Example 1:
 * Input:  nums = [1,1,2]
 * Output: 2
 *
 * Explanation:
 * The first two elements of nums should be [1,2].
 * The remaining elements do not matter.
 *
 * Example 2:
 * Input:  nums = [0,0,1,1,1,2,2,3,3,4]
 * Output: 5
 *
 * Explanation:
 * The first five elements of nums should be [0,1,2,3,4].
 * The remaining elements do not matter.
 *
 *
 * Technique:
 * Two Pointers — Slow/Fast + In-Place
 *
 * Key Idea:
 * Use two pointers:
 *
 * 1. i — points to the last position containing a unique element.
 * 2. j — scans the array looking for the next unique element.
 *
 * Since the array is sorted, duplicates are next to each other.
 *
 * When nums[i] and nums[j] are different, nums[j] is a new unique
 * element. Move i forward and place nums[j] at nums[i].
 *
 * Approach:
 * Start i at index 0 and j at index 1.
 *
 * Traverse the array using j:
 *
 * - If nums[i] == nums[j], j moves forward because nums[j] is a duplicate.
 * - If nums[i] != nums[j], move i forward and copy nums[j] to nums[i].
 *
 * After the traversal, i points to the last unique element.
 * Therefore, the number of unique elements is i + 1.
 *
 * Example:
 * nums = [1,1,2,2,3]
 *
 * Initially:
 * i = 0, j = 1
 *
 * j = 1:
 * nums[0] == nums[1]
 * Duplicate → move j
 *
 * j = 2:
 * nums[0] != nums[2]
 * Move i to 1 and copy nums[2]:
 *
 * nums = [1,2,2,2,3]
 *
 * j = 3:
 * nums[1] == nums[3]
 * Duplicate → move j
 *
 * j = 4:
 * nums[1] != nums[4]
 * Move i to 2 and copy nums[4]:
 *
 * nums = [1,2,3,2,3]
 *
 * Final unique portion:
 * [1,2,3]
 *
 * i = 2
 * Return i + 1 = 3
 *
 * Complexity:
 * Time: O(n)
 * Space: O(1)
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;

        for (int j = 1; j < nums.size(); j++) {
            if (nums[i] != nums[j]) {
                i++;
                nums[i] = nums[j];
            }
        }

        return i + 1;
    }
};