/**
 * 28. Find the Index of the First Occurrence in a String
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
 *
 * Problem:
 * Given two strings haystack and needle, return the index of the
 * first occurrence of needle in haystack, or -1 if needle is not
 * part of haystack.
 *
 * Example 1:
 * Input: haystack = "sadbutsad", needle = "sad"
 * Output: 0
 *
 * Explanation:
 * "sad" occurs at index 0 and index 6.
 * The first occurrence is at index 0.
 *
 * Example 2:
 * Input: haystack = "leetcode", needle = "leeto"
 * Output: -1
 *
 * Explanation:
 * "leeto" does not occur in "leetcode".
 *
 *
 * Approach 1: Brute Force
 *
 * Technique:
 * String Matching / Brute Force
 *
 * Key Idea:
 * Check every possible starting position in haystack and compare
 * the characters of needle one by one.
 *
 * Approach:
 * 1. Start from each possible index in haystack.
 * 2. Compare characters of haystack with characters of needle.
 * 3. If all characters match, return the starting index.
 * 4. If a mismatch occurs, move to the next starting position.
 * 5. If no match is found, return -1.
 *
 * Complexity:
 * Time: O(M × N)
 * Space: O(1) extra space
 *
 * M = length of haystack
 * N = length of needle
 */

class Solution {
public:
    int strStr(string haystack, string needle) {

        int m = haystack.size();
        int n = needle.size();

        for (int i = 0; i <= m - n; i++) {

            int j = 0;

            while (j < n && haystack[i + j] == needle[j]) {
                j++;
            }

            if (j == n) {
                return i;
            }
        }

        return -1;
    }
}

/**
 * Approach 2: KMP
 *
 * Technique:
 * KMP (Knuth-Morris-Pratt) / String Matching
 *
 * Key Idea:
 * Use the LPS (Longest Prefix Suffix) array to avoid rechecking
 * characters that have already been matched.
 *
 * When a mismatch occurs, LPS tells us how far we can move in
 * needle without starting the comparison from the beginning.
 *
 * Approach:
 * 1. Build the LPS array for needle.
 * 2. Use two pointers:
 *      i → haystack
 *      j → needle
 * 3. If characters match, move both pointers forward.
 * 4. If a mismatch occurs and j > 0, use lps[j - 1].
 * 5. If a mismatch occurs and j == 0, move i forward.
 * 6. If j reaches the length of needle, return i - n.
 * 7. If the complete needle is not found, return -1.
 *
 * Complexity:
 * Time: O(M + N)
 * Space: O(N)
 *
 * M = length of haystack
 * N = length of needle
 */

class Solution {
public:
    int strStr(string haystack, string needle) {

        int m = haystack.size();
        int n = needle.size();

        vector<int> lps(n, 0);

        int len = 0;

        for (int i = 1; i < n; ) {

            if (needle[i] == needle[len]) {

                len++;
                lps[i] = len;
                i++;

            }
            else if (len > 0) {

                len = lps[len - 1];

            }
            else {

                lps[i] = 0;
                i++;
            }
        }

        int i = 0;
        int j = 0;

        while (i < m) {

            if (haystack[i] == needle[j]) {

                i++;
                j++;

                if (j == n) {
                    return i - n;
                }
            }
            else if (j > 0) {

                j = lps[j - 1];

            }
            else {

                i++;
            }
        }

        return -1;
    }
};