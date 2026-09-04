/**
 * 14. Longest Common Prefix
 *
 * Difficulty: Easy
 *
 * Link:
 * https://leetcode.com/problems/longest-common-prefix/
 *
 * Problem:
 * Write a function to find the longest common prefix string amongst
 * an array of strings.
 *
 * If there is no common prefix, return an empty string.
 *
 * Example 1:
 * Input:  strs = ["flower", "flow", "flight"]
 * Output: "fl"
 *
 * Example 2:
 * Input:  strs = ["dog", "racecar", "car"]
 * Output: ""
 * 
 * Explanation:
 * The first characters are different, so there is no common prefix.
 *
 * Technique:
 * String Traversal
 *
 * Key Idea:
 * Use the first string as a reference. For each character in the first
 * string, compare it with the character at the same index in every
 * other string.
 *
 * Approach:
 * 1. Traverse the characters of the first string.
 * 2. Store the current character in 'ch'.
 * 3. Compare 'ch' with the same position in every other string.
 * 4. If a string is too short or the character does not match,
 *    return the prefix found so far.
 * 5. If all characters match, return the first string.
 *
 * Complexity:
 * Time: O(N * M)
 * Space: O(1) extra space
 *
 * N = number of strings
 * M = length of the shortest string
 */

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        for (int i = 0; i < strs[0].size(); i++) {
            char ch = strs[0][i];

            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].size() || strs[j][i] != ch) {
                    return strs[0].substr(0, i);
                }
            }
        }

        return strs[0];
    }
};