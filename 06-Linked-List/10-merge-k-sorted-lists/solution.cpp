/**
 * LeetCode 23: Merge K Sorted Lists
 * Time Complexity: O(n log k)
 * Space Complexity: O(k)
 */
#include <vector>
#include <queue>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        std::priority_queue<ListNode*, std::vector<ListNode*>, Compare> pq;
        for (auto l : lists) if (l) pq.push(l);
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (!pq.empty()) {
            ListNode* top = pq.top();
            pq.pop();
            tail->next = top;
            tail = tail->next;
            if (top->next) pq.push(top->next);
        }
        return dummy.next;
    }
};
