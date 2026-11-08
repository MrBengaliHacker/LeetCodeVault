/**
 * 19. Remove Nth Node From End of List
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 *
 * Problem:
 * Given the head of a linked list, remove the nth node from the end of the
 * list and return its head.
 *
 *
 * Examples:
 *
 * Example 1:
 * Input: head = [1,2,3,4,5], n = 2
 * Output: [1,2,3,5]
 *
 * Example 2:
 * Input: head = [1], n = 1
 * Output: []
 *
 * Example 3:
 * Input: head = [1,2], n = 1
 * Output: [1]
 *
 *
 * Constraints:
 * - The number of nodes in the list is sz.
 * - 1 <= sz <= 30
 * - 0 <= Node.val <= 100
 * - 1 <= n <= sz
 *
 * Follow-up:
 * Could you do this in one pass?
 *
 *
 * ============================================================
 * Approach 1: One Pass (Fast & Slow Pointers + Dummy Node)
 * ============================================================
 *
 * Technique:
 * Two Pointers — Fast & Slow (Fixed Gap)
 *
 * Key Idea:
 * Keep fast ahead of slow by n + 1 nodes.
 * When fast reaches nullptr, slow will be just before
 * the node that needs to be removed.
 * Use a dummy node to handle deletion of the head easily.
 *
 * Steps:
 * 1. Create a dummy node before the head and point both pointers to it.
 * 2. Move fast forward n + 1 steps.
 * 3. Move both pointers one step at a time until fast reaches nullptr.
 * 4. Remove the node immediately after slow.
 * 5. Return the updated head using the dummy node.
 *
* Complexity:
 * - Time:  O(sz) — The list of size sz is traversed in a single pass.
 * - Space: O(1)  — Constant auxiliary space; only two pointers and a dummy node are used.
 *
 *
 * ============================================================
 * Approach 2: Two Pass (Length Calculation)
 * ============================================================
 *
 * Technique:
 * Linked List Traversal + Counting
 *
 * Key Idea:
 * First, count the total number of nodes.
 * Calculate the target node's position from the beginning
 * using (length - n).
 * Then traverse to the node before it and remove it.
 * 
 * Steps:
 * 1. Traverse the list and count the total number of nodes.
 * 2. Calculate the target node's position from the beginning.
 * 3. If the target is the head, remove it and return the new head.
 * 4. Otherwise, move to the node just before the target.
 * 5. Remove the target node and connect the previous node
 *    to the next node.
 * 6. Return the updated head.
 *
* Complexity:
 * - Time:  O(sz) — The list of size sz is traversed twice.
 * - Space: O(1)  — Constant auxiliary memory; only a few pointers and variables are used.
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
    // Approach 1: Optimal One-Pass (Fixed Gap Two Pointers)
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        for (int i = 0; i <= n; ++i) {
            fast = fast->next;
        }

        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        delete nodeToDelete;

        return dummy.next;
    }

    // Approach 2: Two-Pass (Length Calculation)
    ListNode* removeNthFromEndTwoPass(ListNode* head, int n) {
        int length = 0;
        ListNode* curr = head;

        while (curr != nullptr) {
            length++;
            curr = curr->next;
        }

        int targetIndex = length - n;

        if (targetIndex == 0) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        curr = head;
        for (int i = 0; i < targetIndex - 1; ++i) {
            curr = curr->next;
        }

        ListNode* nodeToDelete = curr->next;
        curr->next = curr->next->next;
        delete nodeToDelete;

        return head;
    }
};