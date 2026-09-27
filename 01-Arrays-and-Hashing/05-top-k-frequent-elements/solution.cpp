/**
 * LeetCode 347: Top K Frequent Elements
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> count;
        for (int n : nums) count[n]++;

        std::vector<std::vector<int>> buckets(nums.size() + 1);
        for (const auto& [val, freq] : count) {
            buckets[freq].push_back(val);
        }

        std::vector<int> result;
        for (int i = buckets.size() - 1; i >= 0 && (int)result.size() < k; --i) {
            for (int n : buckets[i]) {
                result.push_back(n);
                if ((int)result.size() == k) break;
            }
        }
        return result;
    }
};
