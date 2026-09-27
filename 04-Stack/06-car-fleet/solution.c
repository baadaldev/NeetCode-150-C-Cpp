/**
 * LeetCode 853: Car Fleet
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 */
#include <stdlib.h>

typedef struct {
    int pos;
    int speed;
} Car;

static int cmp(const void* a, const void* b) {
    return ((Car*)b)->pos - ((Car*)a)->pos;
}

int carFleet(int target, int* position, int positionSize, int* speed, int speedSize) {
    if (positionSize == 0) return 0;
    Car* cars = (Car*)malloc(positionSize * sizeof(Car));
    for (int i = 0; i < positionSize; i++) {
        cars[i].pos = position[i];
        cars[i].speed = speed[i];
    }
    qsort(cars, positionSize, sizeof(Car), cmp);

    int fleets = 0;
    double maxTime = 0.0;
    for (int i = 0; i < positionSize; i++) {
        double time = (double)(target - cars[i].pos) / cars[i].speed;
        if (time > maxTime) {
            maxTime = time;
            fleets++;
        }
    }
    free(cars);
    return fleets;
}
