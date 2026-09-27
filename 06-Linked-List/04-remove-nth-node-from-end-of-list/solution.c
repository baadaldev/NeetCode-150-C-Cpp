/**
 * LeetCode 19: Remove Nth Node From End of List
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* fast = &dummy;
    struct ListNode* slow = &dummy;

    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }
    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }
    struct ListNode* toDelete = slow->next;
    slow->next = slow->next->next;
    return dummy.next;
}
