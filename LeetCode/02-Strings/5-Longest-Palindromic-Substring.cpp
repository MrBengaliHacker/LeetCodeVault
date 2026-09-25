/**
 * 5. Longest Palindromic Substring
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/longest-palindromic-substring/
 *
 * Problem:
 * Given a string s, return the longest palindromic substring in s.
 *
 *
 * Example 1:
 * Input: s = "babad"
 * Output: "bab"
 *
 * Explanation:
 * "aba" is also a valid answer.
 *
 *
 * Example 2:
 * Input: s = "cbbd"
 * Output: "bb"
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
 * Expand outward from every possible center while the characters
 * on both sides are equal.
 *
 *
 * Approach:
 * 1. If the string is empty, return an empty string.
 * 2. Treat every character as the center of an odd-length palindrome.
 * 3. Treat every gap between two characters as the center of an
 *    even-length palindrome.
 * 4. Expand outward while the characters match.
 * 5. Track the longest palindrome found so far.
 * 6. Return the longest palindromic substring.
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
    string expand(const string& s, int left, int right) {
        while (left >= 0 && right < s.length() &&
               s[left] == s[right]) {
            left--;
            right++;
        }

        return s.substr(left + 1, right - left - 1);
    }

    string longestPalindrome(string s) {
        string longest = "";

        for (int i = 0; i < s.length(); i++) {
            // Odd-length palindrome
            string odd = expand(s, i, i);

            // Even-length palindrome
            string even = expand(s, i, i + 1);

            if (odd.length() > longest.length())
                longest = odd;

            if (even.length() > longest.length())
                longest = even;
        }

        return longest;
    }
};