/**
 * 234. Palindrome Linked List
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/palindrome-linked-list/
 *
 * Problem:
 * Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
 *
 *
 * Examples:
 *
 * Example 1:
 * Input: head = [1,2,2,1]
 * Output: true
 *
 * Example 2:
 * Input: head = [1,2]
 * Output: false
 *
 *
 * Constraints:
 * - The number of nodes in the list is in the range [1, 10^5].
 * - 0 <= Node.val <= 9
 *
 * Follow-up:
 * Could you do it in O(n) time and O(1) space?
 *
 *
 * ============================================================
 * Approach: Fast & Slow Pointers + In-Place Reversal
 * ============================================================
 *
 * Technique:
 * Find Middle + Reverse Second Half + Compare
 *
 * Key Idea:
 * Find the middle of the linked list using fast and slow pointers.
 * Reverse the second half and compare it with the first half.
 * If all corresponding values match, the list is a palindrome.
 *
 * Steps:
 * 1. Return true if the list has 0 or 1 node.
 * 2. Use fast and slow pointers to find the middle.
 * 3. Reverse the second half of the linked list.
 * 4. Compare the nodes from both halves one by one.
 * 5. Return false immediately if any values mismatch.
 * 6. Return true if all compared nodes match.
 *
 * Complexity:
 * - Time:  O(n) — Finding the middle, reversing and comparing the list take linear time.
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
    bool isPalindrome(ListNode* head) {
        // Base condition
        if (head == nullptr || head->next == nullptr) {
            return true;
        }

        // Step 1: Find the middle using slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half
        ListNode* prev = nullptr;
        ListNode* curr = slow;

        while (curr != nullptr) {
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        // Step 3: Compare both halves
        ListNode* first = head;
        ListNode* second = prev;

        while (second != nullptr) {
            if (first->val != second->val) {
                return false;
            }
            first = first->next;
            second = second->next;
        }

        return true;
    }
};