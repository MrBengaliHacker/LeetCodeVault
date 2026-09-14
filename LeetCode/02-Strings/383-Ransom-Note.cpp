/**
 * 383. Ransom Note
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/ransom-note/
 *
 * Problem:
 * Given two strings ransomNote and magazine, return true if ransomNote can be 
 * constructed by using the letters from magazine and false otherwise.
 *
 * Each letter in magazine can only be used once in ransomNote.
 *
 * Example 1:
 * Input: ransomNote = "a", magazine = "b"
 * Output: false
 *
 * Example 2:
 * Input: ransomNote = "aa", magazine = "ab"
 * Output: false
 *
 * Example 3:
 * Input: ransomNote = "aa", magazine = "aab"
 * Output: true
 *
 *
 * Technique:
 * Frequency Counting
 *
 * Key Idea:
 * Count the frequency of each character in magazine.
 * For every character in ransomNote, use one occurrence from the available frequency.
 * If a required character has no remaining occurrence, return false.
 *
 * Approach:
 * 1. Create a frequency array of size 26.
 * 2. Count the characters available in magazine.
 * 3. Traverse ransomNote character by character.
 * 4. If the required character is unavailable, return false.
 * 5. Otherwise, decrease its frequency.
 * 6. If all characters are successfully used, return true.
 *
 *
 * Complexity:
 * Time: O(n)
 * Space: O(1) extra space
 */

class Solution {
public:

    bool canConstruct(string ransomNote, string magazine) {

        int freq[26] = {0};

        for (char ch : magazine) {
            freq[ch - 'a']++;
        }

        for (char ch : ransomNote) {

            if (freq[ch - 'a'] == 0) {
                return false;
            }

            freq[ch - 'a']--;
        }

        return true;
    }
};