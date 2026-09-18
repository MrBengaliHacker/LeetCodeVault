/**
 * 49. Group Anagrams
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/group-anagrams/
 *
 * Problem:
 * Given an array of strings strs, group the anagrams together.
 * You can return the answer in any order.
 *
 * Example 1:
 * Input: strs = ["eat","tea","tan","ate","nat","bat"]
 * Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
 *
 * Explanation:
 * "eat", "tea", and "ate" contain the same characters with
 * the same frequencies, so they belong to the same group.
 *
 * Example 2:
 * Input: strs = [""]
 * Output: [[""]]
 *
 * Example 3:
 * Input: strs = ["a"]
 * Output: [["a"]]
 *
 *
 * Technique:
 * Frequency Counting + Hashing
 *
 *
 * Key Idea:
 * Anagrams have the same frequency of every character.
 * Create a frequency signature for each string and use it
 * as the hash map key.
 *
 *
 * Approach:
 * 1. Create a frequency array of size 26 for each string.
 * 2. Count the frequency of every character.
 * 3. Store the 26 frequencies as a unique string key.
 * 4. Use the key to group anagrams in a hash map.
 * 5. Return all groups from the hash map.
 *
 *
 * Complexity:
 * Time: O(n × k)
 * Space: O(n × k)
 *
 * n = number of strings
 * k = maximum length of a string
 */

class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mp;

        for (const string& str : strs) {

            string key(26, '\0');

            for (char c : str) {
                key[c - 'a']++;
            }

            mp[key].push_back(str);
        }

        vector<vector<string>> ans;

        for (auto& [key, group] : mp) {
            ans.push_back(group);
        }

        return ans;
    }
};