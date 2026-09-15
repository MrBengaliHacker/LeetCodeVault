/**
 * 387. First Unique Character in a String
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/first-unique-character-in-a-string/
 *
 * Problem:
 * Given a string s, find the first non-repeating character in it
 * and return its index. If it does not exist, return -1.
 *
 * Example 1:
 * Input: s = "leetcode"
 * Output: 0
 *
 * Explanation:
 * The character 'l' at index 0 is the first character that
 * does not occur at any other index.
 *
 * Example 2:
 * Input: s = "loveleetcode"
 * Output: 2
 *
 * Example 3:
 * Input: s = "aabb"
 * Output: -1
 *
 *
 * Technique:
 * Frequency Counting
 *
 *
 * Key Idea:
 * Count how many times each character appears in the string.
 * Then traverse the string from left to right and return the index 
 * of the first character whose frequency is exactly one.
 *
 *
 * Approach:
 * 1. Create a frequency array of size 26.
 * 2. Count the frequency of every character in s.
 * 3. Traverse s from left to right.
 * 4. If the frequency of the current character is one,
 *    return its index.
 * 5. If no character has frequency one, return -1.
 *
 *
 * Complexity:
 * Time: O(n)
 * Space: O(1) extra space
 */

class Solution {
public:

    int firstUniqChar(string s) {

        int freq[26] = {0};

        for (char c : s) {
            freq[c - 'a']++;
        }

        for (int i = 0; i < s.length(); i++) {

            if (freq[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }
};