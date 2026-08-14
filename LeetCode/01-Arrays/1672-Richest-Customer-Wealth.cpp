/**
 * 1672. Richest Customer Wealth
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/richest-customer-wealth/
 *
 * Problem:
 * Given an m x n integer grid accounts, where accounts[i][j] represents
 * the amount of money the ith customer has in the jth bank, return the
 * wealth of the richest customer.
 *
 * A customer's wealth is the total amount of money they have in all
 * their bank accounts.
 *
 * Example 1:
 * Input:  accounts = [[1,2,3],[3,2,1]]
 * Output: 6
 *
 * Example 2:
 * Input:  accounts = [[1,5],[7,3],[3,5]]
 * Output: 10
 *
 * Example 3:
 * Input:  accounts = [[2,8,7],[7,1,3],[1,9,5]]
 * Output: 17
 *
 * Approach:
 * Traverse each customer's accounts and calculate their total wealth.
 * Keep track of the maximum wealth found.
 *
 * Complexity:
 * Time: O(m × n)
 * Space: O(1)
 */

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = 0;

        for (int i = 0; i < accounts.size(); i++) {
            int wealth = 0;

            for (int j = 0; j < accounts[i].size(); j++) {
                wealth += accounts[i][j];
            }

            if (wealth > maxWealth) maxWealth = wealth;
        }

        return maxWealth;
    }
};