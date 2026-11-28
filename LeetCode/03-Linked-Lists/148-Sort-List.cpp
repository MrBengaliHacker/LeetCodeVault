/**
 * 148. Sort List
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/sort-list/
 *
 * Problem:
 * Given the head of a linked list, return the list after sorting it in ascending order.
 *
 *
 * Examples:
 *
 * Example 1:
 * Input: head = [4,2,1,3]
 * Output: [1,2,3,4]
 *
 * Example 2:
 * Input: head = [-1,5,3,4,0]
 * Output: [-1,0,3,4,5]
 *
 * Example 3:
 * Input: head = []
 * Output: []
 *
 *
 * Constraints:
 * - The number of nodes in the list is in the range [0, 5 * 10^4].
 * - -10^5 <= Node.val <= 10^5
 *
 * Follow-up:
 * Can you sort the linked list in O(n log n) time and O(1) memory (i.e. constant space)?
 *
 *
 * ============================================================
 * Approach: Bottom-Up Merge Sort (Iterative + Dummy Node)
 * ============================================================
 *
 * Technique:
 * Bottom-Up Merge Sort + In-Place Linked List Merging
 *
 * Key Idea:
 * Divide the linked list into small groups and merge them in sorted order.
 * Start with groups of 1 node, then merge them into groups of 2, then 4,
 * then 8, and continue doubling the group size until the entire list
 * is sorted. Use pointers to merge the groups without creating new nodes.
 *
 * Steps:
 * 1. Return head if the list is empty or contains only one node.
 * 2. Count the total number of nodes in the list.
 * 3. Create a dummy node pointing to head.
 * 4. Start with a group size of 1 and double it after each pass.
 * 5. For each pass:
 *    - Reset prev to the dummy node and curr to the list head.
 *    - Take the current group as the left sublist.
 *    - Move right forward by up to size nodes to find the start of the right sublist.
 *    - Move next forward by up to size nodes to find the start of the next pair of sublists.
 *    - Merge the left and right sublists by comparing their values.
 *    - Attach any remaining nodes from either sublist.
 *    - Connect the merged sublists to the remaining list.
 *    - Continue from next.
 * 6. Repeat until the group size is greater than or equal to n.
 * 7. Return dummy.next.
 *
 * Complexity:
 * - Time: O(n log n) - Each pass processes at most n nodes, and the number 
 *         of passes is O(log n) because the group size doubles.
 * - Space: O(1) - Uses a constant number of pointers and variables
 *                 without creating additional nodes.
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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        int n = 0;
        for (ListNode* p = head; p; p = p->next) n++;

        ListNode dummy(0, head);

        for (int size = 1; size < n; size <<= 1) {
            ListNode* prev = &dummy;
            ListNode* curr = dummy.next;

            while (curr) {
                // 1. Locate start of right sublist
                ListNode* left = curr;
                ListNode* right = left;
                int leftCount = 0;

                while (leftCount < size && right) {
                    right = right->next;
                    leftCount++;
                }

                // Nothing left to merge in this pass
                if (!right) break;

                // 2. Locate start of next pair
                ListNode* next = right;
                int rightCount = 0;

                while (rightCount < size && next) {
                    next = next->next;
                    rightCount++;
                }

                // 3. Merge left and right in-place
                int i = 0, j = 0;

                while (i < leftCount && j < rightCount) {
                    if (left->val <= right->val) {
                        prev->next = left;
                        left = left->next;
                        i++;
                    } else {
                        prev->next = right;
                        right = right->next;
                        j++;
                    }

                    prev = prev->next;
                }

                // 4. Attach whichever sublist still has nodes remaining
                ListNode* rem = (i < leftCount) ? left : right;
                int remCount = (i < leftCount)
                    ? (leftCount - i)
                    : (rightCount - j);

                while (remCount--) {
                    prev->next = rem;
                    rem = rem->next;
                    prev = prev->next;
                }

                // 5. Reconnect to the rest of the list
                prev->next = next;
                curr = next;
            }
        }

        return dummy.next;
    }
};