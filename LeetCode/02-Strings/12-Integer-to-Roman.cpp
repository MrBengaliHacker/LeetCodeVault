/**
 * 12. Integer to Roman
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/integer-to-roman/
 *
 * Problem:
 * Given an integer, convert it to a Roman numeral.
 *
 *
 * Example 1:
 * Input: num = 3749
 * Output: "MMMDCCXLIX"
 *
 * Explanation:
 * 3000 = MMM
 * 700 = DCC
 * 40 = XL
 * 9 = IX
 *
 *
 * Example 2:
 * Input: num = 58
 * Output: "LVIII"
 *
 * Explanation:
 * 50 = L
 * 8 = VIII
 *
 *
 * Example 3:
 * Input: num = 1994
 * Output: "MCMXCIV"
 *
 * Explanation:
 * 1000 = M
 * 900 = CM
 * 90 = XC
 * 4 = IV
 *
 *
 * Technique:
 * Greedy / One-Pass
 *
 *
 * Key Idea:
 * Always use the largest possible Roman numeral value first.
 *
 * The subtractive forms are included directly:
 *
 *     900 = CM
 *     400 = CD
 *     90  = XC
 *     40  = XL
 *     9   = IX
 *     4   = IV
 *
 * By processing the values from largest to smallest,
 * the number can be converted greedily into its Roman representation.
 *
 *
 * Approach:
 * 1. Store the Roman numeral values and their corresponding symbols
 *    from largest to smallest.
 * 2. Start from the largest value.
 * 3. While the current value can be subtracted from num:
 *    - Append its corresponding symbol to the result.
 *    - Subtract its value from num.
 * 4. Move to the next smaller value.
 * 5. Continue until num becomes 0.
 * 6. Return the result.
 *
 *
 * Complexity:
 * Time: O(1)
 * Space: O(1)
 *
 * The number of Roman numeral values is fixed at 13.
 */
class Solution {
public:
    string intToRoman(int num) {
        string result = "";

        int values[] = {
            1000, 900, 500, 400,
            100, 90, 50, 40,
            10, 9, 5, 4, 1
        };

        string symbols[] = {
            "M", "CM", "D", "CD",
            "C", "XC", "L", "XL",
            "X", "IX", "V", "IV", "I"
        };

        for (int i = 0; i < 13; i++) {
            while (num >= values[i]) {
                result += symbols[i];
                num -= values[i];
            }
        }

        return result;
    }
};