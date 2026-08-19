/**
 * 88. Merge Sorted Array
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/merge-sorted-array/
 *
 * Problem:
 * Given two integer arrays nums1 and nums2, sorted in non-decreasing order,
 * merge nums2 into nums1 so that nums1 becomes sorted.
 *
 * nums1 has enough space to hold all elements from both arrays.
 *
 * Example 1:
 * Input:  nums1 = [1,2,3,0,0,0], m = 3
 *         nums2 = [2,5,6], n = 3
 * Output: [1,2,2,3,5,6]
 *
 * Explanation:
 * The arrays being merged are [1,2,3] and [2,5,6].
 * The merged result is [1,2,2,3,5,6].
 *
 * Example 2:
 * Input:  nums1 = [1], m = 1
 *         nums2 = [], n = 0
 * Output: [1]
 *
 * Explanation:
 * nums2 is empty, so nums1 remains unchanged.
 *
 * Example 3:
 * Input:  nums1 = [0], m = 0
 *         nums2 = [1], n = 1
 * Output: [1]
 *
 * Explanation:
 * nums1 has no actual elements. The 0 only provides space for the merge.
 *
 *
 * Technique:
 * In-Place Merge — Three Pointers
 *
 * Key Idea:
 * Use three pointers starting from the end:
 *
 * 1. i — points to the last actual element in nums1.
 * 2. j — points to the last element in nums2.
 * 3. k — points to the last position in nums1.
 *
 * Compare nums1[i] and nums2[j].
 * Place the larger element at nums1[k].
 *
 * Since we fill nums1 from the end, we do not overwrite any
 * unprocessed elements.
 *
 * Approach:
 * Start:
 *
 * i = m - 1
 * j = n - 1
 * k = m + n - 1
 *
 * While j >= 0:
 *
 * - If nums1[i] is greater than nums2[j], place nums1[i] at nums1[k]
 *   and move i backward.
 * - Otherwise, place nums2[j] at nums1[k] and move j backward.
 * - Move k backward after every placement.
 *
 * The condition i >= 0 is necessary because all actual elements
 * from nums1 may already have been placed.
 *
 * Example:
 * nums1 = [1,2,3,0,0,0]
 * nums2 = [2,5,6]
 *
 * Initially:
 * i = 2, j = 2, k = 5
 *
 * 3 > 6 → false
 * Place 6 at nums1[5]
 *
 * nums1 = [1,2,3,0,0,6]
 *
 * 3 > 5 → false
 * Place 5 at nums1[4]
 *
 * nums1 = [1,2,3,0,5,6]
 *
 * 3 > 2 → true
 * Place 3 at nums1[3]
 *
 * nums1 = [1,2,3,3,5,6]
 *
 * 2 > 2 → false
 * Place 2 from nums2 at nums1[2]
 *
 * nums1 = [1,2,2,3,5,6]
 *
 * Continue until all elements from nums2 are placed.
 *
 * Final result = [1,2,2,3,5,6]
 *
 * Complexity:
 * Time: O(m + n)
 * Space: O(1)
 */

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            }
            else {
                nums1[k] = nums2[j];
                j--;
            }

            k--;
        }
    }
};