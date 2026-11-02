/**
 * 206. Reverse Linked List
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/reverse-linked-list/
 *
 * Problem:
 * Given the head of a singly linked list, reverse the list
 * and return the reversed list.
 *
 *
 * Example 1:
 * Input: head = [1,2,3,4,5]
 * Output: [5,4,3,2,1]
 *
 * Explanation:
 * Reverse the direction of the links between all nodes.
 *
 *
 * Example 2:
 * Input: head = [1,2]
 * Output: [2,1]
 *
 *
 * Example 3:
 * Input: head = []
 * Output: []
 *
 *
 * ============================================================
 * Approach 1: Using an Auxiliary Array (Value Swap)
 * ============================================================
 *
 * Technique:
 * Array Traversal + Value Overwrite
 *
 * Key Idea:
 * Store all node values in a dynamic array (vector).
 * Traverse the linked list again and overwrite each node's
 * value using the array elements in reverse order.
 *
 * Approach:
 * 1. Traverse the list and push each node's val into a vector.
 * 2. Traverse the list a second time from the head.
 * 3. Overwrite temp->val with values from the end of the vector.
 * 4. Return the original head.
 *
 * Complexity:
 * - Time:  O(n) - Two passes over the linked list of n nodes.
 * - Space: O(n) - Auxiliary vector storing n node values.
 *
 * Note:
 * This method modifies node values rather than node links.
 * While it passes test cases, it violates the spirit of pointer
 * manipulation questions and does not work if node objects are immutable.
 *
 *
 * ============================================================
 * Approach 2: Iterative In-Place Reversal (Optimal)
 * ============================================================
 *
 * Technique:
 * Three Pointers (prev, curr, nextNode)
 *
 * Key Idea:
 * Flip the direction of each node's pointer in-place in a single pass.
 *
 * Use three tracking pointers:
 * - prev: Tracks the already reversed sublist (initially nullptr).
 * - curr: The node currently being processed (initially head).
 * - nextNode: Temporarily saves curr->next before rewiring.
 *
 * Approach:
 * 1. Initialize prev = nullptr, curr = head, and nextNode = nullptr.
 * 2. Loop while curr != nullptr:
 *    a. nextNode = curr->next   (save remaining chain)
 *    b. curr->next = prev       (reverse link)
 *    c. prev = curr             (step prev forward)
 *    d. curr = nextNode         (step curr forward)
 * 3. Return prev as the new head of the reversed list.
 *
 * Complexity:
 * - Time:  O(n) - Single pass over n nodes.
 * - Space: O(1) - Constant extra pointers.
 *
 *
 * ============================================================
 * Approach 3: Tail-Recursive Reversal
 * ============================================================
 *
 * Technique:
 * Tail Recursion + Accumulator Pattern
 *
 * Key Idea:
 * Emulate the iterative 3-pointer method recursively by passing
 * the accumulating reversed list (prev) and the remaining chain (curr).
 *
 * Approach:
 * 1. Base case: If curr is nullptr, return prev.
 * 2. Save nextNode = curr->next.
 * 3. Reverse the link: curr->next = prev.
 * 4. Recurse: return reverseHelper(nextNode, curr).
 *
 * Complexity:
 * - Time:  O(n) - Visits each node once.
 * - Space: O(n) - Recursion call stack.
 *
 * Note:
 * Although this function is tail-recursive, Tail-Call Optimization (TCO)
 * is NOT guaranteed by the C++ standard. Modern compilers (GCC/Clang with -O2/-O3)
 * may optimize it into a loop, but in unoptimized builds or under different
 * compiler implementations, it can still risk a stack overflow on large inputs.
 */


#include <vector>

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
    // Approach 1: Auxiliary Array (Value Replacement)
    ListNode* reverseListUsingArray(ListNode* head) {
        std::vector<int> values;
        ListNode* temp = head;

        while (temp) {
            values.push_back(temp->val);
            temp = temp->next;
        }

        int i = static_cast<int>(values.size()) - 1;
        temp = head;

        while (temp) {
            temp->val = values[i--];
            temp = temp->next;
        }

        return head;
    }

    // Approach 2: Iterative Three-Pointer (Optimal)
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* nextNode = nullptr;

        while (curr) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    // Approach 3: Tail-Recursive Reversal
    ListNode* reverseRecursive(ListNode* curr, ListNode* prev) {
        if (!curr) {
            return prev;
        }

        ListNode* nextNode = curr->next;
        curr->next = prev;

        return reverseRecursive(nextNode, curr);
    }

    ListNode* reverseListRecursive(ListNode* head) {
        return reverseRecursive(head, nullptr);
    }
};