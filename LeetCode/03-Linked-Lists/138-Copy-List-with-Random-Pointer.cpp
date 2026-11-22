/**
 * 138. Copy List with Random Pointer
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/copy-list-with-random-pointer/
 *
 * Problem:
 * Construct a deep copy of a linked list of length n where each node contains
 * an additional random pointer that can point to any node in the list or null.
 * Every node in the copied list must be newly allocated with matching values,
 * and both its next and random pointers must reference corresponding nodes
 * within the copied list rather than the original list.
 *
 *
 * Examples:
 *
 * Example 1:
 * Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
 * Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
 *
 * Example 2:
 * Input: head = [[1,1],[2,1]]
 * Output: [[1,1],[2,1]]
 *
 * Example 3:
 * Input: head = [[3,null],[3,0],[3,null]]
 * Output: [[3,null],[3,0],[3,null]]
 *
 *
 * Constraints:
 * - 0 <= n <= 1000
 * - -10^4 <= Node.val <= 10^4
 * - Node.random is null or points to a node in the linked list.
 *
 *
 * ============================================================
 * Approach 1: Node Interweaving (In-Place Three-Pass — Optimal Space)
 * ============================================================
 *
 * Technique:
 * In-Place Node Interweaving + Pointer Manipulation
 *
 * Key Idea:
 * First, create a copy of every node and place it right after its original
 * node. This helps us find the copied version of any node easily.
 * Then, connect the random pointers of the copied nodes and separate
 * the original list from the copied list.
 *
 * Steps:
 * 1. Return nullptr if the original list is empty.
 * 2. Traverse the list and create a copy of each node.
 * 3. Insert every copied node immediately after its original node.
 * 4. Traverse the list again and connect the random pointers of copied nodes.
 *    If an original node points randomly to another node, its copy should
 *    point to that other node's copy.
 * 5. Separate the original and copied nodes into two different lists.
 * 6. Return the head of the copied list.
 *
 * Complexity:
 * - Time:  O(n) — Three linear passes over the list of n nodes.
 * - Space: O(1) — Constant auxiliary space (excluding the n cloned output nodes).
 *
 *
 * ============================================================
 * Approach 2: Hash Map (Two-Pass Original-to-Clone Mapping)
 * ============================================================
 *
 * Technique:
 * Hash Map (Node Pointer Mapping) + Two-Pass Traversal
 *
 * Key Idea:
 * Use a hash map to remember which copied node belongs to each original node.
 * First, create all copied nodes and store them in the map.
 * Then, use the map to connect their next and random pointers.
 *
 * Steps:
 * 1. Return nullptr if the original list is empty.
 * 2. Create a hash map to store original nodes and their corresponding copies.
 * 3. Traverse the original list and create a new node for each original node.
 * 4. Store each original node and its copy in the hash map.
 * 5. Traverse the original list again.
 * 6. Connect each copied node's next pointer using the hash map.
 * 7. Connect each copied node's random pointer using the hash map.
 * 8. Return the copied head.
 *
 * Complexity:
 * - Time:  O(n) — Two linear passes with average O(1) map lookups.
 * - Space: O(n) — Hash map storing n original-to-cloned node pointer pairs.
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    // Approach 1: Optimal Space — Node Interweaving (O(1) Auxiliary Space)
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        Node* curr = head;

        // Pass 1: Create copied nodes and insert them right after original nodes
        while (curr != nullptr) {
            Node* copy = new Node(curr->val);

            copy->next = curr->next;
            curr->next = copy;

            curr = copy->next;
        }

        // Pass 2: Assign random pointers to the copied nodes
        curr = head;

        while (curr != nullptr) {
            if (curr->random != nullptr) {
                curr->next->random = curr->random->next;
            }

            curr = curr->next->next;
        }

        // Pass 3: Separate the original list and the copied list
        curr = head;
        Node* copyHead = head->next;

        while (curr != nullptr) {
            Node* copy = curr->next;

            curr->next = copy->next;

            if (copy->next != nullptr) {
                copy->next = copy->next->next;
            }

            curr = curr->next;
        }

        return copyHead;
    }



    // Approach 2: Hash Map — Original-to-Clone Mapping (O(n) Auxiliary Space)
    Node* copyRandomListHashMap(Node* head) {
        if (!head) return nullptr;

        unordered_map<Node*, Node*> mp;

        Node* curr = head;

        // Pass 1: Create a copy of every node and store in the map
        while (curr) {
            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }

        // Pass 2: Connect next and random pointers for the copied nodes
        curr = head;

        while (curr) {
            mp[curr]->next = mp[curr->next];
            mp[curr]->random = mp[curr->random];
            curr = curr->next;
        }

        return mp[head];
    }
};