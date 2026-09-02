/**
 * 58. Length of Last Word
 *
 * Difficulty: Easy
 *
 * Link:
 * https://leetcode.com/problems/length-of-last-word/
 *
 * Problem:
 * Given a string s consisting of words and spaces, return the length
 * of the last word in the string.
 *
 * Example 1:
 * Input:  s = "Hello World"
 * Output: 5
 *
 * Example 2:
 * Input:  s = "   fly me   to   the moon  "
 * Output: 4
 *
 * Example 3:
 * Input:  s = "luffy is still joyboy"
 * Output: 6
 *
 * Technique:
 * Reverse Traversal
 *
 * Key Idea:
 * Start from the end of the string and count characters until the
 * first space after finding the last word.
 *
 * Approach:
 * 1. Traverse the string from right to left.
 * 2. Ignore trailing spaces.
 * 3. Count characters of the last word.
 * 4. Stop when a space is found after counting.
 * 5. Return the count.
 *
 * Complexity:
 * Time: O(n)
 * Space: O(1)
 */

class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;

        for(int i = s.length() - 1; i >= 0; i--) {
            if(s[i] == ' ') {
                if(count > 0) break;
            }
            else {
                count++;
            }
        }

        return count;
    }
};