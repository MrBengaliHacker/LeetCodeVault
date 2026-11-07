/**
 * 142. Linked List Cycle II
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/linked-list-cycle-ii/
 *
 * Problem:
 * Given the head of a linked list, return the node where the cycle begins.
 * If there is no cycle, return null[cite: 5].
 *
 * There is a cycle in a linked list if there is some node in the list that can
 * be reached again by continuously following the next pointer[cite: 5]. Internally, pos is
 * used to denote the index of the node that tail's next pointer is connected to[cite: 5].
 * It is -1 if there is no cycle[cite: 5]. Note that pos is not passed as a parameter[cite: 5].
 *
 * Do not modify the linked list[cite: 5].
 *
 *
 * Examples:
 *
 * Example 1:
 * Input: head = [3,2,0,-4], pos = 1[cite: 5]
 * Output: tail connects to node index 1[cite: 5]
 * Explanation: There is a cycle in the linked list, where tail connects to the second node[cite: 5].
 *
 * Example 2:
 * Input: head = [1,2], pos = 0[cite: 6]
 * Output: tail connects to node index 0[cite: 6]
 * Explanation: There is a cycle in the linked list, where tail connects to the first node[cite: 6].
 *
 * Example 3:
 * Input: head = [1], pos = -1[cite: 6]
 * Output: no cycle[cite: 6]
 * Explanation: There is no cycle in the linked list[cite: 6].
 *
 *
 * Constraints:
 * - The number of the nodes in the list is in the range [0, 10^4][cite: 6].
 * - -10^5 <= Node.val <= 10^5[cite: 6]
 * - pos is -1 or a valid index in the linked-list[cite: 6].
 *
 * Follow-up:
 * Can you solve it using O(1) (i.e. constant) memory?[cite: 6]
 *
 *
 * ============================================================
 * Approach: Fast & Slow Pointers (Floyd's Cycle Detection)
 * ============================================================
 *
 * Technique:
 * Two Pointers — Fast & Slow
 *
 * Key Idea:
 * First, use fast and slow pointers to check whether a cycle exists.
 * If they meet, move slow back to the head.
 * Then move both pointers one step at a time.
 * They will meet again at the node where the cycle begins.
 *
 * Steps:
 * 1. Start both slow and fast pointers at the head.
 * 2. Move slow one step and fast two steps at a time.
 * 3. If fast reaches nullptr, return nullptr because there is no cycle.
 * 4. If they meet, a cycle exists: reset slow back to the head.
 * 5. Move both pointers one step at a time until they meet again.
 * 6. Return the node where they meet.
 *
 * Complexity:
 * - Time:  O(n) — Phase 1 finds the meeting point in at most n steps.
 *                 Phase 2 takes at most n steps to reach the cycle entry.
 * - Space: O(1) — Constant memory using only two pointers.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        // Phase 1: Determine if a cycle exists
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Phase 2: Find cycle entrance
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }

        return nullptr;
    }
};