/**
 * 876. Middle of the Linked List
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/middle-of-the-linked-list/
 *
 * Problem:
 * Given the head of a singly linked list, return the middle node.
 * If there are two middle nodes, return the second middle node.
 *
 *
 * Examples:
 *
 * Example 1:
 * Input: head = [1,2,3,4,5]
 * Output: [3,4,5]
 * Explanation: The middle node is node 3.
 *
 * Example 2:
 * Input: head = [1,2,3,4,5,6]
 * Output: [4,5,6]
 * Explanation: The second middle node is node 4.
 *
 *
 * ============================================================
 * Approach 1: Count and Traverse (Two-Pass)
 * ============================================================
 *
 * Technique:
 * Length Counting + Traversal
 *
 * Key Idea:
 * Count all nodes, calculate the middle position using `count / 2`,
 * and traverse again from head for that many steps to reach the middle node.
 *
 * Steps:
 * 1. Traverse the linked list and count the total number of nodes.
 * 2. Calculate the middle position using count / 2.
 * 3. Traverse again from head for steps using while (steps--).
 * 4. Return the middle node.
 *
 * Complexity:
 * - Time Complexity:  O(n) — Two traversals (approximately 1.5n node visits).
 * - Space Complexity: O(1) — Constant extra space.
 *
 *
 * ============================================================
 * Approach 2: Fast & Slow Pointers (One-Pass / Optimal)
 * ============================================================
 *
 * Technique:
 * Two Pointers — Same-Direction (Fast & Slow)
 *
 * Key Idea:
 * Move the slow pointer one step and the fast pointer two steps.
 * When the fast pointer reaches the end, the slow pointer points
 * to the middle node.
 *
 * Steps:
 * 1. Initialize both slow and fast pointers at head.
 * 2. Move slow by one node (`slow = slow->next`) and fast by two nodes (`fast = fast->next->next`).
 * 3. Continue while `fast` and `fast->next` are not nullptr.
 * 4. Return slow.
 *
 * Complexity:
 * - Time Complexity:  O(n) — Single pass (slow traverses n/2 nodes).
 * - Space Complexity: O(1) — Only two pointers are used.
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
    // Approach 1: Count and Traverse
    ListNode* middleNodeUsingCount(ListNode* head) {
        int count = 0;
        ListNode *temp = head;

        while (temp) {
            count++;
            temp = temp->next;
        }

        int steps = count / 2;
        temp = head;
        while (steps--) {
            temp = temp->next;
        }
        
        return temp;
    }

    // Approach 2: Fast & Slow Pointers (LeetCode main solution)
    ListNode* middleNode(ListNode* head) {
        ListNode *fast = head, *slow = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};