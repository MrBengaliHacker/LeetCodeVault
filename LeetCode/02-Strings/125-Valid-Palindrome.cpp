/**
 * 125. Valid Palindrome
 *
 * Difficulty: Easy
 *
 * Link:
 * https://leetcode.com/problems/valid-palindrome/
 *
 * Problem:
 * A phrase is a palindrome if, after converting all uppercase letters
 * to lowercase letters and removing all non-alphanumeric characters,
 * it reads the same forward and backward.
 *
 * Given a string s, return true if it is a palindrome, or false otherwise.
 *
 * Example 1:
 * Input: s = "A man, a plan, a canal: Panama"
 * Output: true
 *
 * Explanation:
 * "amanaplanacanalpanama" is a palindrome.
 *
 * Example 2:
 * Input: s = "race a car"
 * Output: false
 *
 * Explanation:
 * "raceacar" is not a palindrome.
 *
 * Example 3:
 * Input: s = " "
 * Output: true
 *
 * Explanation:
 * s is an empty string after removing non-alphanumeric characters.
 *
 *
 * Technique:
 * Two Pointers + Character Filtering
 *
 *
 * Key Idea:
 * Use one pointer from the beginning and another from the end.
 * Skip non-alphanumeric characters and compare the remaining
 * characters after converting them to lowercase.
 *
 *
 * Approach:
 * 1. Set left at the beginning and right at the end.
 * 2. Move left forward while s[left] is not alphanumeric.
 * 3. Move right backward while s[right] is not alphanumeric.
 * 4. Compare both characters after converting them to lowercase.
 * 5. If they are different, return false.
 * 6. Move both pointers toward the center.
 * 7. If all characters match, return true.
 *
 *
 * Complexity:
 * Time: O(n)
 * Space: O(1) extra space
 */

class Solution {
public:
    bool isPalindrome(string s) {

        int i = 0;
        int j = s.length() - 1;

        while (i < j) {

            while (i < j && !isalnum(s[i])) {
                i++;
            }

            while (i < j && !isalnum(s[j])) {
                j--;
            }

            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }
};