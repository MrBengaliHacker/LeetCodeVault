/**
 * 424. Longest Repeating Character Replacement
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/longest-repeating-character-replacement/
 *
 * Problem:
 * You are given a string s and an integer k. You can choose any character 
 * of the string and change it to any other uppercase English character.
 * You can perform this operation at most k times.
 *
 * Return the length of the longest substring containing the same letter
 * you can get after performing the operations.
 *
 *
 * Example 1:
 * Input: s = "ABAB", k = 2
 * Output: 4
 *
 * Explanation:
 * We can change the two 'A's to 'B's, making the substring "BBBB".
 * Therefore, the longest valid substring has length 4.
 *
 *
 * Example 2:
 * Input: s = "AABABBA", k = 1
 * Output: 4
 *
 * Explanation:
 * By changing one character, we can create a substring such as
 * "AABA" or "ABBB" containing four characters with the same letter.
 *
 *
 * Technique:
 * Variable-Size Sliding Window + Frequency Counting
 *
 *
 * Key Idea:
 * For every window, keep track of the frequency of each character
 * and the frequency of the most common character.
 *
 * The number of replacements needed is:
 *
 *     window length - maximum frequency
 *
 * If the required replacements are greater than k, shrink the window from the left.
 *
 *
 * Approach:
 * 1. Create a frequency array for the 26 uppercase letters.
 * 2. Use left and right pointers to maintain a sliding window.
 * 3. Move right forward and increase the frequency of s[right].
 * 4. Track maxFreq, the highest frequency of any character in the window.
 * 5. Calculate the number of replacements required:
 *
 *       window length - maxFreq
 *
 * 6. If the required replacements exceed k, shrink the window by
 *    moving the left pointer forward.
 * 7. Update maxLength with the size of the valid window.
 * 8. Return maxLength.
 *
 *
 * Complexity:
 * Time: O(n)
 * Space: O(1)
 *
 * n = length of the string
 */

class Solution {
public:

    int characterReplacement(string s, int k) {

        vector<int> freq(26, 0);

        int left = 0;
        int maxFreq = 0;
        int maxLength = 0;

        for (int right = 0; right < s.length(); right++) {

            freq[s[right] - 'A']++;

            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            while ((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};