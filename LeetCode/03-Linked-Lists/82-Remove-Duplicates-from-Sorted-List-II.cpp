/**
 * 82. Remove Duplicates from Sorted List II
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
 *
 * Problem:
 * Given the head of a sorted linked list, delete all nodes that have
 * duplicate numbers, leaving only distinct numbers from the original list.
 * Return the linked list sorted as well.
 *
 *
 * Examples:
 *
 * Example 1:
 * Input: head = [1,2,3,3,4,4,5]
 * Output: [1,2,5]
 *
 * Example 2:
 * Input: head = [1,1,1,2,3]
 * Output: [2,3]
 *
 *
 * Constraints:
 * - The number of nodes in the list is in the range [0, 300].
 * - -100 <= Node.val <= 100
 * - The list is guaranteed to be sorted in ascending order.
 *
 *
 * ============================================================
 * Approach: Iterative (Dummy Node + Two Pointers)
 * ============================================================
 *
 * Technique:
 * Dummy Node + Two Pointers
 *
 * Key Idea:
 * Use a dummy node to handle duplicate groups at the beginning of the list.
 * Maintain two pointers: prev points to the last confirmed distinct node,
 * while curr checks the remaining nodes.
 * When a duplicate group is found, remove all its nodes and connect
 * the previous distinct node to the next remaining node.
 *
 * Steps:
 * 1. Create a dummy node before the head and initialize prev and curr.
 * 2. Traverse the linked list and check whether the current node
 *    and the next node have the same value.
 * 3. If a duplicate group is found:
 *    - Store its value.
 *    - Remove all consecutive nodes having that value.
 *    - Connect the previous distinct node to the next remaining node.
 * 4. If the current node is unique, keep it and move both pointers forward.
 * 5. Continue checking the remaining list until all nodes are processed.
 * 6. Return the head of the updated list using the dummy node.
 *
 * Complexity:
 * - Time: O(n) — Each node is traversed once.
 * - Space: O(1) — Constant auxiliary space; nodes are removed in-place.
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        ListNode* curr = head;

        while (curr != nullptr) {
            if (curr->next != nullptr && curr->val == curr->next->val) {
                int duplicateVal = curr->val;
                while (curr != nullptr && curr->val == duplicateVal) {
                    ListNode* temp = curr;
                    curr = curr->next;
                    delete temp;
                }
                prev->next = curr;
            } else {
                prev = prev->next;
                curr = curr->next;
            }
        }

        return dummy.next;
    }
};