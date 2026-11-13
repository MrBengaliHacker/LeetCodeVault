/**
 * 61. Rotate List
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/rotate-list/
 *
 * Problem:
 * Given the head of a linked list, rotate the list to the right by k places.
 *
 *
 * Examples:
 *
 * Example 1:
 * Input: head = [1,2,3,4,5], k = 2
 * Output: [4,5,1,2,3]
 *
 * Example 2:
 * Input: head = [0,1,2], k = 4
 * Output: [2,0,1]
 *
 *
 * Constraints:
 * - The number of nodes in the list is in the range [0, 500].
 * - -100 <= Node.val <= 100
 * - 0 <= k <= 2 * 10^9
 *
 *
 * ============================================================
 * Approach: Circular Linked List + Pointer Manipulation
 * ============================================================
 *
 * Technique:
 * Find Length + Circular Connection + Reconnection
 *
 * Key Idea:
 * First, find the length of the list and its last node.
 * Use k % length to avoid unnecessary rotations.
 * Connect the last node to the head to make the list circular.
 * Find the new tail, break the circle, and return the new head.
 *
 * Steps:
 * 1. Return head if the list has 0 or 1 node, or k is 0.
 * 2. Find the length of the list and its last node.
 * 3. Calculate the effective rotations using k % length.
 * 4. If the effective rotations are 0, return head.
 * 5. Connect the last node to the head to make the list circular.
 * 6. Start from the old tail and move length - k steps to find the new tail.
 * 7. Set the node after the new tail as the new head.
 * 8. Break the circle by setting the new tail's next to nullptr.
 * 9. Return the new head.
 *
 * Complexity:
 * - Time:  O(n) — One pass to find the length and tail, plus at most one pass
 *                 to locate the new tail.
 * - Space: O(1) — In-place pointer manipulation using constant extra memory.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) {
            return head;
        }

        // 1. Find the length of the list and the current tail
        int length = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            length++;
        }

        // 2. Reduce k to avoid unnecessary full rotations
        k = k % length;
        if (k == 0) {
            return head;
        }

        // 3. Connect tail to head to make it a circular linked list
        tail->next = head;

        // 4. Find the new tail by moving (length - k) steps from the old tail
        int stepsToNewTail = length - k;
        ListNode* newTail = tail;
        while (stepsToNewTail--) {
            newTail = newTail->next;
        }

        // 5. Set the new head and break the circle
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};