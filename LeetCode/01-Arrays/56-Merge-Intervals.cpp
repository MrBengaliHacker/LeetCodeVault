/**
 * 56. Merge Intervals
 *
 * Difficulty: Medium
 *
 * Link:
 * https://leetcode.com/problems/merge-intervals/
 *
 * Problem:
 * Given an array of intervals where intervals[i] = [starti, endi],
 * merge all overlapping intervals, and return an array of the
 * non-overlapping intervals that cover all the intervals in the input.
 *
 * Example 1:
 * Input:  intervals = [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 *
 * Explanation:
 * Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
 *
 * Example 2:
 * Input:  intervals = [[1,4],[4,5]]
 * Output: [[1,5]]
 *
 * Explanation:
 * Intervals [1,4] and [4,5] are considered overlapping.
 *
 * Example 3:
 * Input:  intervals = [[4,7],[1,4]]
 * Output: [[1,7]]
 *
 * Explanation:
 * Intervals [1,4] and [4,7] are considered overlapping.
 *
 * Technique:
 * Sorting + Interval Merging
 *
 * Key Idea:
 * Sort intervals by their starting value.
 *
 * Then compare each interval with the last interval in the result:
 *
 * NO OVERLAP:
 *     previous.end < current.start
 *     → intervals are separate, add the current interval.
 *
 * OVERLAP:
 *     current.start <= previous.end
 *     → intervals overlap, merge by extending the end value.
 *
 * The code checks the NO OVERLAP condition
 * (result.back()[1] < interval[0]) and merges in the else branch,
 * which covers the OVERLAP case.
 *
 * Approach:
 * 1. Sort all intervals by their starting value.
 * 2. Create an empty result array.
 * 3. Traverse each interval.
 * 4. If result is empty or there is no overlap, add the interval.
 * 5. Otherwise, merge it with the last interval.
 * 6. Continue until all intervals are processed.
 *
 * Dry Run:
 * intervals = [[1,3],[2,6],[8,10],[15,18]]
 *
 * Start:
 * result = []
 *
 * [1,3] → result is empty → add
 * result = [[1,3]]
 *
 * [2,6] → 2 <= 3 → overlap
 * merge [1,3] and [2,6]
 * result = [[1,6]]
 *
 * [8,10] → 8 > 6 → no overlap
 * result = [[1,6],[8,10]]
 *
 * [15,18] → 15 > 10 → no overlap
 * result = [[1,6],[8,10],[15,18]]
 *
 * Final:
 * [[1,6],[8,10],[15,18]]
 *
 * Complexity:
 * Time: O(n log n)
 * Space: O(n) for the output
 */

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;

        for (auto interval : intervals) {
            if (result.empty() || result.back()[1] < interval[0]) {
                result.push_back(interval);
            }
            else {
                result.back()[1] = 
                    max(result.back()[1], interval[1]);
            }
        }

        return result;
    }
};