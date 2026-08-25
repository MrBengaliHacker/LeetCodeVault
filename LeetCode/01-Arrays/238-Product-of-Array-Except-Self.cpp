/**
 * 238. Product of Array Except Self
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/product-of-array-except-self/
 *
 * Problem:
 * Given an integer array nums, return an array answer such that
 * answer[i] is equal to the product of all the elements of nums
 * except nums[i].
 *
 * The product of any prefix or suffix of nums is guaranteed to fit
 * in a 32-bit integer.
 *
 * You must write an algorithm that runs in O(n) time and without
 * using the division operation.
 *
 * Example 1:
 * Input:  nums = [1,2,3,4]
 * Output: [24,12,8,6]
 *
 * Example 2:
 * Input:  nums = [-1,1,0,-3,3]
 * Output: [0,0,9,0,0]
 *
 *
 * Technique:
 * Prefix/Suffix Product — Left Product + Right Product
 *
 * Key Idea:
 * For every index, the answer is:
 *
 *     product of all elements to the left
 *     ×
 *     product of all elements to the right
 *
 * First, use the answer array to store the product of all elements
 * to the left of each index.
 *
 * Then traverse from right to left and multiply each position by
 * the product of all elements to its right.
 *
 * This avoids using division and does not require a separate
 * prefix or suffix array.
 *
 * Approach:
 * 1. Create an answer array of the same size, initialized with 1.
 * 2. Traverse from left to right.
 * 3. Store the left product in answer[i].
 * 4. Traverse from right to left.
 * 5. Multiply answer[i] by the current right product.
 * 6. Update the right product by multiplying nums[i].
 * 7. Return answer.
 *
 * Example:
 * nums = [1,2,3,4]
 *
 * First pass — Left Products:
 *
 * leftProduct = 1
 *
 * i = 0:
 * answer[0] = 1
 * leftProduct = 1 × 1 = 1
 *
 * i = 1:
 * answer[1] = 1
 * leftProduct = 1 × 2 = 2
 *
 * i = 2:
 * answer[2] = 2
 * leftProduct = 2 × 3 = 6
 *
 * i = 3:
 * answer[3] = 6
 * leftProduct = 6 × 4 = 24
 *
 * After the first pass:
 *
 * answer = [1,1,2,6]
 *
 * Second pass — Right Products:
 *
 * rightProduct = 1
 *
 * i = 3:
 * answer[3] = 6 × 1 = 6
 * rightProduct = 1 × 4 = 4
 *
 * i = 2:
 * answer[2] = 2 × 4 = 8
 * rightProduct = 4 × 3 = 12
 *
 * i = 1:
 * answer[1] = 1 × 12 = 12
 * rightProduct = 12 × 2 = 24
 *
 * i = 0:
 * answer[0] = 1 × 24 = 24
 *
 * Final result:
 * answer = [24,12,8,6]
 *
 * Complexity:
 * Time: O(n)
 * Space: O(1) extra space
 *
 * Note:
 * The answer array is required as the output, so it is not counted
 * as extra space. Only constant auxiliary variables are used.
 */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer(nums.size(), 1);

        int leftProduct = 1;

        for (int i = 0; i < nums.size(); i++) {
            answer[i] = leftProduct;
            leftProduct *= nums[i];
        }

        int rightProduct = 1;

        for (int i = nums.size() - 1; i >= 0; i--) {
            answer[i] *= rightProduct;
            rightProduct *= nums[i];
        }

        return answer;
    }
};