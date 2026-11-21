/**
 * 445. Add Two Numbers II
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/add-two-numbers-ii/
 *
 * Problem:
 * You are given two non-empty linked lists representing two non-negative integers.
 * The most significant digit comes first and each of their nodes contains a single digit.
 * Add the two numbers and return the sum as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
 *
 * Examples:
 *
 * Example 1:
 * Input: l1 = [7,2,4,3], l2 = [5,6,4]
 * Output: [7,8,0,7]
 *
 * Example 2:
 * Input: l1 = [2,4,3], l2 = [5,6,4]
 * Output: [8,0,7]
 *
 * Example 3:
 * Input: l1 = [0], l2 = [0]
 * Output: [0]
 *
 *
 * Constraints:
 * - The number of nodes in each linked list is in the range [1, 100].
 * - 0 <= Node.val <= 9
 * - It is guaranteed that the list represents a number that does not have leading zeros.
 *
 * Follow-up:
 * Could you solve it without reversing the input lists?
 *
 *
 * ============================================================
 * Approach 1: In-Place Reversal (Reverse + Add + Reverse)
 * ============================================================
 *
 * Technique:
 * Linked List Reversal + Dummy Node + Carry Propagation
 *
 * Key Idea:
 * Reverse both input lists to process digits from least significant
 * to most significant.
 * Add corresponding digits while maintaining the carry.
 * Reverse the result to restore forward digit order.
 *
 * Steps:
 * 1. Reverse both input linked lists.
 * 2. Create a dummy node to build the result list.
 * 3. Initialize current at the dummy node and carry as 0.
 * 4. Traverse both reversed lists while either list has nodes or carry
 *    is not 0.
 * 5. Get the current digit from each list, using 0 if a list has ended.
 * 6. Add both digits and the carry.
 * 7. Calculate the new carry and result digit.
 * 8. Create a new node with the result digit and attach it to the list.
 * 9. Move forward in both input lists if nodes are available.
 * 10. Reverse the result list to restore forward digit order.
 * 11. Return the result list.
 *
 * Complexity:
 * - Time: O(m + n) — Reverses both input lists, performs addition,
 *                    and reverses the result list.
 * - Space: O(1) — Uses constant auxiliary space, excluding the output list.
 *
 * 
 * ============================================================
 * Approach 2: Stack (Without Modifying Input Lists)
 * ============================================================
 *
 * Technique:
 * Two Stacks + Carry Propagation + Head Insertion
 *
 * Key Idea:
 * Store the digits from both linked lists in separate stacks.
 * Pop the digits to process them from least significant to most significant.
 * Insert each result digit at the beginning of the result list.
 *
 * Steps:
 * 1. Create two stacks to store the digits from both linked lists.
 * 2. Traverse both lists and push their digits into the respective stacks.
 * 3. Initialize the result list as nullptr and carry as 0.
 * 4. Process digits while either stack has elements or carry is not 0.
 * 5. Pop available digits and add them along with the carry.
 * 6. Calculate the new carry and result digit.
 * 7. Create a new node and insert it at the beginning of the result list.
 * 8. Return the result list.
 *
 * Complexity:
 * - Time:  O(m + n) — Traverses both lists and processes each digit once.
 * - Space: O(m + n) — Uses two stacks to store the input digits.
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
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

public:
    // Approach 1: List Reversal + Elementary Addition (O(1) Auxiliary Space)
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Step 1: Reverse both input lists
        l1 = reverseList(l1);
        l2 = reverseList(l2);

        // Step 2: Create a dummy node to build the result list
        ListNode dummy(0);
        ListNode* current = &dummy;
        int carry = 0;

        // Step 3: Traverse both lists and get the current digits
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;

            // Step 4: Calculate the sum, carry, and result digit
            int total = val1 + val2 + carry;
            carry = total / 10;
            int digit = total % 10;

            // Step 5: Create the result node
            current->next = new ListNode(digit);
            current = current->next;

            // Step 6: Move to the next nodes if available
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        // Step 7: Reverse the result to restore forward order
        return reverseList(dummy.next);
    }


    // Approach 2: Two Stacks + Front Insertion (No Input List Modification — Follow-Up)
    ListNode* addTwoNumbersStack(ListNode* l1, ListNode* l2) {
        // Step 1: Create two stacks to store the digits
        stack<int> s1;
        stack<int> s2;

        // Step 2: Push digits from both lists into their stacks
        while (l1 != nullptr) {
            s1.push(l1->val);
            l1 = l1->next;
        }

        while (l2 != nullptr) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        // Step 3: Initialize the result list and carry
        ListNode* result = nullptr;
        int carry = 0;

        // Step 4: Process digits and carry from both stacks
        while (!s1.empty() || !s2.empty() || carry) {
            int sum = carry;

            if (!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }

            if (!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }

            // Step 5: Calculate the carry and insert the result digit at the beginning
            carry = sum / 10;

            ListNode* newNode = new ListNode(sum % 10);
            newNode->next = result;
            result = newNode;
        }

        // Step 6: Return the result list
        return result;
    }
};