/**
 * 541. Reverse String II
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/reverse-string-ii/
 *
 * Problem:
 * Given a string s and an integer k, reverse the first k characters
 * for every 2k characters counting from the start of the string.
 *
 * If there are fewer than k characters left, reverse all of them.
 * If there are at least k but fewer than 2k characters left, reverse
 * the first k characters and leave the rest unchanged.
 *
 * Example 1:
 * Input: s = "abcdefg", k = 2
 * Output: "bacdfeg"
 *
 * Example 2:
 * Input: s = "abcd", k = 2
 * Output: "bacd"
 *
 *
 * Approach 1: Manual Reversal
 *
 * Technique:
 * Two Pointers — In-Place Reversal
 *
 * Key Idea:
 * Process the string in blocks of 2k characters.
 * For each block, reverse only its first k characters using two pointers.
 *
 * Approach:
 * 1. Start from index 0.
 * 2. Move to the next block after every 2k characters.
 * 3. Set left at the beginning of the block.
 * 4. Set right at the end of the first k characters.
 * 5. Use two pointers to reverse those characters in-place.
 * 6. Limit right to the last index of the string when fewer
 *    than k characters remain.
 * 7. Return the modified string.
 *
 * Complexity:
 * Time: O(n)
 * Space: O(1) extra space
 */

class Solution {
public:
    string reverseStr(string s, int k) {

        for (int i = 0; i < s.size(); i += 2 * k) {

            int left = i;
            int right = min(i + k - 1, (int)s.size() - 1);

            while (left < right) {

                swap(s[left], s[right]);

                left++;
                right--;
            }
        }

        return s;
    }
};


/**
 * Approach 2: STL
 *
 * Technique:
 * String Manipulation + STL reverse()
 *
 * Key Idea:
 * Use the built-in reverse() function to reverse the first k characters of every 2k block.
 *
 * Approach:
 * 1. Start from index 0.
 * 2. Move to the next block after every 2k characters.
 * 3. Reverse the range containing the first k characters.
 * 4. Limit the ending position to the string length when fewer
 *    than k characters remain.
 * 5. Return the modified string.
 *
 * Complexity:
 * Time: O(n)
 * Space: O(1) extra space
 */

class Solution {
public:
    string reverseStr(string s, int k) {

        for (int i = 0; i < s.size(); i += 2 * k) {

            reverse(
                s.begin() + i,
                s.begin() + min(i + k, (int)s.size())
            );
        }

        return s;
    }
};