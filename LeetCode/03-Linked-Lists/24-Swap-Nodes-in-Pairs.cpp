/**
 * 24. Swap Nodes in Pairs
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/swap-nodes-in-pairs/
 *
 * Problem:
 * Given a linked list, swap every two adjacent nodes and return its head.
 * You must solve the problem without modifying the values in the list's nodes
 * (i.e., only nodes themselves may be changed.)
 *
 *
 * Examples:
 *
 * Example 1:
 * Input: head = [1,2,3,4]
 * Output: [2,1,4,3]
 *
 * Example 2:
 * Input: head = []
 * Output: []
 *
 * Example 3:
 * Input: head = [1]
 * Output: [1]
 *
 * Example 4:
 * Input: head = [1,2,3]
 * Output: [2,1,3]
 *
 *
 * Constraints:
 * - The number of nodes in the list is in the range [0, 100].
 * - 0 <= Node.val <= 100
 *
 *
 * ============================================================
 * Approach: Iterative (Three Pointers + Node Rewiring)
 * ============================================================
 *
 * Technique:
 * Three Pointers — Pairwise Swapping + Pointer Reconnection
 *
 * Key Idea:
 * Take two adjacent nodes and swap their links.
 * Connect the swapped pair to the previous pair.
 * Continue until no complete pair is left.
 *
 * Steps:
 * 1. Return head if the list has 0 or 1 node.
 * 2. Set first and second to the first two nodes.
 * 3. Store the node after the pair in third.
 * 4. Connect second to first and first to third.
 * 5. Connect the previous pair to second.
 * 6. Move previous to first and move first to third.
 * 7. Set second to the node after third.
 * 8. Continue until fewer than two nodes remain.
 * 9. Return the updated head.
 *
 * Complexity:
 * - Time:  O(n) — Each node in the list is visited and rewired once.
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
    ListNode* swapPairs(ListNode* head) {
        // Base Condition
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* first = head;
        ListNode* second = head->next;
        ListNode* previous = nullptr;

        while (first != nullptr && second != nullptr) {
            ListNode* third = second->next;

            // Swap the current pair
            second->next = first;
            first->next = third;

            // Connect the previous pair
            if (previous != nullptr) {
                previous->next = second;
            } else {
                head = second;
            }

            // Move to the next pair
            previous = first;
            first = third;

            if (third != nullptr) {
                second = third->next;
            } else {
                second = nullptr;
            }
        }

        return head;
    }
};