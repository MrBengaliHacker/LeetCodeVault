/**
 * 567. Permutation in String
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/permutation-in-string/
 *
 * Problem:
 * Given two strings s1 and s2, return true if s2 contains 
 * a permutation of s1, or false otherwise.
 *
 * In other words, return true if one of s1's permutations is
 * a substring of s2.
 *
 * Example 1:
 * Input: s1 = "ab", s2 = "eidbaooo"
 * Output: true
 *
 * Explanation:
 * s2 contains "ba", which is a permutation of "ab".
 *
 * Example 2:
 * Input: s1 = "ab", s2 = "eidboaoo"
 * Output: false
 *
 *
 * Technique:
 * Fixed-Size Sliding Window + Frequency Counting
 *
 * Key Idea:
 * Every permutation of s1 has the same character frequencies as s1.
 *
 * Maintain a window of size s1.length() in s2 and compare its
 * character frequencies with those of s1.
 *
 *
 * Approach:
 * 1. If s1 is longer than s2, return false.
 * 2. Count the frequency of each character in s1.
 * 3. Create a fixed-size window of the same length in s2.
 * 4. Count the characters inside the current window.
 * 5. Compare the two frequency arrays.
 * 6. Slide the window one position at a time:
 *      - Add the new character.
 *      - Remove the character leaving the window.
 * 7. If the frequencies match, return true.
 * 8. If no window matches, return false.
 *
 *
 * Complexity:
 * Time: O(n)
 * Space: O(1) extra space
 *
 * n = length of s2
 */

class Solution {
public:

    bool checkInclusion(string s1, string s2) {

        if (s1.length() > s2.length()) {
            return false;
        }

        int targetFreq[26] = {0};
        int windowFreq[26] = {0};

        for (char c : s1) {
            targetFreq[c - 'a']++;
        }

        int k = s1.length();

        for (int i = 0; i < k; i++) {
            windowFreq[s2[i] - 'a']++;
        }

        if (equal(targetFreq, targetFreq + 26, windowFreq)) {
            return true;
        }

        for (int i = k; i < s2.length(); i++) {

            windowFreq[s2[i] - 'a']++;
            windowFreq[s2[i - k] - 'a']--;

            if (equal(targetFreq, targetFreq + 26, windowFreq)) {
                return true;
            }
        }

        return false;
    }
};