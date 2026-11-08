# LeetCodeVault

<div align="center">

![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![Problems](https://img.shields.io/badge/Problems%20Solved-73-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)
![Status](https://img.shields.io/badge/Status-Active%20Prep-2EA44F?style=for-the-badge&logo=githubactions&logoColor=white)
![Pattern Index](https://img.shields.io/badge/Index-PATTERNS.md-8A2BE2?style=for-the-badge&logo=markdown&logoColor=white)

A structured collection of LeetCode solutions in modern C++, architected for efficient technical interview revision.

[Explore Patterns](./PATTERNS.md) • [Topic Index](#topic-index) • [Solution Template](#solution-file-standard) • [Roadmap](#curriculum-roadmap)

</div>

---

## Repository Overview

`LeetCodeVault` documents clean, readable, and space-conscious C++ implementations across all major DSA topics. Every solution follows consistent repository conventions:

* **Algorithmic Rigor:** Prioritizes optimal time/space solutions, while documenting intuitive or alternative techniques (e.g., Two-Pass, Sorting, or Recursive counterparts) for follow-up discussions.
* **Modern C++ Standards:** Written in modern C++ with idiomatic practices—using `nullptr`, RAII/stack allocations to prevent memory leaks, explicit resource cleanup where heap memory is used, and STL primitives.
* **Structured Documentation:** Every file contains complete problem descriptions, examples, boundary conditions, conceptual intuition, step-by-step algorithms, and exact complexity breakdowns.
* **Dual Indexing:** Navigate problems sequentially by data structure in this file, or by algorithmic strategy in **[`PATTERNS.md`](./PATTERNS.md)**.

---

## Progress Dashboard

| Category | Folder | Status | Solved | Target |
|:---|:---|:---:|:---:|:---:|
| **00. Basics** | [`00-Programming-Basics`](./LeetCode/00-Programming-Basics) | Completed | 5 | 5 |
| **01. Arrays** | [`01-Arrays`](./LeetCode/01-Arrays) | Completed | 30 | 30 |
| **02. Strings** | [`02-Strings`](./LeetCode/02-Strings) | Completed | 30 | 30 |
| **03. Linked Lists** | [`03-Linked-Lists`](./LeetCode/03-Linked-Lists) | In Progress | 4 | 23 |
| **Total** | — | **Active** | **69** | **85+** |

---

## Topic Index

### 00 - Programming Basics

📁 **Directory:** [`./LeetCode/00-Programming-Basics`](./LeetCode/00-Programming-Basics) • **5/5** ✅ Complete

| # | Problem | Difficulty | Primary Technique |
|---|---------|-----------|-----------|
| 2235 | [Add Two Integers](./LeetCode/00-Programming-Basics/2235-Add-Two-Integers.cpp) | Easy | Basic Arithmetic |
| 412 | [Fizz Buzz](./LeetCode/00-Programming-Basics/412-Fizz-Buzz.cpp) | Easy | Conditionals |
| 1342 | [Number of Steps to Reduce a Number to Zero](./LeetCode/00-Programming-Basics/1342-Number-of-Steps-to-Reduce-a-Number-to-Zero.cpp) | Easy | Loops / Bit Manipulation |
| 1281 | [Subtract the Product and Sum of Digits](./LeetCode/00-Programming-Basics/1281-Subtract-the-Product-and-Sum-of-Digits.cpp) | Easy | Digit Manipulation |
| 258 | [Add Digits](./LeetCode/00-Programming-Basics/258-Add-Digits.cpp) | Easy | Digit Manipulation |

---

### 01 - Arrays

📁 **Directory:** [`./LeetCode/01-Arrays`](./LeetCode/01-Arrays) • **30/30** ✅ Complete

| # | Problem | Difficulty | Primary Technique |
|---|---------|-----------|-----------|
| 1480 | [Running Sum of 1d Array](./LeetCode/01-Arrays/1480-Running-Sum-of-1d-Array.cpp) | Easy | Running Sum |
| 1929 | [Concatenation of Array](./LeetCode/01-Arrays/1929-Concatenation-of-Array.cpp) | Easy | Array Construction |
| 1470 | [Shuffle the Array](./LeetCode/01-Arrays/1470-Shuffle-the-Array.cpp) | Easy | Index Mapping |
| 1431 | [Kids With the Greatest Number of Candies](./LeetCode/01-Arrays/1431-Kids-With-the-Greatest-Number-of-Candies.cpp) | Easy | Traversal + Maximum |
| 1672 | [Richest Customer Wealth](./LeetCode/01-Arrays/1672-Richest-Customer-Wealth.cpp) | Easy | 2D Array Traversal |
| 1 | [Two Sum](./LeetCode/01-Arrays/1-Two-Sum.cpp) | Easy | Hashing |
| 217 | [Contains Duplicate](./LeetCode/01-Arrays/217-Contains-Duplicate.cpp) | Easy | Hashing |
| 121 | [Best Time to Buy and Sell Stock](./LeetCode/01-Arrays/121-Best-Time-to-Buy-and-Sell-Stock.cpp) | Easy | Greedy / One-Pass |
| 136 | [Single Number](./LeetCode/01-Arrays/136-Single-Number.cpp) | Easy | Bit Manipulation / XOR |
| 268 | [Missing Number](./LeetCode/01-Arrays/268-Missing-Number.cpp) | Easy | Bit Manipulation / XOR |
| 448 | [Find All Numbers Disappeared in an Array](./LeetCode/01-Arrays/448-Find-All-Numbers-Disappeared-in-an-Array.cpp) | Easy | In-Place Index Marking |
| 283 | [Move Zeroes](./LeetCode/01-Arrays/283-Move-Zeroes.cpp) | Easy | Two Pointers |
| 167 | [Two Sum II - Input Array Is Sorted](./LeetCode/01-Arrays/167-Two-Sum-II-Input-Array-Is-Sorted.cpp) | Medium | Two Pointers |
| 26 | [Remove Duplicates from Sorted Array](./LeetCode/01-Arrays/26-Remove-Duplicates-from-Sorted-Array.cpp) | Easy | Two Pointers |
| 88 | [Merge Sorted Array](./LeetCode/01-Arrays/88-Merge-Sorted-Array.cpp) | Easy | Two Pointers |
| 169 | [Majority Element](./LeetCode/01-Arrays/169-Majority-Element.cpp) | Easy | Boyer-Moore Voting |
| 189 | [Rotate Array](./LeetCode/01-Arrays/189-Rotate-Array.cpp) | Medium | Array Reversal |
| 31 | [Next Permutation](./LeetCode/01-Arrays/31-Next-Permutation.cpp) | Medium | Permutation |
| 53 | [Maximum Subarray](./LeetCode/01-Arrays/53-Maximum-Subarray.cpp) | Medium | Kadane's Algorithm |
| 724 | [Find Pivot Index](./LeetCode/01-Arrays/724-Find-Pivot-Index.cpp) | Easy | Prefix Sum |
| 238 | [Product of Array Except Self](./LeetCode/01-Arrays/238-Product-of-Array-Except-Self.cpp) | Medium | Prefix / Suffix |
| 643 | [Maximum Average Subarray I](./LeetCode/01-Arrays/643-Maximum-Average-Subarray-I.cpp) | Easy | Sliding Window |
| 75 | [Sort Colors](./LeetCode/01-Arrays/75-Sort-Colors.cpp) | Medium | Dutch National Flag |
| 11 | [Container With Most Water](./LeetCode/01-Arrays/11-Container-With-Most-Water.cpp) | Medium | Two Pointers |
| 42 | [Trapping Rain Water](./LeetCode/01-Arrays/42-Trapping-Rain-Water.cpp) | Hard | Two Pointers + Left/Right Maximum |
| 15 | [3Sum](./LeetCode/01-Arrays/15-3Sum.cpp) | Medium | Sorting + Two Pointers |
| 56 | [Merge Intervals](./LeetCode/01-Arrays/56-Merge-Intervals.cpp) | Medium | Intervals + Sorting |
| 560 | [Subarray Sum Equals K](./LeetCode/01-Arrays/560-Subarray-Sum-Equals-K.cpp) | Medium | Prefix Sum + Hash Map |
| 41 | [First Missing Positive](./LeetCode/01-Arrays/41-First-Missing-Positive.cpp) | Hard | In-Place Index Mapping / Cyclic Placement |
| 704 | [Binary Search](./LeetCode/01-Arrays/704-Binary-Search.cpp) | Easy | Binary Search |

---

### 02 - Strings

📁 **Directory:** [`./LeetCode/02-Strings`](./LeetCode/02-Strings) — **30/30** ✅ Complete

| # | Problem | Difficulty | Primary Technique |
|---|---|---|---|
| 709 | [To Lower Case](./LeetCode/02-Strings/709-To-Lower-Case.cpp) | Easy | Character Manipulation |
| 58 | [Length of Last Word](./LeetCode/02-Strings/58-Length-of-Last-Word.cpp) | Easy | Reverse Traversal |
| 1768 | [Merge Strings Alternately](./LeetCode/02-Strings/1768-Merge-Strings-Alternately.cpp) | Easy | String Traversal |
| 14 | [Longest Common Prefix](./LeetCode/02-Strings/14-Longest-Common-Prefix.cpp) | Easy | String Traversal |
| 28 | [Find the Index of the First Occurrence in a String](./LeetCode/02-Strings/28-Find-the-Index-of-the-First-Occurrence-in-a-String.cpp) | Easy | String Matching |
| 13 | [Roman to Integer](./LeetCode/02-Strings/13-Roman-to-Integer.cpp) | Easy | Right-to-Left Traversal + Hash Map |
| 344 | [Reverse String](./LeetCode/02-Strings/344-Reverse-String.cpp) | Easy | Two Pointers — Opposite Direction |
| 541 | [Reverse String II](./LeetCode/02-Strings/541-Reverse-String-II.cpp) | Easy | Two Pointers — In-Place Reversal |
| 125 | [Valid Palindrome](./LeetCode/02-Strings/125-Valid-Palindrome.cpp) | Easy | Two Pointers + Character Filtering |
| 392 | [Is Subsequence](./LeetCode/02-Strings/392-Is-Subsequence.cpp) | Easy | Two Pointers — Same Direction |
| 345 | [Reverse Vowels of a String](./LeetCode/02-Strings/345-Reverse-Vowels-of-a-String.cpp) | Easy | Two Pointers — Opposite Direction |
| 680 | [Valid Palindrome II](./LeetCode/02-Strings/680-Valid-Palindrome-II.cpp) | Easy | Two Pointers — Opposite Direction |
| 242 | [Valid Anagram](./LeetCode/02-Strings/242-Valid-Anagram.cpp) | Easy | Frequency Counting |
| 383 | [Ransom Note](./LeetCode/02-Strings/383-Ransom-Note.cpp) | Easy | Frequency Counting |
| 387 | [First Unique Character in a String](./LeetCode/02-Strings/387-First-Unique-Character-in-a-String.cpp) | Easy | Frequency Counting |
| 205 | [Isomorphic Strings](./LeetCode/02-Strings/205-Isomorphic-Strings.cpp) | Easy | Character Mapping / Bijection |
| 290 | [Word Pattern](./LeetCode/02-Strings/290-Word-Pattern.cpp) | Easy | Character Mapping / Bijection |
| 49 | [Group Anagrams](./LeetCode/02-Strings/49-Group-Anagrams.cpp) | Medium | Frequency Counting + Hashing |
| 3 | [Longest Substring Without Repeating Characters](./LeetCode/02-Strings/3-Longest-Substring-Without-Repeating-Characters.cpp) | Medium | Sliding Window + Last Occurrence Tracking |
| 567 | [Permutation in String](./LeetCode/02-Strings/567-Permutation-in-String.cpp) | Medium | Fixed-Size Sliding Window + Frequency Counting |
| 438 | [Find All Anagrams in a String](./LeetCode/02-Strings/438-Find-All-Anagrams-in-a-String.cpp) | Medium | Fixed-Size Sliding Window + Frequency Counting |
| 424 | [Longest Repeating Character Replacement](./LeetCode/02-Strings/424-Longest-Repeating-Character-Replacement.cpp) | Medium | Variable-Size Sliding Window + Frequency Counting |
| 151 | [Reverse Words in a String](./LeetCode/02-Strings/151-Reverse-Words-in-a-String.cpp) | Medium | In-Place String Manipulation + Reversal |
| 443 | [String Compression](./LeetCode/02-Strings/443-String-Compression.cpp) | Medium | Two Pointers + In-Place Array Manipulation |
| 5 | [Longest Palindromic Substring](./LeetCode/02-Strings/5-Longest-Palindromic-Substring.cpp) | Medium | Expand Around Center |
| 647 | [Palindromic Substrings](./LeetCode/02-Strings/647-Palindromic-Substrings.cpp) | Medium | Expand Around Center |
| 6 | [Zigzag Conversion](./LeetCode/02-Strings/6-Zigzag-Conversion.cpp) | Medium | Cycle Pattern / Mathematical Traversal |
| 12 | [Integer to Roman](./LeetCode/02-Strings/12-Integer-to-Roman.cpp) | Medium | Greedy / One-Pass |
| 43 | [Multiply Strings](./LeetCode/02-Strings/43-Multiply-Strings.cpp) | Medium | Array Simulation / Grade-School Multiplication |
| 76 | [Minimum Window Substring](./LeetCode/02-Strings/76-Minimum-Window-Substring.cpp) | Hard | Variable-Size Sliding Window + Frequency Counting |

---

### 03 - Linked Lists

📁 **Directory:** [`./LeetCode/03-Linked-Lists`](./LeetCode/03-Linked-Lists) — **8/23** 🚧 In Progress

| # | Problem | Difficulty | Primary Technique |
|---|---|---|---|
| 206 | [Reverse Linked List](./LeetCode/03-Linked-Lists/206-Reverse-Linked-List.cpp) | Easy | Iterative Linked List Reversal |
| 876 | [Middle of the Linked List](./LeetCode/03-Linked-Lists/876-Middle-of-the-Linked-List.cpp) | Easy | Two Pointers — Fast & Slow |
| 21 | [Merge Two Sorted Lists](./LeetCode/03-Linked-Lists/21-Merge-Two-Sorted-Lists.cpp) | Easy | Recursive Merging / Two Pointers + Dummy Node |
| 203 | [Remove Linked List Elements](./LeetCode/03-Linked-Lists/203-Remove-Linked-List-Elements.cpp) | Easy | Dummy Node + In-Place Removal |
| 82 | [Remove Duplicates from Sorted List II](./LeetCode/03-Linked-Lists/82-Remove-Duplicates-from-Sorted-List-II.cpp) | Medium | Dummy Node + Two Pointers |
| 141 | [Linked List Cycle](./LeetCode/03-Linked-Lists/141-Linked-List-Cycle.cpp) | Easy | Fast & Slow Pointers |
| 142 | [Linked List Cycle II](./LeetCode/03-Linked-Lists/142-Linked-List-Cycle-II.cpp) | Medium | Two Pointers — Fast & Slow |
| 19 | [Remove Nth Node From End of List](./LeetCode/03-Linked-Lists/19-Remove-Nth-Node-From-End-of-List.cpp) | Medium | Two Pointers — Fast & Slow (Fixed Gap) |

---

## Solution File Standard

To maintain high code quality and consistency across all topics (Arrays, Strings, Trees, Graphs, DP, Linked Lists), every solution file adheres to this blueprint:

```cpp
/**
 * [Number]. [Problem Title]
 * Difficulty: [Easy | Medium | Hard]
 * Link: [https://leetcode.com/problems/](https://leetcode.com/problems/)[problem-slug]/
 *
 * Problem:
 * [Formal problem statement]
 *
 * Examples:
 * [Input / Output / Explanation test cases]
 *
 * Constraints:
 * [Data ranges and input boundaries]
 *
 * ============================================================
 * Approach 1: [Primary / Optimal Technique Name]
 * ============================================================
 *
 * Technique:
 * [Pattern / Sub-pattern classification matching PATTERNS.md]
 *
 * Key Idea:
 * [Core invariant, mathematical property, or algorithmic observation]
 *
 * Steps:
 * 1. [Ordered execution flow]
 * 2. [...]
 * 3. [...]
 *
 * Complexity:
 * - Time:  O(...) — [Justification with pass counts or tree depth]
 * - Space: O(...) — [Justification covering auxiliary structures/stack]
 *
 * ============================================================
 * Approach 2: [Alternative / Follow-up Technique (if applicable)]
 * ============================================================
 * [Same structure: Technique, Key Idea, Steps, Complexity]
 */

// Necessary headers or custom struct definitions (ListNode, TreeNode, etc.)

class Solution {
public:
    // Primary optimal solution
    // Alternative method (if included)
};
```

---

## Curriculum Roadmap
```
Phase 1: Linear Data Structures (Current)
├── 00 - Programming Basics     [5/5]   ✅ Complete
├── 01 - Arrays                 [30/30] ✅ Complete
├── 02 - Strings                [30/30] ✅ Complete
├── 03 - Linked Lists           [4/23]  🚧 In Progress
├── 04 - Stacks & Monotonic Stacks
└── 05 - Queues & Deques

Phase 2: Trees & Graph Traversals
├── 06 - Binary Trees & BSTs
├── 07 - Binary Search Trees (Advanced)
├── 08 - Heaps & Priority Queues
└── 09 - Graph Theory (BFS, DFS, Topo Sort)

Phase 3: Advanced Optimization & Algorithms
├── 10 - Backtracking
├── 11 - Greedy Strategies
├── 12 - Dynamic Programming (1D, 2D, Knapsack, Intervals)
└── 13 - Advanced Graphs (Dijkstra, Bellman-Ford, DSU)
```

---

## Author

**Ritam Mondal**

- GitHub: [MrBengaliHacker](https://github.com/MrBengaliHacker)

---

⭐ If this repository assists your technical interview preparation, consider starring the repo.
