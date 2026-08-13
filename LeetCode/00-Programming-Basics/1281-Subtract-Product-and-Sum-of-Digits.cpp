/**
 * 1281. Subtract the Product and Sum of Digits of an Integer
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/
 *
 * Problem:
 * Given an integer n, return the difference between the product of its digits
 * and the sum of its digits.
 *
 * Example 1:
 * Input:  n = 234
 * Output: 15
 *
 * Example 2:
 * Input:  n = 4421
 * Output: 21
 *
 * Approach:
 * Extract each digit using modulo 10. Add the digit to the sum and multiply
 * it into the product, then divide n by 10 to process the next digit.
 *
 * Complexity:
 * Time: O(log n)
 * Space: O(1)
 */

class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum = 0;
        int product = 1;

        while (n > 0) {
            int ld = n % 10;
            n /= 10;
            product *= ld;
            sum += ld;
        }

        return product - sum;
    }
};