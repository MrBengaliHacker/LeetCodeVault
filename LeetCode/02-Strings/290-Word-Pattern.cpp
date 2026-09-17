/**
 * 290. Word Pattern
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/word-pattern/
 *
 * Problem:
 * Given a pattern and a string s, find if s follows the same pattern.
 *
 * Here follow means a full match, such that there is a bijection between
 * a letter in pattern and a non-empty word in s.
 *
 * Example 1:
 * Input: pattern = "abba", s = "dog cat cat dog"
 * Output: true
 *
 * Explanation:
 * 'a' maps to "dog" and 'b' maps to "cat".
 *
 * Example 2:
 * Input: pattern = "abba", s = "dog cat cat fish"
 * Output: false
 *
 * Example 3:
 * Input: pattern = "aaaa", s = "dog cat cat dog"
 * Output: false
 *
 *
 * Technique:
 * Character Mapping / Bijection
 *
 * Key Idea:
 * Maintain a mapping in both directions:
 * pattern → word and word → pattern.
 *
 * This ensures that each character maps to only one word and
 * each word maps to only one character.
 *
 * Approach:
 * 1. Split the string into individual words.
 * 2. If the number of words exceeds the length of pattern, return false.
 * 3. Check the existing mapping from character to word.
 * 4. Check the existing mapping from word to character.
 * 5. If either mapping conflicts, return false.
 * 6. Otherwise, create both mappings.
 * 7. After processing all words, make sure the number of words
 *    is equal to the length of pattern.
 *
 *
 * Complexity:
 * Time: O(n)
 * Space: O(n)
 *
 * n = number of words in s
 */

class Solution {
public:

    bool wordPattern(string pattern, string s) {

        unordered_map<char, string> mp;
        unordered_map<string, char> rev;

        stringstream ss(s);
        string word;

        int i = 0;

        while (ss >> word) {

            if (i == pattern.size()) {
                return false;
            }

            char ch = pattern[i];

            if (mp.count(ch) && mp[ch] != word) {
                return false;
            }

            if (rev.count(word) && rev[word] != ch) {
                return false;
            }

            mp[ch] = word;
            rev[word] = ch;

            i++;
        }

        return i == pattern.size();
    }
};