/**
 * 75. Sort Colors
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/sort-colors/
 *
 * Problem:
 * Given an array nums with n objects colored red, white, or blue,
 * sort them in-place so that objects of the same color are adjacent,
 * with the colors in the order red, white, and blue.
 *
 * We use the integers 0, 1, and 2 to represent red, white, and blue.
 *
 * You must solve this problem without using the library sort function.
 *
 * Example 1:
 * Input:  nums = [2,0,2,1,1,0]
 * Output: [0,0,1,1,2,2]
 *
 * Explanation:
 * The array contains two 0s, two 1s, and two 2s.
 * They are rearranged in the order 0, 1, 2.
 *
 * Example 2:
 * Input:  nums = [2,0,1]
 * Output: [0,1,2]
 *
 * Explanation:
 * The three colors are rearranged in ascending order.
 *
 *
 * Technique:
 * Array Manipulation — Dutch National Flag Algorithm (3 Pointers)
 *
 * Key Idea:
 * Divide the array into three regions:
 *
 * [0s] [1s] [unknown] [2s]
 *
 * Use three pointers:
 *
 * 1. low  — position where the next 0 should be placed.
 * 2. mid  — current element being examined.
 * 3. high — position where the next 2 should be placed.
 *
 * When nums[mid] is:
 *
 * - 0 → swap it with nums[low], then move low and mid forward.
 * - 1 → it is already in the correct middle region, so move mid forward.
 * - 2 → swap it with nums[high], then move high backward.
 *
 * We do not move mid after placing a 2 because the element
 * coming from nums[high] has not been examined yet.
 *
 * Approach:
 * Start with:
 *
 * low = 0
 * mid = 0
 * high = n - 1
 *
 * While mid <= high:
 *
 * - If nums[mid] == 0:
 *   Swap nums[mid] and nums[low].
 *   Move low and mid forward.
 *
 * - If nums[mid] == 1:
 *   Move mid forward.
 *
 * - If nums[mid] == 2:
 *   Swap nums[mid] and nums[high].
 *   Move high backward.
 *   Do not move mid yet because the swapped element still needs to be checked.
 *
 * Example:
 * nums = [2,0,2,1,1,0]
 *
 * Initially:
 * low = 0, mid = 0, high = 5
 *
 * Step 1:
 * nums[mid] = 2
 * Swap nums[mid] with nums[high].
 *
 * [0,0,2,1,1,2]
 *
 * high = 4
 * mid stays at 0 because the swapped element must be checked.
 *
 * Step 2:
 * nums[mid] = 0
 * Swap nums[mid] with nums[low].
 *
 * [0,0,2,1,1,2]
 *
 * low = 1, mid = 1
 *
 * Step 3:
 * nums[mid] = 0
 * Swap nums[mid] with nums[low].
 *
 * [0,0,2,1,1,2]
 *
 * low = 2, mid = 2
 *
 * Step 4:
 * nums[mid] = 2
 * Swap nums[mid] with nums[high].
 *
 * [0,0,1,1,2,2]
 *
 * high = 3
 * mid stays at 2.
 *
 * Step 5:
 * nums[mid] = 1
 * It belongs in the middle region.
 *
 * mid = 3
 *
 * Step 6:
 * nums[mid] = 1
 * It belongs in the middle region.
 *
 * mid = 4
 *
 * Now mid > high, so the process stops.
 *
 * Final result:
 * [0,0,1,1,2,2]
 *
 * 
 * Complexity:
 * Time: O(n)
 * Space: O(1)
 */

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1) {
                mid++;
            }
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};