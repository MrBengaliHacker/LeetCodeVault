/**
 * 560. Subarray Sum Equals K
 *
 * Difficulty: Medium
 *
 * Link:
 * https://leetcode.com/problems/subarray-sum-equals-k/
 *
 * Problem:
 * Given an array of integers nums and an integer k,
 * return the total number of subarrays whose sum equals k.
 *
 * A subarray is a contiguous non-empty sequence of elements within an array.
 *
 * Example 1:
 * Input:  nums = [1,1,1], k = 2
 * Output: 2
 *
 * Explanation:
 * The subarrays [1,1] at positions (0,1) and (1,2)
 * both have sum 2.
 *
 * Example 2:
 * Input:  nums = [1,2,3], k = 3
 * Output: 2
 *
 * Explanation:
 * The subarrays [1,2] and [3] have sum 3.
 *
 * Technique:
 * Prefix Sum + Hash Map
 *
 * Key Idea:
 * Let prefixSum be the sum of elements from the beginning up to
 * the current position.
 *
 * If prefixSum - k has appeared before, then the elements between
 * that previous prefix sum and the current position form a
 * subarray with sum k.
 *
 * Store the frequency of each prefix sum in a hash map.
 *
 * Approach:
 * 1. Initialize prefixSum = 0 and count = 0.
 * 2. Store prefix sum 0 with frequency 1.
 * 3. Traverse the array.
 * 4. Add the current element to prefixSum.
 * 5. Check whether prefixSum - k exists in the map.
 * 6. If it exists, add its frequency to count.
 * 7. Store the current prefixSum in the map.
 * 8. Return count.
 *
 * Dry Run:
 * nums = [1,1,1], k = 2
 *
 * Start:
 * prefixSum = 0
 * count = 0
 * map = {0:1}
 *
 * Step 1:
 * prefixSum = 1
 * prefixSum - k = -1 → not found
 * map = {0:1, 1:1}
 *
 * Step 2:
 * prefixSum = 2
 * prefixSum - k = 0 → found
 * count = 1
 * map = {0:1, 1:1, 2:1}
 *
 * Step 3:
 * prefixSum = 3
 * prefixSum - k = 1 → found
 * count = 2
 *
 * Final:
 * count = 2
 *
 * Complexity:
 * Time: O(n) average
 * Space: O(n)
 */

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefixSum = 0;
        int count = 0;

        unordered_map<int, int> freq;
        freq[0] = 1;

        for (int num : nums) {
            prefixSum += num;

            if (freq.find(prefixSum - k) != freq.end()) {
                count += freq[prefixSum - k];
            }

            freq[prefixSum]++;
        }

        return count;
    }
};