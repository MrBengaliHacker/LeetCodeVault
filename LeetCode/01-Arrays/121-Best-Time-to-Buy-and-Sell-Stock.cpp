/**
 * 121. Best Time to Buy and Sell Stock
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 *
 * Problem:
 * You are given an array prices where prices[i] is the price of a stock
 * on the ith day.
 *
 * Choose one day to buy one stock and a different day in the future to
 * sell it. Return the maximum profit you can achieve.
 *
 * If no profit can be achieved, return 0.
 *
 * Example 1:
 * Input:  prices = [7,1,5,3,6,4]
 * Output: 5
 *
 * Explanation:
 * Buy on day 2 at price 1 and sell on day 5 at price 6.
 * Profit = 6 - 1 = 5.
 *
 * Example 2:
 * Input:  prices = [7,6,4,3,1]
 * Output: 0
 *
 * Explanation:
 * Prices continuously decrease, so no profitable transaction is possible.
 *
 * Technique:
 * Greedy + One-Pass Minimum Tracking
 *
 * Key Idea:
 * For every selling day, the best possible buying price is the minimum
 * price seen before that day.
 *
 * Approach:
 * Traverse the array once while maintaining:
 *
 * 1. minPrice  - the lowest stock price seen so far.
 * 2. maxProfit - the maximum profit found so far.
 *
 * For each price, calculate the profit from buying at minPrice and selling
 * at the current price. Update maxProfit if this profit is better.
 * Then update minPrice if the current price is lower.
 *
 * This greedy approach works because keeping the cheapest previous buying
 * price always gives the best possible profit for the current selling price.
 *
 * Complexity:
 * Time: O(n)
 * Space: O(1)
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); i++) {
            int profit = prices[i] - minPrice;
            maxProfit = max(maxProfit, profit);

            minPrice = min(minPrice, prices[i]);
        }

        return maxProfit;
    }
};