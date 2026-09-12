/**
 * 680. Valid Palindrome II
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/valid-palindrome-ii/
 *
 * Problem:
 * Given a string s, return true if the s can be palindrome 
 * after deleting at most one character from it.
 *
 * Example 1:
 * Input: s = "aba"
 * Output: true
 *
 * Example 2:
 * Input: s = "abca"
 * Output: true
 *
 * Explanation:
 * You could delete the character 'c'.
 *
 * Example 3:
 * Input: s = "abc"
 * Output: false
 *
 *
 * Technique:
 * Two Pointers — Opposite Direction
 *
 * Key Idea:
 * Compare characters from both ends of the string.
 * If a mismatch occurs, we are allowed to delete at most one character,
 * so we check both possibilities:
 * skip the left character or skip the right character.
 *
 * Approach:
 * 1. Set left at the beginning of the string.
 * 2. Set right at the end of the string.
 * 3. Compare s[left] and s[right].
 * 4. If they match, move both pointers inward.
 * 5. If they do not match, skip either the left or right character 
 *    and check whether the remaining substring is a palindrome.
 * 6. If either possibility is a palindrome, return true.
 * 7. If all characters match, return true.
 *
 *
 * Complexity:
 * Time: O(n)
 * Space: O(1) extra space
 */

class Solution {
public:

    bool isPalindrome(const string& s, int left, int right) {

        while (left < right) {

            if (s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    bool validPalindrome(const string& s) {

        int left = 0;
        int right = s.length() - 1;

        while (left < right) {

            if (s[left] != s[right]) {

                return isPalindrome(s, left + 1, right) ||
                       isPalindrome(s, left, right - 1);
            }

            left++;
            right--;
        }

        return true;
    }
};