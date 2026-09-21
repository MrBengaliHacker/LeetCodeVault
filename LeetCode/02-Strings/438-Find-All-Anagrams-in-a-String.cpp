/**
 * 438. Find All Anagrams in a String
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/find-all-anagrams-in-a-string/
 *
 * Problem:
 * Given two strings s and p, return an array of all the start indices of p's anagrams in s.
 *
 * You may return the answer in any order.
 *
 * Example 1:
 * Input: s = "cbaebabacd", p = "abc"
 * Output: [0,6]
 *
 * Explanation:
 * The substring with start index 0 is "cba", which is an anagram
 * of "abc".
 * The substring with start index 6 is "bac", which is an anagram
 * of "abc".
 *
 * Example 2:
 * Input: s = "abab", p = "ab"
 * Output: [0,1,2]
 *
 *
 * Technique:
 * Fixed-Size Sliding Window + Frequency Counting
 *
 * Key Idea:
 * Every anagram of p has exactly the same character frequencies as p.
 *
 * Maintain a window of size p.length() in s and track how many
 * required characters are still missing from the current window.
 *
 *
 * Approach:
 * 1. If p is longer than s, return an empty result.
 * 2. Count the frequency of every character in p.
 * 3. Initialize a window using the first p.length() characters
 *    of s.
 * 4. Use remaining to track how many required characters are
 *    still missing from the current window.
 * 5. Slide the window through s:
 *      - Add the right character.
 *      - Remove the left character when the window becomes
 *        larger than p.length().
 * 6. When remaining becomes 0, the current window is an anagram
 *    of p, so store its starting index.
 *
 *
 * Complexity:
 * Time: O(n)
 * Space: O(1)
 *
 * n = length of s
 */

class Solution {
public:

    vector<int> findAnagrams(string s, string p) {

        vector<int> result;

        if (p.length() > s.length()) {
            return result;
        }

        vector<int> count(26, 0);

        for (char c : p) {
            count[c - 'a']++;
        }

        int left = 0;
        int right = 0;
        int remaining = p.length();

        while (right < s.length()) {

            if (count[s[right] - 'a'] > 0) {
                remaining--;
            }

            count[s[right] - 'a']++;
            right++;

            if (right - left > p.length()) {

                if (count[s[left] - 'a'] > 0) {
                    remaining++;
                }

                count[s[left] - 'a']--;
                left++;
            }

            if (remaining == 0) {
                result.push_back(left);
            }
        }

        return result;
    }
};