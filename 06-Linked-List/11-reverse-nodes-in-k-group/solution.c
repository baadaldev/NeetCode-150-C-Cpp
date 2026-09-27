/**
 * LeetCode 25: Reverse Nodes in k-Group
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#include <stddef.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode* curr = head;
    for (int i = 0; i < k; i++) {
        if (!curr) return head;
        curr = curr->next;
    }
    struct ListNode *prev = NULL, *nextT = NULL, *p = head;
    for (int i = 0; i < k; i++) {
        nextT = p->next;
        p->next = prev;
        prev = p;
        p = nextT;
    }
    head->next = reverseKGroup(p, k);
    return prev;
}
