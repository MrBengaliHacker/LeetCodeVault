/**
 * 1768. Merge Strings Alternately
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/merge-strings-alternately/
 *
 * Problem:
 * You are given two strings word1 and word2. Merge the strings by
 * adding letters in alternating order, starting with word1.
 *
 * If one string is longer than the other, append the additional
 * letters onto the end of the merged string.
 *
 * Example 1:
 * Input:  word1 = "abc", word2 = "pqr"
 * Output: "apbqcr"
 *
 * Explanation:
 * The characters are added alternately:
 * word1: a  b  c
 * word2: p  q  r
 * merged: a  p  b  q  c  r
 *
 * Example 2:
 * Input:  word1 = "ab", word2 = "pqrs"
 * Output: "apbqrs"
 *
 * Explanation:
 * The strings are merged alternately until word1 ends.
 * The remaining characters "rs" from word2 are appended.
 *
 * Example 3:
 * Input:  word1 = "abcd", word2 = "pq"
 * Output: "apbqcd"
 *
 * Explanation:
 * The strings are merged alternately until word2 ends.
 * The remaining characters "cd" from word1 are appended.
 *
 * Technique:
 * String Traversal
 *
 * Key Idea:
 * Traverse both strings using the same index and append a character
 * from each string whenever that index exists.
 *
 * Approach:
 * 1. Start from index 0.
 * 2. Add a character from word1 if available.
 * 3. Add a character from word2 if available.
 * 4. Continue until both strings are completely processed.
 * 5. Return the merged string.
 *
 * Complexity:
 * Time: O(m + n)
 * Space: O(m + n) for the output
 */

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        string result = "";
        int i = 0;

        while(i < m || i < n) {
            if(i < m) result.push_back(word1[i]);
            if(i < n) result.push_back(word2[i]);
            i++;
        }

        return result;
    }
};