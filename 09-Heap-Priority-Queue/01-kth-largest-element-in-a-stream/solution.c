/**
 * LeetCode 703: Kth Largest Element in a Stream
 * Time Complexity: O(log k) per add
 * Space Complexity: O(k)
 */
#include <stdlib.h>

typedef struct {
    int* heap;
    int size;
    int k;
} KthLargest;

static void swap(int* a, int* b) { int t = *a; *a = *b; *b = t; }

static void heapifyUp(KthLargest* obj, int i) {
    while (i > 0 && obj->heap[i] < obj->heap[(i - 1) / 2]) {
        swap(&obj->heap[i], &obj->heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

static void heapifyDown(KthLargest* obj, int i) {
    int smallest = i;
    int l = 2 * i + 1, r = 2 * i + 2;
    if (l < obj->size && obj->heap[l] < obj->heap[smallest]) smallest = l;
    if (r < obj->size && obj->heap[r] < obj->heap[smallest]) smallest = r;
    if (smallest != i) {
        swap(&obj->heap[i], &obj->heap[smallest]);
        heapifyDown(obj, smallest);
    }
}

KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest* obj = (KthLargest*)malloc(sizeof(KthLargest));
    obj->heap = (int*)malloc((k + 1) * sizeof(int));
    obj->size = 0;
    obj->k = k;
    for (int i = 0; i < numsSize; i++) {
        if (obj->size < k) {
            obj->heap[obj->size++] = nums[i];
            heapifyUp(obj, obj->size - 1);
        } else if (nums[i] > obj->heap[0]) {
            obj->heap[0] = nums[i];
            heapifyDown(obj, 0);
        }
    }
    return obj;
}

int kthLargestAdd(KthLargest* obj, int val) {
    if (obj->size < obj->k) {
        obj->heap[obj->size++] = val;
        heapifyUp(obj, obj->size - 1);
    } else if (val > obj->heap[0]) {
        obj->heap[0] = val;
        heapifyDown(obj, 0);
    }
    return obj->heap[0];
}
