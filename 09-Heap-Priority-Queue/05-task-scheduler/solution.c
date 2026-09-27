/**
 * LeetCode 621: Task Scheduler
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int leastInterval(char* tasks, int tasksSize, int n) {
    int freq[26] = {0};
    for (int i = 0; i < tasksSize; i++) freq[tasks[i] - 'A']++;
    int maxF = 0;
    for (int i = 0; i < 26; i++) if (freq[i] > maxF) maxF = freq[i];
    int maxCount = 0;
    for (int i = 0; i < 26; i++) if (freq[i] == maxF) maxCount++;
    int ans = (maxF - 1) * (n + 1) + maxCount;
    return MAX(ans, tasksSize);
}
