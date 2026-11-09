/**
 * 160. Intersection of Two Linked Lists
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/intersection-of-two-linked-lists/
 *
 * Problem:
 * Given the heads of two singly linked-lists headA and headB, return the node
 * at which the two lists intersect. If the two linked lists have no intersection
 * at all, return null.
 *
 * The test cases are generated such that there are no cycles anywhere in
 * the entire linked structure.
 *
 * Note that the linked lists must retain their original structure after
 * the function returns.
 *
 *
 * Examples:
 *
 * Example 1:
 * Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
 * Output: Intersected at '8'
 * Explanation: The intersected node's value is 8. There are 2 nodes before the
 * intersected node in A; There are 3 nodes before the intersected node in B.
 *
 * Example 2:
 * Input: intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
 * Output: Intersected at '2'
 * Explanation: The intersected node's value is 2.
 *
 * Example 3:
 * Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
 * Output: No intersection
 * Explanation: The two lists do not intersect, so return null.
 *
 *
 * Constraints:
 * - The number of nodes in listA is m.
 * - The number of nodes in listB is n.
 * - 1 <= m, n <= 3 * 10^4
 * - 1 <= Node.val <= 10^5
 * - 0 <= skipA <= m
 * - 0 <= skipB <= n
 * - intersectVal is 0 if listA and listB do not intersect.
 * - intersectVal == listA[skipA] == listB[skipB] if listA and listB intersect.
 *
 * Follow-up:
 * Could you write a solution that runs in O(m + n) time and use only O(1) memory?
 *
 *
 * ============================================================
 * Approach: Two Pointers (Path Length Equalization)
 * ============================================================
 *
 * Technique:
 * Two Pointers — Simultaneous Traversal
 *
 * Key Idea:
 * Start one pointer at each list.
 * When a pointer reaches the end of its list, move it to the head of the other list.
 * Both pointers will travel the same total distance.
 * If the lists intersect, they will meet at the shared node.
 * Otherwise, both will reach nullptr.
 *
 * Steps:
 * 1. Start ptrA at headA and ptrB at headB.
 * 2. Move both pointers one node forward at a time.
 * 3. When ptrA reaches the end, redirect it to headB.
 * 4. When ptrB reaches the end, redirect it to headA.
 * 5. Continue until both pointers meet.
 * 6. Return the meeting node (intersection node or nullptr).
 *
 * Complexity:
 * - Time:  O(m + n) — Each pointer traverses at most m + n steps.
 * - Space: O(1) — Constant extra space using only two pointer variables.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) {
            return nullptr;
        }

        ListNode *ptrA = headA;
        ListNode *ptrB = headB;

        while (ptrA != ptrB) {
            ptrA = (ptrA == nullptr) ? headB : ptrA->next;
            ptrB = (ptrB == nullptr) ? headA : ptrB->next;
        }

        return ptrA;
    }
};