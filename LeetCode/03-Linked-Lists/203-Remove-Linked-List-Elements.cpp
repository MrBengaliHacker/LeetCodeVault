/**
 * 203. Remove Linked List Elements
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/remove-linked-list-elements/
 *
 * Problem:
 * Given the head of a singly linked list and an integer val, remove all the
 * nodes of the linked list that have Node.val == val, and return the new head.
 *
 *
 * Examples:
 *
 * Example 1:
 * Input: head = [1,2,6,3,4,5,6], val = 6
 * Output: [1,2,3,4,5]
 *
 * Example 2:
 * Input: head = [], val = 1
 * Output: []
 *
 * Example 3:
 * Input: head = [7,7,7,7], val = 7
 * Output: []
 *
 *
 * Constraints:
 * - The number of nodes in the list is in the range [0, 10^4].
 * - 1 <= Node.val <= 50
 * - 0 <= val <= 50
 *
 *
 * ============================================================
 * Approach: Iterative (Dummy Node + Explicit Memory Deletion)
 * ============================================================
 *
 * Technique:
 * Dummy Node + In-Place Removal
 *
 * Key Idea:
 * Use a dummy node pointing to head to handle deletions at the beginning
 * of the list uniformly.
 *
 * Check curr->next:
 * - If its value matches val, bypass the node and delete it.
 * - Otherwise, move curr to the next node.
 *
 * Steps:
 * 1. Create a dummy node and connect it to head.
 * 2. Initialize curr to point to the dummy node.
 * 3. Traverse while curr->next is not nullptr:
 *    - If curr->next->val == val:
 *        Save the node in temp.
 *        Bypass it using curr->next = curr->next->next.
 *        Delete the removed node.
 *    - Otherwise, advance curr.
 * 4. Return dummy.next.
 *
 * Complexity:
 * - Time:  O(n) — Each node is visited at most once.
 * - Space: O(1) — Constant auxiliary memory on the stack.
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* curr = &dummy;

        while (curr->next != nullptr) {
            if (curr->next->val == val) {
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            } else {
                curr = curr->next;
            }
        }

        return dummy.next;
    }
};