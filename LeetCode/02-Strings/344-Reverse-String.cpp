/**
 * 344. Reverse String
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/reverse-string/
 *
 * Problem:
 * Write a function that reverses a string.
 * The input string is given as an array of characters s.
 *
 * The input array must be modified in-place with O(1) extra memory.
 *
 * Example 1:
 * Input: s = ["h","e","l","l","o"]
 * Output: ["o","l","l","e","h"]
 *
 * Example 2:
 * Input: s = ["H","a","n","n","a","h"]
 * Output: ["h","a","n","n","a","H"]
 *
 *
 * Technique:
 * Two Pointers — Opposite Direction
 *
 * Key Idea:
 * Use two pointers, one at the beginning and one at the end.
 * Swap the characters at both pointers and move them towards the center until they meet.
 *
 * Approach:
 * 1. Set i at the beginning of the array.
 * 2. Set j at the end of the array.
 * 3. Swap s[i] and s[j].
 * 4. Move i forward and j backward.
 * 5. Continue until i >= j.
 *
 *
 * Complexity:
 * Time: O(n)
 * Space: O(1) extra space
 */

class Solution {

public:

    void reverseString(vector<char>& s) {

        int i = 0;
        int j = s.size() - 1;

        while (i < j) {

            swap(s[i], s[j]);

            i++;
            j--;
        }
    }
};