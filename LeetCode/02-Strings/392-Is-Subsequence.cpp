/**
 * 392. Is Subsequence
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/is-subsequence/
 *
 * Problem:
 * Given two strings s and t, return true if s is a subsequence
 * of t, or false otherwise.
 *
 * A subsequence of a string is a new string that is formed from original string 
 * by deleting some (can be none) of the characters without disturbing 
 * the relative positions of the remaining characters.
 *
 * Example 1:
 * Input: s = "abc", t = "ahbgdc"
 * Output: true
 *
 * Explanation:
 * "abc" is a subsequence of "ahbgdc".
 *
 * Example 2:
 * Input: s = "axc", t = "ahbgdc"
 * Output: false
 *
 * Explanation:
 * "axc" is not a subsequence of "ahbgdc".
 *
 *
 * Technique:
 * Two Pointers — Same Direction
 *
 * Key Idea:
 * Use one pointer for s and another pointer for t.
 * Move through t and advance the pointer of s whenever the current characters match.
 *
 * Approach:
 * 1. Set i at the beginning of s.
 * 2. Set j at the beginning of t.
 * 3. Compare s[i] and t[j].
 * 4. If they match, move i forward.
 * 5. Always move j forward.
 * 6. If i reaches the end of s, all characters of s were found
 *    in the correct order.
 * 7. Return whether i equals the length of s.
 *
 *
 * Complexity:
 * Time: O(n)
 * Space: O(1) extra space
 */

class Solution {
public:
    bool isSubsequence(string s, string t) {

        int i = 0;
        int j = 0;

        while (i < s.length() && j < t.length()) {

            if (s[i] == t[j]) {
                i++;
            }

            j++;
        }

        return i == s.length();
    }
};