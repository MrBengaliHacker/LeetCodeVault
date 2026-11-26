/**
 * 146. LRU Cache
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/lru-cache/
 *
 * Problem:
 * Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
 *
 * Implement the LRUCache class:
 * - LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
 * - int get(int key) Return the value of the key if the key exists, otherwise return -1.
 * - void put(int key, int value) Update the value of the key if the key exists. Otherwise,
 *   add the key-value pair to the cache. If the number of keys exceeds the capacity from
 *   this operation, evict the least recently used key.
 *
 * The functions get and put must each run in O(1) average time complexity.
 *
 *
 * Examples:
 *
 * Example 1:
 * Input:
 * ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
 * [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
 * Output:
 * [null, null, null, 1, null, -1, null, -1, 3, 4]
 *
 * Explanation:
 * LRUCache lRUCache = new LRUCache(2);
 * lRUCache.put(1, 1); // cache is {1=1}
 * lRUCache.put(2, 2); // cache is {1=1, 2=2}
 * lRUCache.get(1);    // return 1
 * lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
 * lRUCache.get(2);    // returns -1 (not found)
 * lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
 * lRUCache.get(1);    // return -1 (not found)
 * lRUCache.get(3);    // return 3
 * lRUCache.get(4);    // return 4
 *
 *
 * Constraints:
 * - 1 <= capacity <= 3000
 * - 0 <= key <= 10^4
 * - 0 <= value <= 10^5
 * - At most 2 * 10^5 calls will be made to get and put.
 *
 *
 * ============================================================
 * Approach: Hash Map + Doubly Linked List
 * ============================================================
 *
 * Technique:
 * Hash Map + Doubly Linked List + List Splicing
 *
 * Key Idea:
 * Use a hash map to find any cache entry quickly and a doubly linked
 * list to maintain the order in which entries are used. Keep the
 * most recently used entry at the front and the least recently used
 * entry at the back. Move an entry to the front whenever it is used.
 * When the cache is full, remove the entry at the back.
 *
 * Steps:
 * 1. Initialize a doubly linked list and a hash map.
 * 2. Store each key-value pair in the doubly linked list.
 * 3. Store each key and its list iterator in the hash map.
 * 4. For get:
 *    - Return -1 if the key does not exist.
 *    - Get the value and move its node to the front.
 *    - Return the value.
 * 5. For put:
 *    - If the key exists, update its value and move it to the front.
 *    - Otherwise, insert the new key-value pair at the front.
 *    - Store its iterator in the hash map.
 *    - If capacity is exceeded, remove the last node from the list
 *      and remove its key from the hash map.
 *
 * Complexity:
 * - Time: O(1) average for both get and put.
 * - Space: O(capacity) - Stores up to capacity key-value pairs.
 */

class LRUCache {
private:
    int capacity;

    // Doubly Linked List: {key, value}
    list<pair<int, int>> cache;

    // Hash Map: key -> iterator of the list node
    unordered_map<int, list<pair<int, int>>::iterator> mp;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        // Key does not exist
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        // Move recently used node to the front
        auto it = mp[key];
        int value = it->second;

        cache.splice(cache.begin(), cache, it);

        return value;
    }

    void put(int key, int value) {
        // Key already exists
        if (mp.find(key) != mp.end()) {
            auto it = mp[key];

            // Update value
            it->second = value;

            // Move node to the front
            cache.splice(cache.begin(), cache, it);
        } else {
            // Insert new node at the front
            cache.push_front({key, value});

            // Store its iterator
            mp[key] = cache.begin();

            // Check capacity
            if (cache.size() > capacity) {
                // Get least recently used key
                int lruKey = cache.back().first;

                // Remove from Hash Map
                mp.erase(lruKey);

                // Remove from Doubly Linked List
                cache.pop_back();
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */