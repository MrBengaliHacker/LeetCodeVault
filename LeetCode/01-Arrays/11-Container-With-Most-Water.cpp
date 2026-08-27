/**
 * 11. Container With Most Water
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/container-with-most-water/
 *
 * Problem:
 * You are given an integer array height where height[i] represents the
 * height of a vertical line at index i.
 *
 * Find two lines that, together with the x-axis, form a container that
 * holds the most water.
 *
 * The container must be formed using two different lines, and the lines
 * cannot be tilted.
 *
 * Example 1:
 * Input:  height = [1,8,6,2,5,4,8,3,7]
 * Output: 49
 *
 * Explanation:
 * The lines at indices 1 and 8 form the container:
 *
 * width = 8 - 1 = 7
 * height = min(8, 7) = 7
 * area = 7 * 7 = 49
 *
 * Example 2:
 * Input:  height = [1,1]
 * Output: 1
 *
 * Technique:
 * Two Pointers — Opposite Direction
 *
 * Key Idea:
 * The area formed by two lines is:
 *
 *     area = width × minimum height
 *
 * Start with two pointers at both ends of the array.
 *
 * At every step:
 * - Calculate the current container area.
 * - Update the maximum area.
 * - Move the pointer with the smaller height.
 *
 * We move the smaller-height pointer because the current container height
 * is limited by the shorter line. Moving the taller pointer cannot
 * increase the height limit, while also reducing the width.
 *
 * Approach:
 * 1. Initialize left at the beginning of the array.
 * 2. Initialize right at the end of the array.
 * 3. Calculate the width between the two pointers.
 * 4. Find the smaller of the two heights.
 * 5. Calculate the current area.
 * 6. Update the maximum area.
 * 7. Move the pointer with the smaller height inward.
 * 8. Continue until left and right meet.
 *
 * Example:
 * height = [1,8,6,2,5,4,8,3,7]
 *
 * Initially:
 * left = 0
 * right = 8
 *
 * Step 1:
 * height[left] = 1
 * height[right] = 7
 *
 * width = 8 - 0 = 8
 * containerHeight = min(1, 7) = 1
 * area = 8 × 1 = 8
 *
 * Since the left height is smaller:
 * left++
 *
 * Step 2:
 * left = 1
 * right = 8
 *
 * width = 8 - 1 = 7
 * containerHeight = min(8, 7) = 7
 * area = 7 × 7 = 49
 *
 * maxArea = 49
 *
 * Since the right height is smaller:
 * right--
 *
 * Continue moving the smaller-height pointer and checking each
 * possible useful container.
 *
 * The maximum area found is 49.
 *
 * Complexity:
 * Time: O(n)
 * Space: O(1)
 */

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;

        while (left < right) {
            int width = right - left;
            int containerHeight = min(height[left], height[right]);
            int currentArea = width * containerHeight;

            maxArea = max(maxArea, currentArea);

            if (height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }

        return maxArea;
    }
};