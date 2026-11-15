/**
 * 92. Reverse Linked List II
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/reverse-linked-list-ii/
 *
 * Problem:
 * Given the head of a singly linked list and two integers left and right where
 * left <= right, reverse the nodes of the list from position left to position
 * right, and return the reversed list.
 *
 *
 * Examples:
 *
 * Example 1:
 * Input: head = [1,2,3,4,5], left = 2, right = 4
 * Output: [1,4,3,2,5]
 *
 * Example 2:
 * Input: head = [5], left = 1, right = 1
 * Output: [5]
 *
 *
 * Constraints:
 * - The number of nodes in the list is n.
 * - 1 <= n <= 500
 * - -500 <= Node.val <= 500
 * - 1 <= left <= right <= n
 *
 * Follow-up:
 * Could you do it in one pass?
 *
 *
 * ============================================================
 * Approach: Iterative (Dummy Node + Head Insertion)
 * ============================================================
 *
 * Technique:
 * Dummy Node + In-Place Sublist Reversal (Head Insertion) + Pointer Reconnection
 *
 * Key Idea:
 * Keep a pointer before the sublist that needs to be reversed.
 * Repeatedly take the next node from the sublist and move it
 * to the beginning of that sublist.
 * Continue until the required part is reversed.
 *
 * Steps:
 * 1. Return head if the list is empty or left equals right.
 * 2. Create a dummy node before the head.
 * 3. Move prev to the node just before the left position.
 * 4. Set curr to the first node of the sublist.
 * 5. Take the node immediately after curr.
 * 6. Move that node to the beginning of the sublist.
 * 7. Repeat until the required part is reversed.
 * 8. Return the updated head using the dummy node.
 *
 * Complexity:
 * - Time:  O(n) — Traversing to the sublist and reversing it takes linear time.
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) {
            return head;
        }

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        // 1. Move prev to the node before left
        for (int i = 0; i < left - 1; i++) {
            prev = prev->next;
        }

        ListNode* curr = prev->next;

        // 2. Reverse the sublist
        for (int i = 0; i < right - left; i++) {
            ListNode* nextNode = curr->next;
            curr->next = nextNode->next;
            nextNode->next = prev->next;
            prev->next = nextNode;
        }

        return dummy.next;
    }
};