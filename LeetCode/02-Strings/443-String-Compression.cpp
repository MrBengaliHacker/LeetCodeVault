/**
 * 443. String Compression
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/string-compression/
 *
 * Problem:
 * Compress the given array of characters in-place.
 *
 * For each group of consecutive repeating characters:
 * - If the group length is 1, write only the character.
 * - Otherwise, write the character followed by its count.
 *
 * Return the new length of the compressed array.
 *
 *
 * Example 1:
 * Input: chars = ["a","a","b","b","c","c","c"]
 * Output: 6
 *
 * Explanation:
 * The groups are "aa", "bb", and "ccc".
 * The compressed array becomes ["a","2","b","2","c","3"].
 *
 *
 * Example 2:
 * Input: chars = ["a"]
 * Output: 1
 *
 * Explanation:
 * The only group is "a", which remains unchanged.
 *
 *
 * Example 3:
 * Input:
 * chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
 *
 * Output: 4
 *
 * Explanation:
 * The groups are "a" and "bbbbbbbbbbbb".
 * The compressed array becomes ["a","b","1","2"].
 *
 *
 * Technique:
 * Two Pointers + In-Place Array Manipulation
 *
 *
 * Key Idea:
 * Use one pointer to read groups of consecutive characters
 * and another pointer to write the compressed result back into the same array.
 *
 *
 * Approach:
 * 1. Initialize read and write pointers at 0.
 * 2. Use read to find each group of consecutive equal characters.
 * 3. Store the current character and count its occurrences.
 * 4. Write the character at the write position.
 * 5. If the count is greater than 1, convert the count to a string
 *    and write each digit into the array.
 * 6. Continue until all groups are processed.
 * 7. Return write, which represents the new compressed length.
 *
 *
 * Complexity:
 * Time: O(n)
 * Space: O(1)
 *
 * n = length of the character array
 */
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int write = 0;
        int read = 0;

        while (read < n) {
            char current = chars[read];
            int count = 0;

            // Count consecutive same characters
            while (read < n && chars[read] == current) {
                read++;
                count++;
            }

            // Write the character
            chars[write++] = current;

            // Write the count if greater than 1
            if (count > 1) {
                string num = to_string(count);

                for (char c : num) {
                    chars[write++] = c;
                }
            }
        }

        return write;
    }
};