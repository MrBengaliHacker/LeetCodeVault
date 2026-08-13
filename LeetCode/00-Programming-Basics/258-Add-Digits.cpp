/**
 * 258. Add Digits
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/add-digits/
 *
 * Problem:
 * Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.
 *
 * Example 1:
 * Input:  num = 38
 * Output: 2
 *
 * Example 2:
 * Input:  num = 0
 * Output: 0
 *
 * Approach:
 * Repeatedly extract each digit using modulo 10 and add it to sum.
 * Continue until num becomes a single digit.
 *
 * Complexity:
 * Time: O(log n)
 * Space: O(1)
 */

class Solution {
public:
    int addDigits(int num) {
        while (num >= 10) {
            int sum = 0;

            while (num > 0) {
                int ld = num % 10;
                num /= 10;
                sum += ld;
            }

            num = sum;
        }

        return num;
    }
};