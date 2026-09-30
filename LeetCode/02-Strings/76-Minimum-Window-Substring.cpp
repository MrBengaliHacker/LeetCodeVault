/**
 * 76. Minimum Window Substring
 * Difficulty: Hard
 * Link: https://leetcode.com/problems/minimum-window-substring/
 *
 * Problem:
 * Given two strings s and t of lengths m and n respectively,
 * return the minimum window substring of s such that every character
 * in t (including duplicates) is included in the window.
 *
 * If there is no such substring, return an empty string.
 *
 *
 * Example 1:
 * Input: s = "ADOBECODEBANC", t = "ABC"
 * Output: "BANC"
 *
 * Explanation:
 * The minimum window substring "BANC" includes 'A', 'B', and 'C'.
 *
 *
 * Example 2:
 * Input: s = "a", t = "a"
 * Output: "a"
 *
 *
 * Example 3:
 * Input: s = "a", t = "aa"
 * Output: ""
 *
 *
 * Technique:
 * Variable-Size Sliding Window + Frequency Counting
 *
 * Key Idea:
 * Store the frequency required for every character in t.
 *
 * Expand the window by moving right until it contains all required
 * characters with the required frequencies.
 *
 * Once the window is valid, shrink it from the left as much as
 * possible while keeping it valid.
 *
 * This produces the smallest valid window ending at each right pointer.
 *
 *
 * Approach:
 * 1. Store the required frequency of every character in t.
 * 2. Use left and right pointers to maintain a sliding window.
 * 3. Move right forward and add s[right] to the current window.
 * 4. Track how many required characters have been satisfied.
 * 5. When the window contains all characters required by t,
 *    try to shrink it by moving left forward.
 * 6. Before removing a character, update the minimum window
 *    if the current window is smaller.
 * 7. Continue until right reaches the end of s.
 * 8. Return the minimum window found.
 *
 *
 * Complexity:
 * Time: O(m + n)
 * Space: O(1)
 *
 * m = length of s
 * n = length of t
 *
 * The frequency arrays contain only 128 ASCII characters,
 * so their size is constant.
 */
class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size())
            return "";

        int need[128] = {0};
        int window[128] = {0};

        for (char c : t)
            need[c]++;

        int required = t.size();
        int left = 0;

        int minLength = s.size() + 1;
        int minStart = 0;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];

            window[c]++;

            if (need[c] > 0 && window[c] <= need[c])
                required--;

            while (required == 0) {
                int currentLength = right - left + 1;

                if (currentLength < minLength) {
                    minLength = currentLength;
                    minStart = left;
                }

                char leftChar = s[left];
                window[leftChar]--;

                if (need[leftChar] > 0 &&
                    window[leftChar] < need[leftChar]) {
                    required++;
                }

                left++;
            }
        }

        if (minLength == s.size() + 1)
            return "";

        return s.substr(minStart, minLength);
    }
};