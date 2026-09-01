/**
 * 709. To Lower Case
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/to-lower-case/
 *
 * Problem:
 * Given a string s, return the string after replacing every
 * uppercase letter with the same lowercase letter.
 *
 * Example 1:
 * Input:  s = "Hello"
 * Output: "hello"
 *
 * Example 2:
 * Input:  s = "here"
 * Output: "here"
 *
 * Example 3:
 * Input:  s = "LOVELY"
 * Output: "lovely"
 *
 * Technique:
 * String Traversal + Character Manipulation
 *
 * Key Idea:
 * Traverse the string and convert each character to lowercase.
 *
 * Approach:
 * 1. Traverse every character of the string.
 * 2. Convert the character using tolower().
 * 3. Modify the original string.
 * 4. Return the string.
 *
 * Complexity:
 * Time: O(n)
 * Space: O(1)
 */

class Solution {
public:
    string toLowerCase(string s) {
        for(char &x : s) {
            x = tolower(x);
        }

        return s;
    }
};