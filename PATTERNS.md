# DSA Patterns

A practical index of the DSA techniques and problem-solving patterns
covered in **CodeVault**.

This file is organized by **problem-solving pattern**, not by the
problem's physical folder.

A problem may belong to more than one pattern.

---

## 1. Array Traversal & Manipulation

Basic traversal, indexing, construction, and direct array operations.

| # | Problem | Technique | LeetCode | Solution |
|---|---|---|---|---|
| 1480 | Running Sum of 1d Array | Running Sum / Traversal | [LeetCode](https://leetcode.com/problems/running-sum-of-1d-array/) | [Solution](./LeetCode/01-Arrays/1480-Running-Sum-of-1d-Array.cpp) |
| 1929 | Concatenation of Array | Array Construction | [LeetCode](https://leetcode.com/problems/concatenation-of-array/) | [Solution](./LeetCode/01-Arrays/1929-Concatenation-of-Array.cpp) |
| 1470 | Shuffle the Array | Index Mapping | [LeetCode](https://leetcode.com/problems/shuffle-the-array/) | [Solution](./LeetCode/01-Arrays/1470-Shuffle-the-Array.cpp) |
| 1431 | Kids With the Greatest Number of Candies | Maximum + Traversal | [LeetCode](https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/) | [Solution](./LeetCode/01-Arrays/1431-Kids-With-the-Greatest-Number-of-Candies.cpp) |
| 1672 | Richest Customer Wealth | 2D Array Traversal | [LeetCode](https://leetcode.com/problems/richest-customer-wealth/) | [Solution](./LeetCode/01-Arrays/1672-Richest-Customer-Wealth.cpp) |

---

## 2. Hashing

Use hash-based data structures for fast lookup and duplicate detection.

| # | Problem | Technique | LeetCode | Solution |
|---|---|---|---|---|
| 1 | Two Sum | Hash Map | [LeetCode](https://leetcode.com/problems/two-sum/) | [Solution](./LeetCode/01-Arrays/1-Two-Sum.cpp) |
| 217 | Contains Duplicate | Hash Set | [LeetCode](https://leetcode.com/problems/contains-duplicate/) | [Solution](./LeetCode/01-Arrays/217-Contains-Duplicate.cpp) |

---

## 3. Two Pointers

Use two indices to reduce unnecessary comparisons and process an array
efficiently.

### Same-Direction / In-Place

| # | Problem | Technique | LeetCode | Solution |
|---|---|---|---|---|
| 283 | Move Zeroes | Two Pointers — In-Place | [LeetCode](https://leetcode.com/problems/move-zeroes/) | [Solution](./LeetCode/01-Arrays/283-Move-Zeroes.cpp) |
| 26 | Remove Duplicates from Sorted Array | Two Pointers — In-Place | [LeetCode](https://leetcode.com/problems/remove-duplicates-from-sorted-array/) | [Solution](./LeetCode/01-Arrays/26-Remove-Duplicates-from-Sorted-Array.cpp) |
| 88 | Merge Sorted Array | Two Pointers — Reverse Traversal | [LeetCode](https://leetcode.com/problems/merge-sorted-array/) | [Solution](./LeetCode/01-Arrays/88-Merge-Sorted-Array.cpp) |

### Opposite-Direction

| # | Problem | Technique | LeetCode | Solution |
|---|---|---|---|---|
| 167 | Two Sum II - Input Array Is Sorted | Two Pointers — Opposite Direction | [LeetCode](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/) | [Solution](./LeetCode/01-Arrays/167-Two-Sum-II-Input-Array-Is-Sorted.cpp) |
| 11 | Container With Most Water | Two Pointers — Opposite Direction | [LeetCode](https://leetcode.com/problems/container-with-most-water/) | [Solution](./LeetCode/01-Arrays/11-Container-With-Most-Water.cpp) |

---

## 4. Sliding Window

Maintain a moving window over a contiguous portion of an array or string.

### Fixed-Size Window

| # | Problem | Technique | LeetCode | Solution |
|---|---|---|---|---|
| 643 | Maximum Average Subarray I | Fixed-Size Sliding Window | [LeetCode](https://leetcode.com/problems/maximum-average-subarray-i/) | [Solution](./LeetCode/01-Arrays/643-Maximum-Average-Subarray-I.cpp) |

---

## 5. Prefix Sum

Use cumulative sums to avoid repeatedly calculating sums.

| # | Problem | Technique | LeetCode | Solution |
|---|---|---|---|---|
| 724 | Find Pivot Index | Prefix Sum | [LeetCode](https://leetcode.com/problems/find-pivot-index/) | [Solution](./LeetCode/01-Arrays/724-Find-Pivot-Index.cpp) |

---

## 6. Prefix / Suffix

Combine information calculated from the left and right sides of an array.

| # | Problem | Technique | LeetCode | Solution |
|---|---|---|---|---|
| 238 | Product of Array Except Self | Prefix + Suffix Product | [LeetCode](https://leetcode.com/problems/product-of-array-except-self/) | [Solution](./LeetCode/01-Arrays/238-Product-of-Array-Except-Self.cpp) |

---

## 7. Kadane's Algorithm

Maintain the best subarray ending at the current position to find the
maximum-sum contiguous subarray.

| # | Problem | Technique | LeetCode | Solution |
|---|---|---|---|---|
| 53 | Maximum Subarray | Kadane's Algorithm | [LeetCode](https://leetcode.com/problems/maximum-subarray/) | [Solution](./LeetCode/01-Arrays/53-Maximum-Subarray.cpp) |

---

## 8. Greedy / One-Pass

Make the best decision possible at each step while scanning the input once.

| # | Problem | Technique | LeetCode | Solution |
|---|---|---|---|---|
| 121 | Best Time to Buy and Sell Stock | Minimum Price Tracking | [LeetCode](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) | [Solution](./LeetCode/01-Arrays/121-Best-Time-to-Buy-and-Sell-Stock.cpp) |

---

## 9. Bit Manipulation

Use bitwise properties to solve problems efficiently.

| # | Problem | Technique | LeetCode | Solution |
|---|---|---|---|---|
| 136 | Single Number | XOR | [LeetCode](https://leetcode.com/problems/single-number/) | [Solution](./LeetCode/01-Arrays/136-Single-Number.cpp) |
| 268 | Missing Number | XOR | [LeetCode](https://leetcode.com/problems/missing-number/) | [Solution](./LeetCode/01-Arrays/268-Missing-Number.cpp) |

---

## 10. In-Place Array Techniques

Use the input array itself to store information and avoid extra data structures.

| # | Problem | Technique | LeetCode | Solution |
|---|---|---|---|---|
| 448 | Find All Numbers Disappeared in an Array | Index Marking | [LeetCode](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/) | [Solution](./LeetCode/01-Arrays/448-Find-All-Numbers-Disappeared-in-an-Array.cpp) |

---

## 11. Boyer-Moore Voting

Maintain a candidate and vote count to find a majority element in
linear time and constant extra space.

| # | Problem | Technique | LeetCode | Solution |
|---|---|---|---|---|
| 169 | Majority Element | Boyer-Moore Voting Algorithm | [LeetCode](https://leetcode.com/problems/majority-element/) | [Solution](./LeetCode/01-Arrays/169-Majority-Element.cpp) |

---

## 12. Array Reversal

Use reversal operations to rearrange an array in-place.

| # | Problem | Technique | LeetCode | Solution |
|---|---|---|---|---|
| 189 | Rotate Array | Reversal Algorithm | [LeetCode](https://leetcode.com/problems/rotate-array/) | [Solution](./LeetCode/01-Arrays/189-Rotate-Array.cpp) |

---

## 13. Permutation

Manipulate elements according to lexicographical ordering.

| # | Problem | Technique | LeetCode | Solution |
|---|---|---|---|---|
| 31 | Next Permutation | Pivot + Successor + Reversal | [LeetCode](https://leetcode.com/problems/next-permutation/) | [Solution](./LeetCode/01-Arrays/31-Next-Permutation.cpp) |

---

## 14. Dutch National Flag

Partition an array into three regions using three pointers.

| # | Problem | Technique | LeetCode | Solution |
|---|---|---|---|---|
| 75 | Sort Colors | Dutch National Flag — 3 Pointers | [LeetCode](https://leetcode.com/problems/sort-colors/) | [Solution](./LeetCode/01-Arrays/75-Sort-Colors.cpp) |

---

# Pattern Notes

### Problems can have multiple patterns

A problem does not necessarily belong to only one pattern.

For example:

```text
Container With Most Water
→ Two Pointers

Product of Array Except Self
→ Prefix / Suffix

Two Sum II
→ Two Pointers

Two Sum
→ Hashing