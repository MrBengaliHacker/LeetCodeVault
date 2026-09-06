/**
 * 13. Roman to Integer
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/roman-to-integer/
 *
 * Problem:
 * Given a Roman numeral, convert it to an integer.
 *
 * Example 1:
 * Input: s = "III"
 * Output: 3
 *
 * Explanation:
 * III = 1 + 1 + 1 = 3.
 *
 * Example 2:
 * Input: s = "LVIII"
 * Output: 58
 *
 * Explanation:
 * L = 50, V = 5, III = 3.
 *
 * Example 3:
 * Input: s = "MCMXCIV"
 * Output: 1994
 *
 * Explanation:
 * M = 1000, CM = 900, XC = 90 and IV = 4.
 *
 *
 * Technique:
 * Right-to-Left Traversal + Hash Map (Comparison-Based)
 *
 * Key Idea:
 * Traverse the Roman numeral from right to left.
 *
 * If the current value is smaller than the previous value,
 * subtract it. Otherwise, add it.
 *
 * Approach:
 * 1. Store the value of each Roman numeral symbol.
 * 2. Traverse the string from right to left.
 * 3. Compare the current value with the previous value.
 * 4. If current < previous, subtract current from the answer.
 * 5. Otherwise, add current to the answer.
 * 6. Update previous to the current value.
 *
 * Complexity:
 * Time: O(N)
 * Space: O(1) extra space
 *
 * N = length of the Roman numeral
 */

class Solution {
public:
    int romanToInt(string s) {

        unordered_map<char, int> value = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int ans = 0;
        int prev = 0;

        for (int i = s.size() - 1; i >= 0; i--) {

            int curr = value[s[i]];

            if (curr < prev) {
                ans -= curr;
            }
            else {
                ans += curr;
            }

            prev = curr;
        }

        return ans;
    }
};