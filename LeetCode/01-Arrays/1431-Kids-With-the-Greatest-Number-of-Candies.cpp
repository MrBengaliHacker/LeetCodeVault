/**
 * 1431. Kids With the Greatest Number of Candies
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
 *
 * Problem:
 * Given an array candies and extraCandies, return a boolean array indicating
 * whether each kid can have the greatest number of candies after receiving
 * all the extraCandies.
 *
 * Example 1:
 * Input:  candies = [2,3,5,1,3], extraCandies = 3
 * Output: [true,true,true,false,true]
 *
 * Example 2:
 * Input:  candies = [4,2,1,1,2], extraCandies = 1
 * Output: [true,false,false,false,false]
 *
 * Example 3:
 * Input:  candies = [12,1,12], extraCandies = 10
 * Output: [true,false,true]
 *
 * Approach:
 * Find the current maximum number of candies, then check whether each kid
 * can reach or exceed that maximum after receiving all extraCandies.
 *
 * Complexity:
 * Time: O(n)
 * Space: O(n)
 */

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result;
        result.reserve(candies.size());

        int maxCandies = *max_element(candies.begin(), candies.end());

        for (int i = 0; i < candies.size(); i++) {
            result.push_back(candies[i] + extraCandies >= maxCandies);
        }

        return result;
    }
};