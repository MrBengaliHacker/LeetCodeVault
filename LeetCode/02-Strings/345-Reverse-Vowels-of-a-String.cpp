/**
 * 345. Reverse Vowels of a String
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/reverse-vowels-of-a-string/
 *
 * Problem:
 * Given a string s, reverse only all the vowels in the string and return it.
 *
 * The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both 
 * lowercase and uppercase.
 *
 * Example 1:
 * Input: s = "IceCreAm"
 * Output: "AceCreIm"
 *
 * Explanation:
 * The vowels in s are ['I', 'e', 'e', 'A'].
 * On reversing the vowels, s becomes "AceCreIm".
 *
 * Example 2:
 * Input: s = "leetcode"
 * Output: "leotcede"
 *
 *
 * Technique:
 * Two Pointers — Opposite Direction
 *
 * Key Idea:
 * Use two pointers starting from both ends of the string.
 * Skip non-vowels until both pointers point to vowels, then
 * swap them and move both pointers toward the center.
 *
 *
 * Approach:
 * 1. Set left at the beginning of the string.
 * 2. Set right at the end of the string.
 * 3. Move left forward until it points to a vowel.
 * 4. Move right backward until it points to a vowel.
 * 5. Swap the two vowels.
 * 6. Move both pointers toward the center.
 * 7. Continue until the pointers meet.
 *
 *
 * Complexity:
 * Time: O(n)
 * Space: O(1) extra space
 */

class Solution {
public:

    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' ||
               c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' ||
               c == 'O' || c == 'U';
    }

    string reverseVowels(string s) {

        int left = 0;
        int right = s.length() - 1;

        while (left < right) {

            while (left < right && !isVowel(s[left])) {
                left++;
            }

            while (left < right && !isVowel(s[right])) {
                right--;
            }

            swap(s[left], s[right]);

            left++;
            right--;
        }

        return s;
    }
};