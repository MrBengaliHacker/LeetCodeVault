/**
 * 3. Longest Substring Without Repeating Characters
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
 *
 * Problem:
 * Given a string s, find the length of the longest substring
 * without duplicate characters.
 *
 * Example 1:
 * Input: s = "abcabcbb"
 * Output: 3
 *
 * Explanation:
 * The answer is "abc", with a length of 3.
 *
 * Example 2:
 * Input: s = "bbbbb"
 * Output: 1
 *
 * Explanation:
 * The answer is "b", with a length of 1.
 *
 * Example 3:
 * Input: s = "pwwkew"
 * Output: 3
 *
 * Explanation:
 * The answer is "wke", with a length of 3.
 *
 *
 * Technique:
 * Sliding Window + Last Occurrence Tracking
 *
 * Key Idea:
 * Maintain a window containing unique characters.
 * Store the last index of every character.
 *
 * When a duplicate character is found, move the left pointer
 * directly after its previous occurrence.
 *
 *
 * Approach:
 * 1. Create an array to store the last index of each character.
 * 2. Start the left pointer at 0.
 * 3. Move the right pointer through the string.
 * 4. If the current character appeared inside the current window,
 *    move left to its previous index + 1.
 * 5. Update the character's last occurrence.
 * 6. Update the maximum window length.
 *
 *
 * Complexity:
 * Time: O(n)
 * Space: O(1) extra space
 */

class Solution {
public:

    int lengthOfLongestSubstring(string s) {

        vector<int> last(128, -1);

        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < s.length(); right++) {

            if (last[s[right]] >= left) {
                left = last[s[right]] + 1;
            }

            last[s[right]] = right;

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};