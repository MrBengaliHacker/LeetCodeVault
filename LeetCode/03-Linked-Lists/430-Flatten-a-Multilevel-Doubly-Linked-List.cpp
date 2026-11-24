/**
 * 430. Flatten a Multilevel Doubly Linked List
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
 *
 * Problem:
 * You are given a doubly linked list, which contains nodes that have a next pointer,
 * a previous pointer, and an additional child pointer. This child pointer may or may
 * not point to a separate doubly linked list, also containing these special nodes.
 * These child lists may have one or more children of their own, and so on, to produce
 * a multilevel data structure.
 *
 * Given the head of the first level of the list, flatten the list so that all the
 * nodes appear in a single-level, doubly linked list. Let curr be a node with a child
 * list. The nodes in the child list should appear after curr and before curr.next in
 * the flattened list.
 *
 * Return the head of the flattened list. The nodes in the list must have all of their
 * child pointers set to null.
 *
 *
 * Examples:
 *
 * Example 1:
 * Input: head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
 * Output: [1,2,3,7,8,11,12,9,10,4,5,6]
 *
 * Example 2:
 * Input: head = [1,2,null,3]
 * Output: [1,3,2]
 *
 * Example 3:
 * Input: head = []
 * Output: []
 *
 *
 * Constraints:
 * - The number of Nodes will not exceed 1000.
 * - 1 <= Node.val <= 10^5
 *
 *
 * ============================================================
 * Approach 1: Iterative Pointer Splicing (Optimal Space)
 * ============================================================
 *
 * Technique:
 * Doubly Linked List Splicing + Pointer Rewiring
 *
 * Key Idea:
 * Whenever a node has a child list, insert that child list between
 * the current node and its next node. Connect the end of the child
 * list to the saved next node. Continue traversing the list to
 * flatten any remaining child lists.
 *
 * Steps:
 * 1. Return nullptr if the original list is empty.
 * 2. Start traversing the list from the head.
 * 3. If the current node has no child, move to the next node.
 * 4. If the current node has a child:
 *    - Save its original next node and child head.
 *    - Connect the current node to the child list.
 *    - Set the child's previous pointer to the current node.
 *    - Set the current node's child pointer to nullptr.
 * 5. Find the last node of the child list.
 * 6. Connect the last child node to the saved next node.
 * 7. Update the saved next node's previous pointer, if it exists.
 * 8. Move to the next node and continue until the list ends.
 * 9. Return the original head.
 *
 * Complexity:
 * - Time:  O(n) — Each node is visited at most twice (once during splicing to find
 *                 the child tail, and once during the main forward traversal).
 * - Space: O(1) — In-place pointer manipulation using constant extra memory.
 *
 *
 * ============================================================
 * Approach 2: Recursive DFS Flattening
 * ============================================================
 *
 * Technique:
 * Depth-First Search (Recursion) + Doubly Linked List Rewiring
 *
 * Key Idea:
 * Whenever a node has a child list, first flatten that child list
 * using recursion. Then connect the flattened child list between
 * the current node and its original next node. Continue until
 * all child lists are flattened.
 *
 * Steps:
 * 1. Return nullptr if the original list is empty.
 * 2. Start traversing the list from the head.
 * 3. If the current node has no child, move to the next node.
 * 4. If the current node has a child:
 *    - Save its original next node.
 *    - Recursively flatten the child list.
 *    - Connect the flattened child list after the current node.
 *    - Set the current node's child pointer to nullptr.
 * 5. Find the last node of the flattened child list.
 * 6. Connect the last child node to the saved next node, if it exists.
 * 7. Update the saved next node's previous pointer, if it exists.
 * 8. Continue traversing the flattened list.
 * 9. Return the original head.
 *
 * Complexity:
* - Time:  O(n) — Each node is visited at most twice (once when finding the tail of
 *                 a flattened child list and once during the main traversal).
 * - Space: O(d) — Recursion call stack proportional to the maximum nesting depth d
 *                 (O(n) in the worst case of a purely vertical child chain).
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    // Approach 1: Iterative Pointer Splicing (O(1) Auxiliary Space)
    Node* flatten(Node* head) {
        if (!head) return nullptr;

        Node* curr = head;

        while (curr != nullptr) {
            if (curr->child != nullptr) {
                Node* nextNode = curr->next;
                Node* childHead = curr->child;

                // Connect current node to the child list
                curr->next = childHead;
                childHead->prev = curr;
                curr->child = nullptr;

                // Find the tail of the child list
                Node* tail = childHead;
                while (tail->next != nullptr) {
                    tail = tail->next;
                }

                // Connect the tail of the child list to the saved nextNode
                tail->next = nextNode;
                if (nextNode != nullptr) {
                    nextNode->prev = tail;
                }
            }

            curr = curr->next;
        }

        return head;
    }

    // Approach 2: Recursive DFS Flattening
    Node* flattenRecursive(Node* head) {
        if (!head) return nullptr;

        Node* curr = head;

        while (curr != nullptr) {
            if (curr->child != nullptr) {
                // Save the original next node
                Node* next = curr->next;

                // Recursively flatten the child list
                curr->next = flattenRecursive(curr->child);
                curr->next->prev = curr;
                curr->child = nullptr;

                // Find the tail of the flattened child list
                Node* tail = curr->next;

                while (tail->next != nullptr) {
                    tail = tail->next;
                }

                // Connect the child list to the original next node
                if (next != nullptr) {
                    tail->next = next;
                    next->prev = tail;
                }
            }

            curr = curr->next;
        }

        return head;
    }
};