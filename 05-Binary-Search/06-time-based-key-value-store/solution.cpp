/**
 * LeetCode 981: Time Based Key-Value Store
 * Time Complexity: set O(1), get O(log n)
 * Space Complexity: O(n)
 */
#include <string>
#include <vector>
#include <unordered_map>

class TimeMap {
    std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> store;
public:
    TimeMap() {}
    
    void set(std::string key, std::string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    std::string get(std::string key, int timestamp) {
        if (store.find(key) == store.end()) return "";
        const auto& list = store[key];
        int l = 0, r = (int)list.size() - 1;
        std::string res = "";
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (list[mid].first <= timestamp) {
                res = list[mid].second;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return res;
    }
};
