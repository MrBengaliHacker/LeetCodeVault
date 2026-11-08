# DSA Patterns & Problem-Solving Index

A structured reference to the data structures and algorithms
patterns explored throughout **LeetCodeVault**.

This index organizes problems by their underlying problem-solving
techniques rather than their directory structure, making it easier
to study, recognize, and revise recurring algorithmic patterns.

> A problem may appear under multiple patterns when it demonstrates more than one important technique.

---

## Pattern Navigation

- [1. Two Pointers](#1-two-pointers)
  - [Opposite-Direction](#opposite-direction)
  - [Same-Direction / In-Place](#same-direction--in-place)
  - [Fast & Slow Pointers](#fast--slow-pointers)
  - [Dutch National Flag](#dutch-national-flag)
- [2. Sliding Window](#2-sliding-window)
  - [Fixed-Size Window](#fixed-size-window)
  - [Variable-Size Window](#variable-size-window)
- [3. Hashing & Frequency Counting](#3-hashing--frequency-counting)
  - [Hash Set & Hash Map](#hash-set--hash-map)
  - [Frequency Counting](#frequency-counting)
  - [Character Mapping / Bijection](#character-mapping--bijection)
- [4. Prefix Sum & Prefix / Suffix](#4-prefix-sum--prefix--suffix)
- [5. In-Place](#5-in-place)
  - [In-Place Array Techniques, Reversal & Permutations](#in-place-array-techniques-reversal--permutations)
  - [In-Place String Manipulation](#in-place-string-manipulation)(#5-in-place-array-techniques-reversal--permutations)
- [6. Kadane's Algorithm & Running State](#6-kadanes-algorithm--running-state)
- [7. Binary Search](#7-binary-search)
- [8. Bit Manipulation & Basic Operations](#8-bit-manipulation--basic-operations)
- [9. Intervals](#9-intervals)
- [10. Linked List Reversal](#10-linked-list-reversal)
- [11. Palindrome (Expand Around Center)](#11-palindrome-expand-around-center)
- [12. String Traversal, Matching & Simulation](#12-string-traversal-matching--simulation)
- [13. Array Traversal & Construction](#13-array-traversal--construction)

---

## 1. Two Pointers

Use two indices to reduce unnecessary comparisons and process arrays or strings efficiently.

### Opposite-Direction

| # | Problem | Technique | LeetCode | Solution |
|---|---|---|---|---|
| 167 | Two Sum II - Input Array Is Sorted | Two Pointers — Opposite Direction | [LeetCode](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/) | [Solution](./LeetCode/01-Arrays/167-Two-Sum-II-Input-Array-Is-Sorted.cpp) |
| 11 | Container With Most Water | Two Pointers — Opposite Direction | [LeetCode](https://leetcode.com/problems/container-with-most-water/) | [Solution](./LeetCode/01-Arrays/11-Container-With-Most-Water.cpp) |
| 42 | Trapping Rain Water | Two Pointers — Left/Right Maximum | [LeetCode](https://leetcode.com/problems/trapping-rain-water/) | [Solution](./LeetCode/01-Arrays/42-Trapping-Rain-Water.cpp) |
| 15 | 3Sum | Sorting + Two Pointers | [LeetCode](https://leetcode.com/problems/3sum/) | [Solution](./LeetCode/01-Arrays/15-3Sum.cpp) |
| 344 | Reverse String | Two Pointers — Opposite Direction | [LeetCode](https://leetcode.com/problems/reverse-string/) | [Solution](./LeetCode/02-Strings/344-Reverse-String.cpp) |
| 125 | Valid Palindrome | Two Pointers — Opposite Direction | [LeetCode](https://leetcode.com/problems/valid-palindrome/) | [Solution](./LeetCode/02-Strings/125-Valid-Palindrome.cpp) |
| 345 | Reverse Vowels of a String | Two Pointers — Opposite Direction | [LeetCode](https://leetcode.com/problems/reverse-vowels-of-a-string/) | [Solution](./LeetCode/02-Strings/345-Reverse-Vowels-of-a-String.cpp) |
| 680 | Valid Palindrome II | Two Pointers — Opposite Direction | [LeetCode](https://leetcode.com/problems/valid-palindrome-ii/) | [Solution](./LeetCode/02-Strings/680-Valid-Palindrome-II.cpp) |

### Same-Direction / In-Place

| # | Problem | Technique | LeetCode | Solution |
|---|---|---|---|---|
| 283 | Move Zeroes | Two Pointers — In-Place | [LeetCode](https://leetcode.com/problems/move-zeroes/) | [Solution](./LeetCode/01-Arrays/283-Move-Zeroes.cpp) |
| 26 | Remove Duplicates from Sorted Array | Two Pointers — In-Place | [LeetCode](https://leetcode.com/problems/remove-duplicates-from-sorted-array/) | [Solution](./LeetCode/01-Arrays/26-Remove-Duplicates-from-Sorted-Array.cpp) |
| 88 | Merge Sorted Array | Two Pointers — Reverse Traversal | [LeetCode](https://leetcode.com/problems/merge-sorted-array/) | [Solution](./LeetCode/01-Arrays/88-Merge-Sorted-Array.cpp) |
| 541 | Reverse String II | Two Pointers — In-Place Reversal | [LeetCode](https://leetcode.com/problems/reverse-string-ii/) | [Solution](./LeetCode/02-Strings/541-Reverse-String-II.cpp) |
| 392 | Is Subsequence | Two Pointers — Same Direction | [LeetCode](https://leetcode.com/problems/is-subsequence/) | [Solution](./LeetCode/02-Strings/392-Is-Subsequence.cpp) |
| 443 | String Compression | Two Pointers + In-Place Array Manipulation | [LeetCode](https://leetcode.com/problems/string-compression/) | [Solution](./LeetCode/02-Strings/443-String-Compression.cpp) |
| 21 | Merge Two Sorted Lists | Recursive Merging / Two Pointers + Dummy Node | [LeetCode](https://leetcode.com/problems/merge-two-sorted-lists/) | [Solution](./LeetCode/03-Linked-Lists/21-Merge-Two-Sorted-Lists.cpp) |
| 203 | Remove Linked List Elements | Dummy Node + In-Place Removal | [LeetCode](https://leetcode.com/problems/remove-linked-list-elements/) | [Solution](./LeetCode/03-Linked-Lists/203-Remove-Linked-List-Elements.cpp) |
| 82 | Remove Duplicates from Sorted List II | Dummy Node + Two Pointers | [LeetCode](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/) | [Solution](./LeetCode/03-Linked-Lists/82-Remove-Duplicates-from-Sorted-List-II.cpp) |

### Fast & Slow Pointers

Use two pointers moving at different speeds to find middle nodes, detect cycles, or locate specific positions in a linked list.

| # | Problem | Technique | LeetCode | Solution |
|---|---|---|---|---|
| 876 | Middle of the Linked List | Fast & Slow Pointers | [LeetCode](https://leetcode.com/problems/middle-of-the-linked-list/) | [Solution](./LeetCode/03-Linked-Lists/876-Middle-of-the-Linked-List.cpp) |
| 141 | Linked List Cycle | Fast & Slow Pointers | [LeetCode](https://leetcode.com/problems/linked-list-cycle/) | [Solution](./LeetCode/03-Linked-Lists/141-Linked-List-Cycle.cpp) |
| 142 | Linked List Cycle II | Fast & Slow Pointers | [LeetCode](https://leetcode.com/problems/linked-list-cycle-ii/) | [Solution](./LeetCode/03-Linked-Lists/142-Linked-List-Cycle-II.cpp) |
| 19 | Remove Nth Node From End of List | Two Pointers — Fast & Slow (Fixed Gap) | [LeetCode](https://leetcode.com/problems/remove-nth-node-from-end-of-list/) | [Solution](./LeetCode/03-Linked-Lists/19-Remove-Nth-Node-From-End-of-List.cpp) |

### Dutch National Flag

| # | Problem | Technique | LeetCode | Solution |
|---|---|---|---|---|
| 75 | Sort Colors | Dutch National Flag — 3 Pointers | [LeetCode](https://leetcode.com/problems/sort-colors/) | [Solution](./LeetCode/01-Arrays/75-Sort-Colors.cpp) |

---

## 2. Sliding Window

Maintain a moving window over a contiguous portion of an array or string.

### Fixed-Size Window

| # | Problem | Technique | LeetCode | Solution |
|---|---|---|---|---|
| 643 | Maximum Average Subarray I | Fixed-Size Sliding Window | [LeetCode](https://leetcode.com/problems/maximum-average-subarray-i/) | [Solution](./LeetCode/01-Arrays/643-Maximum-Average-Subarray-I.cpp) |
| 567 | Permutation in String | Fixed-Size Sliding Window + Frequency Counting | [LeetCode](https://leetcode.com/problems/permutation-in-string/) | [Solution](./LeetCode/02-Strings/567-Permutation-in-String.cpp) |
| 438 | Find All Anagrams in a String | Fixed-Size Sliding Window + Frequency Counting | [LeetCode](https://leetcode.com/problems/find-all-anagrams-in-a-string/) | [Solution](./LeetCode/02-Strings/438-Find-All-Anagrams-in-a-String.cpp) |

### Variable-Size Window

| # | Problem | Technique | LeetCode | Solution |
|---|---|---|---|---|
| 3 | Longest Substring Without Repeating Characters | Variable-Size Sliding Window + Last Occurrence Tracking | [LeetCode](https://leetcode.com/problems/longest-substring-without-repeating-characters/) | [Solution](./LeetCode/02-Strings/3-Longest-Substring-Without-Repeating-Characters.cpp) |
| 424 | Longest Repeating Character Replacement | Variable-Size Sliding Window + Frequency Counting | [LeetCode](https://leetcode.com/problems/longest-repeating-character-replacement/) | [Solution](./LeetCode/02-Strings/424-Longest-Repeating-Character-Replacement.cpp) |
| 76 | Minimum Window Substring | Variable-Size Sliding Window + Frequency Counting | [LeetCode](https://leetcode.com/problems/minimum-window-substring/) | [Solution](./LeetCode/02-Strings/76-Minimum-Window-Substring.cpp) |

---

## 3. Hashing & Frequency Counting

Use hash-based data structures or frequency arrays for fast lookup, anagram detection, and mappings.

### Hash Set & Hash Map

| # | Problem | Technique | LeetCode | Solution |
|---|---|---|---|---|
| 1 | Two Sum | Hash Map | [LeetCode](https://leetcode.com/problems/two-sum/) | [Solution](./LeetCode/01-Arrays/1-Two-Sum.cpp) |
| 217 | Contains Duplicate | Hash Set | [LeetCode](https://leetcode.com/problems/contains-duplicate/) | [Solution](./LeetCode/01-Arrays/217-Contains-Duplicate.cpp) |

### Frequency Counting

| # | Problem | Technique | LeetCode | Solution |
|---|---|---|---|---|
| 242 | Valid Anagram | Character Frequency Counting | [LeetCode](https://leetcode.com/problems/valid-anagram/) | [Solution](./LeetCode/02-Strings/242-Valid-Anagram.cpp) |
| 383 | Ransom Note | Character Frequency Counting | [LeetCode](https://leetcode.com/problems/ransom-note/) | [Solution](./LeetCode/02-Strings/383-Ransom-Note.cpp) |
| 387 | First Unique Character in a String | Character Frequency Counting | [LeetCode](https://leetcode.com/problems/first-unique-character-in-a-string/) | [Solution](./LeetCode/02-Strings/387-First-Unique-Character-in-a-String.cpp) |
| 49 | Group Anagrams | Frequency Counting + Hashing | [LeetCode](https://leetcode.com/problems/group-anagrams/) | [Solution](./LeetCode/02-Strings/49-Group-Anagrams.cpp) |

### Character Mapping / Bijection

| # | Problem | Technique | LeetCode | Solution |
|---|---|---|---|---|
| 205 | Isomorphic Strings | Two-Way Character Mapping | [LeetCode](https://leetcode.com/problems/isomorphic-strings/) | [Solution](./LeetCode/02-Strings/205-Isomorphic-Strings.cpp) |
| 290 | Word Pattern | Two-Way Character-to-Word Mapping | [LeetCode](https://leetcode.com/problems/word-pattern/) | [Solution](./LeetCode/02-Strings/290-Word-Pattern.cpp) |

---

## 4. Prefix Sum & Prefix / Suffix

Precalculate cumulative sums or products from the left and right to process subarray queries efficiently.

| # | Problem | Technique | LeetCode | Solution |
|---|---|---|---|---|
| 724 | Find Pivot Index | Prefix Sum | [LeetCode](https://leetcode.com/problems/find-pivot-index/) | [Solution](./LeetCode/01-Arrays/724-Find-Pivot-Index.cpp) |
| 560 | Subarray Sum Equals K | Prefix Sum + Hash Map | [LeetCode](https://leetcode.com/problems/subarray-sum-equals-k/) | [Solution](./LeetCode/01-Arrays/560-Subarray-Sum-Equals-K.cpp) |
| 238 | Product of Array Except Self | Prefix + Suffix Product | [LeetCode](https://leetcode.com/problems/product-of-array-except-self/) | [Solution](./LeetCode/01-Arrays/238-Product-of-Array-Except-Self.cpp) |

---

## 5. In-Place

In-place techniques modify an existing array or string directly, minimizing additional memory usage while preserving the required order or structure.

### In-Place Array Techniques, Reversal & Permutations

Rearrange array elements in place using indexing, swapping, cyclic placement, and reversal.

| # | Problem | Technique | LeetCode | Solution |
|---|---|---|---|---|
| 448 | Find All Numbers Disappeared in an Array | In-Place Index Marking | [LeetCode](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/) | [Solution](./LeetCode/01-Arrays/448-Find-All-Numbers-Disappeared-in-an-Array.cpp) |
| 41 | First Missing Positive | Cyclic Sort / Index Placement | [LeetCode](https://leetcode.com/problems/first-missing-positive/) | [Solution](./LeetCode/01-Arrays/41-First-Missing-Positive.cpp) |
| 189 | Rotate Array | Reversal Algorithm | [LeetCode](https://leetcode.com/problems/rotate-array/) | [Solution](./LeetCode/01-Arrays/189-Rotate-Array.cpp) |
| 31 | Next Permutation | In-Place Permutation | [LeetCode](https://leetcode.com/problems/next-permutation/) | [Solution](./LeetCode/01-Arrays/31-Next-Permutation.cpp) |

### In-Place String Manipulation

Modify strings directly using indexing, read/write positions, and reversal without creating unnecessary additional strings.

| # | Problem | Technique | LeetCode | Solution |
|---|---|---|---|---|
| 151 | Reverse Words in a String | In-Place String Manipulation + Reversal | [LeetCode](https://leetcode.com/problems/reverse-words-in-a-string/) | [Solution](./LeetCode/02-Strings/151-Reverse-Words-in-a-String.cpp) |

---

## 6. Kadane's Algorithm & Running State

Maintain optimal local states (running maximum, candidates, or minimum values) in a single pass.

| # | Problem | Technique | LeetCode | Solution |
|---|---|---|---|---|
| 53 | Maximum Subarray | Kadane's Algorithm | [LeetCode](https://leetcode.com/problems/maximum-subarray/) | [Solution](./LeetCode/01-Arrays/53-Maximum-Subarray.cpp) |
| 121 | Best Time to Buy and Sell Stock | Minimum Price Tracking | [LeetCode](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) | [Solution](./LeetCode/01-Arrays/121-Best-Time-to-Buy-and-Sell-Stock.cpp) |
| 169 | Majority Element | Boyer-Moore Voting Algorithm | [LeetCode](https://leetcode.com/problems/majority-element/) | [Solution](./LeetCode/01-Arrays/169-Majority-Element.cpp) |

---

## 7. Binary Search

Use the sorted order of the input to repeatedly eliminate half of the search space.

| # | Problem | Technique | LeetCode | Solution |
|---|---|---|---|---|
| 704 | Binary Search | Binary Search — Iterative | [LeetCode](https://leetcode.com/problems/binary-search/) | [Solution](./LeetCode/01-Arrays/704-Binary-Search.cpp) |

---

## 8. Bit Manipulation & Basic Operations

Use bitwise properties, loops, and digit extraction to solve arithmetic and parity problems.

| # | Problem | Technique | LeetCode | Solution |
|---|---|---|---|---|
| 136 | Single Number | XOR | [LeetCode](https://leetcode.com/problems/single-number/) | [Solution](./LeetCode/01-Arrays/136-Single-Number.cpp) |
| 268 | Missing Number | XOR | [LeetCode](https://leetcode.com/problems/missing-number/) | [Solution](./LeetCode/01-Arrays/268-Missing-Number.cpp) |
| 2235 | Add Two Integers | Basic Arithmetic | [LeetCode](https://leetcode.com/problems/add-two-integers/) | [Solution](./LeetCode/00-Programming-Basics/2235-Add-Two-Integers.cpp) |
| 412 | Fizz Buzz | Conditionals | [LeetCode](https://leetcode.com/problems/fizz-buzz/) | [Solution](./LeetCode/00-Programming-Basics/412-Fizz-Buzz.cpp) |
| 1342 | Number of Steps to Reduce a Number to Zero | Loops / Bit Manipulation | [LeetCode](https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/) | [Solution](./LeetCode/00-Programming-Basics/1342-Number-of-Steps-to-Reduce-a-Number-to-Zero.cpp) |
| 1281 | Subtract the Product and Sum of Digits | Digit Manipulation | [LeetCode](https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/) | [Solution](./LeetCode/00-Programming-Basics/1281-Subtract-the-Product-and-Sum-of-Digits.cpp) |
| 258 | Add Digits | Digit Manipulation | [LeetCode](https://leetcode.com/problems/add-digits/) | [Solution](./LeetCode/00-Programming-Basics/258-Add-Digits.cpp) |

---

## 9. Intervals

Sort intervals and merge overlapping ranges while traversing them.

| # | Problem | Technique | LeetCode | Solution |
|---|---|---|---|---|
| 56 | Merge Intervals | Sorting + Interval Merging | [LeetCode](https://leetcode.com/problems/merge-intervals/) | [Solution](./LeetCode/01-Arrays/56-Merge-Intervals.cpp) |

---

## 10. Linked List Reversal

Reverse linked-list connections using iterative or recursive pointer manipulation.

| # | Problem | Technique | LeetCode | Solution |
|---|---|---|---|---|
| 206 | Reverse Linked List | Iterative + Recursive Reversal | [LeetCode](https://leetcode.com/problems/reverse-linked-list/) | [Solution](./LeetCode/03-Linked-Lists/206-Reverse-Linked-List.cpp) |

---

## 11. Palindrome (Expand Around Center)

Identify and process palindromic sequences by checking characters from the center outward.

| # | Problem | Technique | LeetCode | Solution |
|---|---|---|---|---|
| 5 | Longest Palindromic Substring | Expand Around Center | [LeetCode](https://leetcode.com/problems/longest-palindromic-substring/) | [Solution](./LeetCode/02-Strings/5-Longest-Palindromic-Substring.cpp) |
| 647 | Palindromic Substrings | Expand Around Center | [LeetCode](https://leetcode.com/problems/palindromic-substrings/) | [Solution](./LeetCode/02-Strings/647-Palindromic-Substrings.cpp) |

---

## 12. String Traversal, Matching & Simulation

Process characters sequentially or in reverse, match patterns, simulate string operations, and manipulate strings in-place.

| # | Problem | Technique | LeetCode | Solution |
|---|---|---|---|---|
| 709 | To Lower Case | Character Traversal | [LeetCode](https://leetcode.com/problems/to-lower-case/) | [Solution](./LeetCode/02-Strings/709-To-Lower-Case.cpp) |
| 58 | Length of Last Word | Reverse Traversal | [LeetCode](https://leetcode.com/problems/length-of-last-word/) | [Solution](./LeetCode/02-Strings/58-Length-of-Last-Word.cpp) |
| 1768 | Merge Strings Alternately | Two Pointers + String Construction | [LeetCode](https://leetcode.com/problems/merge-strings-alternately/) | [Solution](./LeetCode/02-Strings/1768-Merge-Strings-Alternately.cpp) |
| 6 | Zigzag Conversion | Cycle Pattern / Mathematical Traversal | [LeetCode](https://leetcode.com/problems/zigzag-conversion/) | [Solution](./LeetCode/02-Strings/6-Zigzag-Conversion.cpp) |
| 14 | Longest Common Prefix | Character-by-Character Comparison | [LeetCode](https://leetcode.com/problems/longest-common-prefix/) | [Solution](./LeetCode/02-Strings/14-Longest-Common-Prefix.cpp) |
| 28 | Find the Index of the First Occurrence in a String | Brute Force / KMP | [LeetCode](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/) | [Solution](./LeetCode/02-Strings/28-Find-the-Index-of-the-First-Occurrence-in-a-String.cpp) |
| 13 | Roman to Integer | Right-to-Left Traversal + Hash Map | [LeetCode](https://leetcode.com/problems/roman-to-integer/) | [Solution](./LeetCode/02-Strings/13-Roman-to-Integer.cpp) |
| 12 | Integer to Roman | Greedy / One-Pass | [LeetCode](https://leetcode.com/problems/integer-to-roman/) | [Solution](./LeetCode/02-Strings/12-Integer-to-Roman.cpp) |
| 43 | Multiply Strings | Array Simulation / Grade-School Multiplication | [LeetCode](https://leetcode.com/problems/multiply-strings/) | [Solution](./LeetCode/02-Strings/43-Multiply-Strings.cpp) |

---

## 13. Array Traversal & Construction

Basic traversal, indexing, construction, and direct array operations.

| # | Problem | Technique | LeetCode | Solution |
|---|---|---|---|---|
| 1480 | Running Sum of 1d Array | Running Sum / Traversal | [LeetCode](https://leetcode.com/problems/running-sum-of-1d-array/) | [Solution](./LeetCode/01-Arrays/1480-Running-Sum-of-1d-Array.cpp) |
| 1929 | Concatenation of Array | Array Construction | [LeetCode](https://leetcode.com/problems/concatenation-of-array/) | [Solution](./LeetCode/01-Arrays/1929-Concatenation-of-Array.cpp) |
| 1470 | Shuffle the Array | Index Mapping | [LeetCode](https://leetcode.com/problems/shuffle-the-array/) | [Solution](./LeetCode/01-Arrays/1470-Shuffle-the-Array.cpp) |
| 1431 | Kids With the Greatest Number of Candies | Maximum + Traversal | [LeetCode](https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/) | [Solution](./LeetCode/01-Arrays/1431-Kids-With-the-Greatest-Number-of-Candies.cpp) |
| 1672 | Richest Customer Wealth | 2D Array Traversal | [LeetCode](https://leetcode.com/problems/richest-customer-wealth/) | [Solution](./LeetCode/01-Arrays/1672-Richest-Customer-Wealth.cpp) |
