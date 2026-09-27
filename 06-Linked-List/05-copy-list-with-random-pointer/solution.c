/**
 * LeetCode 138: Copy List with Random Pointer
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#include <stdlib.h>

struct Node {
    int val;
    struct Node *next;
    struct Node *random;
};

struct Node* copyRandomList(struct Node* head) {
    if (!head) return NULL;
    struct Node* curr = head;
    while (curr) {
        struct Node* clone = (struct Node*)malloc(sizeof(struct Node));
        clone->val = curr->val;
        clone->next = curr->next;
        clone->random = NULL;
        curr->next = clone;
        curr = clone->next;
    }
    curr = head;
    while (curr) {
        if (curr->random) {
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;
    }
    curr = head;
    struct Node* copyHead = head->next;
    while (curr) {
        struct Node* copy = curr->next;
        curr->next = copy->next;
        if (copy->next) copy->next = copy->next->next;
        curr = curr->next;
    }
    return copyHead;
}
