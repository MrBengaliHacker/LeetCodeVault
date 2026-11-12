/**
 * 143. Reorder List
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/reorder-list/
 *
 * Problem:
 * You are given the head of a singly linked-list. The list can be represented as:
 * L0 -> L1 -> ... -> Ln - 1 -> Ln
 *
 * Reorder the list to be on the following form:
 * L0 -> Ln -> L1 -> Ln - 1 -> L2 -> Ln - 2 -> ...
 *
 * You may not modify the values in the list's nodes. Only nodes themselves may be changed.
 *
 *
 * Examples:
 *
 * Example 1:
 * Input: head = [1,2,3,4]
 * Output: [1,4,2,3]
 *
 * Example 2:
 * Input: head = [1,2,3,4,5]
 * Output: [1,5,2,4,3]
 *
 *
 * Constraints:
 * - The number of nodes in the list is in the range [1, 5 * 10^4].
 * - 1 <= Node.val <= 1000
 *
 *
 * ============================================================
 * Approach: Find Middle + Reverse + Merge
 * ============================================================
 *
 * Technique:
 * Fast & Slow Pointers + In-Place Reversal + Alternating Merging
 *
 * Key Idea:
 * Divide the list into two halves.
 * Reverse the second half and merge both halves one node at a time.
 * This places the last node after the first, the second-last after
 * the second, and continues until the list is reordered.
 *
 * Steps:
 * 1. Return if the list has 0 or 1 node.
 * 2. Use fast and slow pointers to find the middle.
 * 3. Split the list into two halves.
 * 4. Reverse the second half.
 * 5. Take one node from the first half and one from the reversed
 *    second half, and connect them alternately.
 * 6. Continue until all nodes from the second half are merged.
 *
 * Complexity:
 * - Time:  O(n) — Finding the middle, reversing the second half, and merging
 *                 both halves each take linear time.
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
    void reorderList(ListNode* head) {
        if (!head || !head->next) {
            return;
        }

        // Step 1: Find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Split the list into two halves
        ListNode* secondHalf = slow->next;
        slow->next = nullptr;

        // Step 3: Reverse the second half
        ListNode* previousNode = nullptr;
        ListNode* currentNode = secondHalf;

        while (currentNode) {
            ListNode* nextNode = currentNode->next;
            currentNode->next = previousNode;
            previousNode = currentNode;
            currentNode = nextNode;
        }

        secondHalf = previousNode;

        // Step 4: Merge both halves alternately
        ListNode* firstHalf = head;

        while (secondHalf) {
            ListNode* nextFirst = firstHalf->next;
            ListNode* nextSecond = secondHalf->next;

            firstHalf->next = secondHalf;
            secondHalf->next = nextFirst;

            firstHalf = nextFirst;
            secondHalf = nextSecond;
        }
    }
};