/**
 * 328. Odd Even Linked List
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/odd-even-linked-list/
 *
 * Problem:
 * Given the head of a singly linked list, group all the nodes with odd indices
 * together followed by the nodes with even indices, and return the reordered list.
 *
 * The first node is considered odd, and the second node is even, and so on.
 * Note that the relative order inside both the even and odd groups should remain
 * as it was in the input.
 *
 * You must solve the problem in O(1) extra space complexity and O(n) time complexity.
 *
 *
 * Examples:
 *
 * Example 1:
 * Input: head = [1,2,3,4,5]
 * Output: [1,3,5,2,4]
 *
 * Example 2:
 * Input: head = [2,1,3,5,6,4,7]
 * Output: [2,3,6,7,1,5,4]
 *
 *
 * Constraints:
 * - The number of nodes in the linked list is in the range [0, 10^4].
 * - -10^6 <= Node.val <= 10^6
 *
 *
 * ============================================================
 * Approach: Two Pointers (In-Place Reordering)
 * ============================================================
 *
 * Technique:
 * Two Pointers — Odd & Even
 *
 * Key Idea:
 * Create two separate chains using the existing nodes:
 * one for odd positions and one for even positions.
 * Keep evenHead to remember the beginning of the even chain.
 * After rearranging the nodes, connect the even chain
 * at the end of the odd chain.
 *
 * Steps:
 * 1. Return head if the list has 0 or 1 node.
 * 2. Set odd at the head and even at the second node.
 * 3. Store the starting node of the even chain in evenHead.
 * 4. Connect odd to the next odd-positioned node and move odd forward.
 * 5. Connect even to the next even-positioned node and move even forward.
 * 6. Continue until there are no more pairs to rearrange.
 * 7. Connect the odd chain to evenHead.
 * 8. Return head.
 *
 * Complexity:
 * - Time:  O(n) — Each node is visited and relinked exactly once.
 * - Space: O(1) — Only three pointers are used.
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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenHead;
        return head;
    }
};