/**
 * 205. Isomorphic Strings
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/isomorphic-strings/
 *
 * Problem:
 * Given two strings s and t, determine if they are isomorphic.
 *
 * Two strings s and t are isomorphic if the characters in s can be replaced to get t.
 *
 * Example 1:
 * Input: s = "egg", t = "add"
 * Output: true
 *
 * Explanation:
 * 'e' maps to 'a' and 'g' maps to 'd'.
 *
 * Example 2:
 * Input: s = "foo", t = "bar"
 * Output: false
 *
 * Explanation:
 * 'o' cannot map to both 'a' and 'r'.
 *
 * Example 3:
 * Input: s = "paper", t = "title"
 * Output: true
 *
 *
 * Technique:
 * Character Mapping / Bijection
 *
 *
 * Key Idea:
 * Maintain a mapping in both directions:
 * s → t and t → s.
 *
 * This ensures that each character in s maps to only one character in t, 
 * and each character in t is mapped from only one character in s.
 *
 *
 * Approach:
 * 1. If the strings have different lengths, return false.
 * 2. Create two mapping arrays for both directions.
 * 3. Traverse both strings together.
 * 4. If an existing mapping conflicts, return false.
 * 5. Otherwise, create the mapping in both directions.
 * 6. If all characters follow the same mapping, return true.
 *
 *
 * Complexity:
 * Time: O(n)
 * Space: O(1) extra space
 */

class Solution {
public:

    bool isIsomorphic(string s, string t) {

        if (s.length() != t.length()) {
            return false;
        }

        vector<int> sToT(256, -1);
        vector<int> tToS(256, -1);

        for (int i = 0; i < s.length(); i++) {

            unsigned char a = s[i];
            unsigned char b = t[i];

            if (sToT[a] != -1 && sToT[a] != b) {
                return false;
            }

            if (tToS[b] != -1 && tToS[b] != a) {
                return false;
            }

            sToT[a] = b;
            tToS[b] = a;
        }

        return true;
    }
};