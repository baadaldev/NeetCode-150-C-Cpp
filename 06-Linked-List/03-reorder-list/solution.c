/**
 * LeetCode 143: Reorder List
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#include <stddef.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void reorderList(struct ListNode* head) {
    if (!head || !head->next) return;
    struct ListNode *slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode *prev = NULL, *curr = slow->next;
    slow->next = NULL;
    while (curr) {
        struct ListNode* nextT = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextT;
    }
    struct ListNode *first = head, *second = prev;
    while (second) {
        struct ListNode *t1 = first->next, *t2 = second->next;
        first->next = second;
        second->next = t1;
        first = t1;
        second = t2;
    }
}
