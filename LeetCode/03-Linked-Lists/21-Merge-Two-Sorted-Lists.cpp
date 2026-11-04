/**
 * 21. Merge Two Sorted Lists
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/merge-two-sorted-lists/
 *
 * Problem:
 * You are given the heads of two sorted linked lists list1 and list2.
 * Merge the two lists into one sorted list. The list should be made by
 * splicing together the nodes of the first two lists.
 *
 * Return the head of the merged linked list.
 *
 *
 * Examples:
 *
 * Example 1:
 * Input: list1 = [1,2,4], list2 = [1,3,4]
 * Output: [1,1,2,3,4,4]
 *
 * Example 2:
 * Input: list1 = [], list2 = []
 * Output: []
 *
 * Example 3:
 * Input: list1 = [], list2 = [0]
 * Output: [0]
 *
 *
 * Constraints:
 * - The number of nodes in both lists is in the range [0, 50].
 * - -100 <= Node.val <= 100
 * - Both list1 and list2 are sorted in non-decreasing order.
 *
 *
 * ============================================================
 * Approach 1: Recursive Merging (LeetCode Submission)
 * ============================================================
 *
 * Technique:
 * Recursive Linked List Merging
 *
 * Key Idea:
 * Determine which head node has the smaller value. That node becomes
 * the head of the merged list, and its next pointer is recursively set
 * to the result of merging its remaining nodes with the other list.
 *
 * Steps:
 * 1. Base case: If list1 is nullptr, return list2. If list2 is nullptr, return list1.
 * 2. If list1->val <= list2->val:
 *    - list1->next = mergeTwoLists(list1->next, list2)
 *    - Return list1.
 * 3. Else:
 *    - list2->next = mergeTwoLists(list1, list2->next)
 *    - Return list2.
 *
 * Complexity:
 * - Time:  O(m + n) — Each node is processed once.
 * - Space: O(m + n) — Recursive call stack in the worst case.
 *
 *
 * ============================================================
 * Approach 2: Iterative (Dummy Node + Tail Pointer)
 * ============================================================
 *
 * Technique:
 * Two Pointers + Dummy Node
 *
 * Key Idea:
 * Use a stack-allocated dummy node to avoid edge cases with the head pointer.
 * Compare the front nodes of both lists iteratively, attach the smaller node
 * to the merged chain, and advance that list's pointer.
 *
 * Steps:
 * 1. Create a dummy node and point tail to &dummy.
 * 2. Loop while both list1 and list2 are not nullptr:
 *    - Attach smaller node to tail->next.
 *    - Advance the pointer of the chosen list.
 *    - Advance tail.
 * 3. Attach remaining non-empty list: tail->next = list1 ? list1 : list2.
 * 4. Return dummy.next.
 *
 * Complexity:
 * - Time:  O(m + n) — Each node is processed once.
 * - Space: O(1) — In-place pointer rewiring without extra memory.
 *
 * Note:
 * The recursive method is concise and elegant, but it uses
 * additional call stack space. The iterative method avoids
 * recursion overhead and is safer for very long linked lists.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    // Approach 1: Recursive (Primary LeetCode Submission)
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr || list2 == nullptr) {
            return list1 == nullptr ? list2 : list1;
        }

        if (list1->val <= list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }

    // Approach 2: Iterative (Optimal O(1) Space)
    ListNode* mergeTwoListsIterative(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        tail->next = list1 != nullptr ? list1 : list2;
        return dummy.next;
    }
};