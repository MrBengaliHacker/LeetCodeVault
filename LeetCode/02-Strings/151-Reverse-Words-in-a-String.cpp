/**
 * 151. Reverse Words in a String
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/reverse-words-in-a-string/
 *
 * Problem:
 * Given an input string s, reverse the order of the words.
 *
 * A word is defined as a sequence of non-space characters.
 *
 * Return a string of the words in reverse order concatenated by a single space.
 *
 * Note:
 * - s may contain leading or trailing spaces.
 * - s may contain multiple spaces between words.
 * - The returned string should contain only a single space between words.
 *
 *
 * Example 1:
 * Input: s = "the sky is blue"
 * Output: "blue is sky the"
 *
 *
 * Example 2:
 * Input: s = "  hello world  "
 * Output: "world hello"
 *
 * Explanation:
 * Leading and trailing spaces are removed in the result.
 *
 *
 * Example 3:
 * Input: s = "a good   example"
 * Output: "example good a"
 *
 * Explanation:
 * Multiple spaces between words are reduced to a single space.
 *
 *
 * Technique:
 * In-Place String Manipulation + Reversal
 *
 * Key Idea:
 * First remove extra spaces and compact all words toward 
 * the beginning of the string.
 *
 * Then reverse the entire string and reverse each individual word.
 *
 * For example:
 *
 *     "the sky is blue"
 *
 * Reverse the entire string:
 *
 *     "eulb si yks eht"
 *
 * Reverse each word:
 *
 *     "blue is sky the"
 *
 *
 * Approach:
 * 1. Use read to scan the original string.
 * 2. Use write to place valid characters at the beginning of the string.
 * 3. Skip leading spaces and collapse multiple spaces into one.
 * 4. Resize the string to remove unused characters.
 * 5. Reverse the entire string.
 * 6. Reverse each individual word to restore the characters of each word.
 * 7. Return the modified string.
 *
 *
 * Complexity:
 * Time: O(n)
 * Space: O(1)
 *
 * n = length of the string
 */

class Solution {
public:

    string reverseWords(string s) {

        // Remove extra spaces and move words to the front
        int n = s.size();
        int write = 0;

        for (int read = 0; read < n; read++) {

            if (s[read] != ' ') {

                if (write > 0)
                    s[write++] = ' ';

                while (read < n && s[read] != ' ')
                    s[write++] = s[read++];
            }
        }

        s.resize(write);

        // Reverse the entire string
        reverse(s.begin(), s.end());

        // Reverse each individual word
        int start = 0;

        for (int i = 0; i <= s.size(); i++) {

            if (i == s.size() || s[i] == ' ') {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }

        return s;
    }
};