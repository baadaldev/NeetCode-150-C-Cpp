/**
 * LeetCode 25: Reverse Nodes in k-Group
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        for (int i = 0; i < k; ++i) {
            if (!curr) return head;
            curr = curr->next;
        }
        ListNode *prev = nullptr, *nxt = nullptr, *p = head;
        for (int i = 0; i < k; ++i) {
            nxt = p->next;
            p->next = prev;
            prev = p;
            p = nxt;
        }
        head->next = reverseKGroup(p, k);
        return prev;
    }
};
