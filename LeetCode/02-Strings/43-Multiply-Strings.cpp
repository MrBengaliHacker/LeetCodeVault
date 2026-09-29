/**
 * 43. Multiply Strings
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/multiply-strings/
 *
 * Problem:
 * Given two non-negative integers num1 and num2 represented as strings,
 * return the product of num1 and num2, also represented as a string.
 *
 * You must not use any built-in BigInteger library or convert the
 * inputs directly into integers.
 *
 *
 * Example 1:
 * Input: num1 = "2", num2 = "3"
 * Output: "6"
 *
 *
 * Example 2:
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 *
 *
 * Technique:
 * Array Simulation / Grade-School Multiplication
 *
 *
 * Key Idea:
 * Multiply each digit of num1 with each digit of num2 just like traditional multiplication.
 *
 * If num1 has m digits and num2 has n digits, their product can contain at most m + n digits.
 *
 * For digits at positions i and j, their product contributes to
 * positions i + j and i + j + 1 in the result array.
 *
 *
 * Approach:
 * 1. If either number is "0", return "0".
 * 2. Create a result array of size m + n initialized with 0.
 * 3. Traverse num1 and num2 from right to left.
 * 4. Multiply each pair of digits.
 * 5. Add the product to result[i + j + 1].
 * 6. Store the carry in result[i + j].
 * 7. Skip leading zeros from the result array.
 * 8. Convert the remaining digits into a string.
 * 9. Return the result.
 *
 *
 * Complexity:
 * Time: O(m * n)
 * Space: O(m + n)
 *
 * m = length of num1
 * n = length of num2
 */
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";

        int m = num1.size();
        int n = num2.size();

        vector<int> result(m + n, 0);

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int digit1 = num1[i] - '0';
                int digit2 = num2[j] - '0';

                int product = digit1 * digit2;

                int position = i + j + 1;

                result[position] += product;

                result[position - 1] += result[position] / 10;
                result[position] %= 10;
            }
        }

        string answer;
        int i = 0;

        while (i < result.size() && result[i] == 0)
            i++;

        while (i < result.size()) {
            answer += char(result[i] + '0');
            i++;
        }

        return answer;
    }
};