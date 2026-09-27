/**
 * LeetCode 146: LRU Cache
 * Time Complexity: O(1)
 * Space Complexity: O(capacity)
 */
#include <unordered_map>
#include <list>

class LRUCache {
    int cap;
    std::list<std::pair<int, int>> dll;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cache;
public:
    LRUCache(int capacity) : cap(capacity) {}
    
    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        dll.splice(dll.begin(), dll, cache[key]);
        return cache[key]->second;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            dll.splice(dll.begin(), dll, cache[key]);
            cache[key]->second = value;
            return;
        }
        if ((int)cache.size() == cap) {
            int dKey = dll.back().first;
            dll.pop_back();
            cache.erase(dKey);
        }
        dll.push_front({key, value});
        cache[key] = dll.begin();
    }
};
