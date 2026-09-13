/**
 * 242. Valid Anagram
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/valid-anagram/
 *
 * Problem:
 * Given two strings s and t, return true if t is an anagram of s, and false otherwise.
 *
 * Example 1:
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 *
 * Example 2:
 * Input: s = "rat", t = "car"
 * Output: false
 *
 * Technique:
 * Frequency Counting
 *
 * Key Idea:
 * Count the frequency of each character in s and decrease the
 * corresponding frequency for each character in t.
 * If any frequency is not zero, the strings are not anagrams.
 *
 *
 * Approach:
 * 1. If the strings have different lengths, return false.
 * 2. Create a frequency array of size 26.
 * 3. Increase the count for each character in s.
 * 4. Decrease the count for each character in t.
 * 5. Check whether every frequency is zero.
 * 6. If all frequencies are zero, return true.
 *
 *
 * Complexity:
 * Time: O(n)
 * Space: O(1) extra space
 */

class Solution {
public:

    bool isAnagram(string s, string t) {

        if (s.size() != t.size()) {
            return false;
        }

        int count[26] = {0};

        for (int i = 0; i < s.size(); i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                return false;
            }
        }

        return true;
    }
};