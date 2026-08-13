/**
 * 1342. Number of Steps to Reduce a Number to Zero
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/
 *
 * Problem:
 * Given an integer num, return the number of steps to reduce it to zero.
 * 
 * In one step, if the current number is even, you have to divide it by 2, otherwise, you have to subtract 1 from it.
 *
 * Example 1:
 * Input:  num = 14
 * Output: 6
 *
 * Example 2:
 * Input:  num = 8
 * Output: 4
 *
 * Example 3:
 * Input:  num = 123
 * Output: 12
 *
 * Approach:
 * Repeatedly check whether num is even or odd.
 * Divide even values by 2 and subtract 1 from odd values.
 * Count each operation until num becomes zero.
 *
 * Complexity:
 * Time: O(log n)
 * Space: O(1)
 */

class Solution {
public:
    int numberOfSteps(int num) {
        int steps = 0;

        while (num > 0) {
            if (num % 2 == 0) {
                num /= 2;
            }
            else {
                num--;
            }

            steps++;
        }

        return steps;
    }
};