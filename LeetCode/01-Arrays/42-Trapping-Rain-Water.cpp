/**
 * 42. Trapping Rain Water
 * Difficulty: Hard
 * Link: https://leetcode.com/problems/trapping-rain-water/
 *
 * Problem:
 * Given n non-negative integers representing an elevation map where the
 * width of each bar is 1, compute how much water can be trapped after raining.
 *
 * Example 1:
 * Input:  height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 *
 * Example 2:
 * Input:  height = [4,2,0,3,2,5]
 * Output: 9
 *
 * Technique:
 * Two Pointers — Left/Right Maximum
 *
 * Key Idea:
 * Water trapped at a position depends on the smaller of the maximum
 * heights on its left and right:
 *
 *     water = min(leftMax, rightMax) - height[i]
 *
 * Instead of storing separate prefix and suffix arrays, maintain:
 *
 * - leftMax  → maximum height seen from the left
 * - rightMax → maximum height seen from the right
 *
 * The side with the smaller maximum determines the amount of water
 * that can be calculated safely.
 *
 * Approach:
 * 1. Initialize left at the beginning of the array.
 * 2. Initialize right at the end of the array.
 * 3. Maintain leftMax and rightMax.
 * 4. Update both maximum heights.
 * 5. If leftMax < rightMax, calculate trapped water at left and move left.
 * 6. Otherwise, calculate trapped water at right and move right.
 * 7. Continue until the two pointers meet.
 *
 * Complexity:
 * Time: O(n)
 * Space: O(1)
 */

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;

        int leftMax = 0;
        int rightMax = 0;
        int trappedWater = 0;

        while (left < right) {
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);

            if (leftMax < rightMax) {
                trappedWater += leftMax - height[left];
                left++;
            }
            else {
                trappedWater += rightMax - height[right];
                right--;
            }
        }

        return trappedWater;
    }
};