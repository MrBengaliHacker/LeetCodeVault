/**
 * 647. Palindromic Substrings
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/palindromic-substrings/
 *
 * Problem:
 * Given a string s, return the number of palindromic substrings in it.
 *
 * A string is a palindrome when it reads the same backward as forward.
 *
 * A substring is a contiguous sequence of characters within the string.
 *
 *
 * Example 1:
 * Input: s = "abc"
 * Output: 3
 *
 * Explanation:
 * Three palindromic strings are "a", "b", and "c".
 *
 *
 * Example 2:
 * Input: s = "aaa"
 * Output: 6
 *
 * Explanation:
 * Six palindromic strings are "a", "a", "a", "aa", "aa", and "aaa".
 *
 *
 * Technique:
 * Expand Around Center
 *
 * Key Idea:
 * Every palindrome has a center.
 *
 * There are two possible types of centers:
 * - One character for odd-length palindromes.
 * - The gap between two characters for even-length palindromes.
 *
 * Expand outward from every possible center.
 * Every successful expansion represents one palindromic substring.
 *
 *
 * Approach:
 * 1. Initialize a counter to store the number of palindromic substrings.
 * 2. Treat every character as the center of an odd-length palindrome.
 * 3. Expand outward while the characters on both sides are equal.
 * 4. Count every successful expansion.
 * 5. Treat every gap between two characters as the center of an
 *    even-length palindrome.
 * 6. Expand outward and count every successful expansion.
 * 7. Return the total count.
 *
 *
 * Complexity:
 * Time: O(n²)
 * Space: O(1)
 *
 * n = length of the string
 */
class Solution {
public:
    int expand(const string& s, int left, int right) {
        int count = 0;

        while (left >= 0 && right < s.length() &&
               s[left] == s[right]) {
            count++;
            left--;
            right++;
        }

        return count;
    }

    int countSubstrings(string s) {
        int count = 0;

        for (int i = 0; i < s.length(); i++) {
            // Odd-length palindromes
            count += expand(s, i, i);

            // Even-length palindromes
            count += expand(s, i, i + 1);
        }

        return count;
    }
};