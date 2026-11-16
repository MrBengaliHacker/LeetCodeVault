/**
 * 2. Add Two Numbers
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/add-two-numbers/
 *
 * Problem:
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order, and each of their nodes contains a single digit.
 * Add the two numbers and return the sum as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
 *
 * Examples:
 *
 * Example 1:
 * Input: l1 = [2,4,3], l2 = [5,6,4]
 * Output: [7,0,8]
 * Explanation: 342 + 465 = 807.
 *
 * Example 2:
 * Input: l1 = [0], l2 = [0]
 * Output: [0]
 *
 * Example 3:
 * Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 * Output: [8,9,9,9,0,0,0,1]
 *
 *
 * Constraints:
 * - The number of nodes in each linked list is in the range [1, 100].
 * - 0 <= Node.val <= 9
 * - It is guaranteed that the list represents a number that does not have leading zeros.
 *
 *
 * ============================================================
 * Approach: Elementary Math Simulation (Dummy Node + Carry)
 * ============================================================
 *
 * Technique:
 * Dummy Node + Two-List Traversal + Carry Propagation
 *
 * Key Idea:
 * Add the digits from both lists one by one.
 * Include the carry from the previous addition.
 * Create a new node using the last digit of the sum.
 * Continue until both lists and the carry are finished.
 *
 * Steps:
 * 1. Create a dummy node to build the result list.
 * 2. Initialize current at the dummy node and carry as 0.
 * 3. Traverse both lists while either list has nodes or carry is not 0.
 * 4. Get the current digit from each list. Use 0 if a list has ended.
 * 5. Add both digits and the carry.
 * 6. Calculate the new carry and the digit to store in the result.
 * 7. Create a new node with that digit and attach it to the result.
 * 8. Move forward in each list if nodes are available.
 * 9. Return dummy.next.
 *
 * Complexity:
 * - Time: O(max(m, n)) — Traverses both lists once, with at most
 *                        one additional iteration for the final carry.
 * - Space: O(max(m, n)) — Creates a new result list containing
 *                         at most max(m, n) + 1 nodes.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      // Step 1: Create a dummy node to build the result list
        ListNode dummy(0);
        ListNode* current = &dummy;
        int carry = 0;

        // Step 2: Traverse both lists and get the current digits
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;

            // Step 3: Calculate the sum, carry, and result digit
            int total = val1 + val2 + carry;
            carry = total / 10;
            int digit = total % 10;

            // Step 4: Create the result node
            current->next = new ListNode(digit);
            current = current->next;

            // Step 5: Move to the next nodes if available
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        return dummy.next;
    }
};